#include "calibracao.h"
#define PORCENTAGEM 1
#define ALTURA 480
#define LARGURA 640

RNG rng(12345);
Mat src_gray, frameA, res,mask;
Calibracao at ;
std::vector<Rect> insideRect;
char* src_window = "Configuração da Imagem";
int brightness_value = 0, contrast_value = 50, dragA, select_flagA;
Rect tamanho;
bool callbackA = false,cameraIndisponivel=false;
Point point1, point2;
cv::VideoCapture camera;

/*
0 AMARELO
1 AZUL
2 VERDE
3 VERMELHO
*/
std::vector<SCIMM_COR> CORES;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor


double Calibracao::ObterPorcentagem(int valor, int porcentagem){
    double p = (porcentagem*valor)/100;
    return p;
}
static void mouseHandler(int event, int x, int y, int flags, void *param) {

    if (event == CV_EVENT_LBUTTONDOWN && !dragA && !select_flagA) {

        point1 = cv::Point(x, y);
        dragA = 1;
    }

    if (event == CV_EVENT_MOUSEMOVE && dragA && !select_flagA) {

        point2 = cv::Point(x, y);
        rectangle(frameA, point1, point2, CV_RGB(255, 0, 0), 2, 5, 0);
        imshow(src_window, frameA);
    }

    if (event == CV_EVENT_LBUTTONUP && dragA && !select_flagA) {
        point2 = cv::Point(x, y);
        rectangle(frameA, point1, point2, CV_RGB(255, 0, 0), 2, 5, 0);
        dragA = 0;
        callbackA = true;
        imshow(src_window, frameA);
        // std::cout << point1 << " "<< point2 << std::endl;
        if (point1.y > point2.y || point1.x > point2.x) {
            printf("Horientação errada para detecção de cor.");

        }
    }
}
Calibracao::Calibracao()
{
}
void Calibracao::Iniciar(JanelaPrincipal *janela, int c){
    CAMERA =c ;
    JANELA = janela;

    camera.open(CAMERA);
    camera.set(CAP_PROP_AUTOFOCUS, FOCO);
    if( !camera.isOpened() )
    { cameraIndisponivel = true;
        janela->CameraIndisponivel();
    }
}


void Calibracao::ConfigurarCamera(){

    camera.open(CAMERA);

    if( !camera.isOpened() )
    { cameraIndisponivel = true;
        JANELA->CameraIndisponivel();
    } else {

        while(true){
            createTrackbar("Brilho", src_window, &brightness_value, 200);
            createTrackbar("Contraste", src_window, &contrast_value, 100);
            camera >> frameA;
            frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-200);
            cv::resize(frameA, frameA, cvSize(LARGURA, ALTURA));


            cv::setMouseCallback(src_window,mouseHandler,0);
            cv::rectangle(frameA, point1, point2, CV_RGB(255, 0, 0), 2, 5, 0);
            cv::imshow(src_window,frameA);
            JANELA->SetImage(frameA);

            cv::imshow(src_window,frameA);
            if (cv::waitKey(30) >= 0) break;
        }

        cvDestroyAllWindows();
        tamanho = Rect( point1.x, point1.y,( point2.x- point1.x) ,( point2.y- point1.y));
        //        std::cout << tamanho << std::endl;
        //        cv::Mat croppedImage;
        //        while(true){
        //            camera >> frameA;
        //            //   frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-100 );
        //            croppedImage = frameA(tamanho);
        //            cv::imshow(src_window,croppedImage);
        //            if (cv::waitKey(30) >= 0) break;
        //        }

        cvDestroyAllWindows();
        cvDestroyAllWindows();
    }

}
void Calibracao::ReconhecerFundoExtrairObjetos(){

    pMOG2= createBackgroundSubtractorMOG2(); //MOG2 approach
    for (int var = 0; var < 101; ++var) {
        JANELA->SetStatusFundo(var);
        camera >> frame;


        frame.convertTo(frame, -1, contrast_value / 50.0, brightness_value-200);
        cv::resize(frame, frame, cvSize(LARGURA, ALTURA));
        JANELA->SetImage(frame);
        pMOG2->apply(frame, mask);

    }
    Mat Atual;

    QMessageBox::StandardButton reply =  JANELA->SCIMM_ALERT();

    if(reply == QMessageBox::StandardButton::Ok) {



        for(int var = 0; var <= 10; var++){
            camera >> Atual;
            Atual.convertTo(Atual, -1, contrast_value / 50.0, brightness_value-200);

            pMOG2->apply(Atual, mask);
        }
        Mat aux;
        while(true) {
            camera >> Atual;
            Atual.convertTo(Atual, -1, contrast_value / 50.0, brightness_value-200);
            imshow("Mask", mask);
            //            JANELA->SetImage(mask);
            if (cv::waitKey(30)>= 0) break;
            bitwise_and(Atual, Atual, aux, mask);
            JANELA->SetImage(aux);

        }


    }
    pMOG2.release();
    cvDestroyAllWindows();


}
void Calibracao::DetectarObjetos(int, void *){
    Mat canny_output;
    std::vector< std::vector<Point> > contours;
    std::vector<Vec4i> hierarchy;

    cvtColor(res, src_gray, CV_BGR2GRAY);
    blur(src_gray, src_gray, Size(3, 3));
    Canny(src_gray, canny_output, thresh, thresh * 3, 3);
    findContours(canny_output, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    std:: vector< std::vector<Point> > contours_poly(contours.size());


    boundRect.clear();
    insideRect.clear();
    for (unsigned int i = 0; i < contours.size(); i++) {
        approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
        boundRect.push_back(boundingRect(Mat(contours_poly[i])));

    }

    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);

    Rect n;
    Point pTopRight, pBottomLeft;
    for (unsigned int i = 0; i < contours.size(); i++) {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
        n = boundRect.at(i);
        pTopRight = n.tl();
        pBottomLeft = n.br();
        pTopRight.x += ObterPorcentagem(pTopRight.x, PORCENTAGEM);
        pTopRight.y += ObterPorcentagem(pTopRight.y, PORCENTAGEM);
        pBottomLeft.x -= ObterPorcentagem(pBottomLeft.x, PORCENTAGEM);
        pBottomLeft.y -= ObterPorcentagem(pBottomLeft.y,PORCENTAGEM);
        Rect rRect(pTopRight, pBottomLeft);
        if(rRect.area()>1){
            insideRect.push_back(rRect);
            rectangle(drawing, rRect, Scalar(0, 0, 255), 1, 8, 0);
        }
    }

}
void Calibracao::Calibrar(){
    Mat cali;
    FIM=false;
    cv::Mat croppedImage;


    Mat aux;
    mask = mask(tamanho);
    for(int i = 0; i < 20; i++){
        camera >> cali;

        cali = cali(tamanho);
        cali.copyTo(aux);
        cali.convertTo(cali, -1, contrast_value / 50.0, brightness_value-200);

        bitwise_and(cali, cali, res, mask);

    }
    //   cv::resize(frame, frame, cvSize(LARGURA, ALTURA));


    bitwise_and(aux, aux, res, mask);
    cvDestroyAllWindows();

    JANELA->SetStatus(25);


    DetectarObjetos(0, 0);
    sleep(1);

    JANELA->SetStatus(50);

    Calcular();
    JANELA->SetStatus(75);


    JANELA->SetStatus(100);
}

void Calibracao::Calcular(){
    SCIMM_COR c1,c2,c3,c4,c5,c6,c7;
    CORES.push_back(c1);
    CORES.push_back(c2);
    CORES.push_back(c3);
    CORES.push_back(c4);
    CORES.push_back(c5);
    CORES.push_back(c6);
    CORES.push_back(c7);
    Mat thisFrame;
    camera >> thisFrame;
    cv::cvtColor(thisFrame, HSV, CV_BGR2HSV );
    cv::Vec3b pixel;
    for (unsigned int i = 0; i < insideRect.size(); i++) {
        //   std::cout << "Objeto: " <<i <<std::endl;
        for (int y = insideRect.at(i).tl().y; y < insideRect.at(i).br().y; y++) {
            for (int x = insideRect.at(i).tl().x; x < insideRect.at(i).br().x; x++) {
                pixel = HSV.at<cv::Vec3b>(y, x);

                if(pixel.val[1]>99 && pixel.val[2]>99){
                    //pixel.val[1] = pixel.val[1] < 50 ? 50 : pixel.val[1];
                    //                    pixel.val[2] = pixel.val[2] < 50 ? 50 : pixel.val[2];
                    if(pixel.val[0]<=20) {
                        //LARANJA
                        CORES[LARANJA].SetMinMax2(pixel);
                    } else  if(pixel.val[0]>20 &&pixel.val[0]<=30) {
                        //AMARELO
                        //std::cout <<"AMARELO: " << ((int)pixel.val[0]) << "."<< ((int)pixel.val[1]) << "."<< ((int)pixel.val[2]) <<std::endl;
                        CORES[AMARELO].SetMinMax2(pixel);
                    } else  if(pixel.val[0]>60 &&pixel.val[0]<=90) {
                        //VERDE
                        pixel.val[1] = pixel.val[1] < 100 ? 100 : pixel.val[1];
                        pixel.val[2] = pixel.val[2] < 30 ? 30 : pixel.val[2];
                        CORES[VERDE].SetMinMax2(pixel);
                    }else  if(pixel.val[0]>90 &&pixel.val[0]<=120) {
                        //AZUL
                        //    std::cout <<"AZUL: " << ((int)pixel.val[0]) << "."<< ((int)pixel.val[1]) << "."<< ((int)pixel.val[2]) <<std::endl;
                        pixel.val[1] = pixel.val[1] < 100 ? 100 : pixel.val[1];
                        pixel.val[2] = pixel.val[2] < 100 ? 100 : pixel.val[2];
                        CORES[AZUL].SetMinMax2(pixel);
                    }else  if(pixel.val[0]>120 &&pixel.val[0]<=160) {
                        //ROXO
                        CORES[ROXO].SetMinMax3(pixel);
                    }else  if(pixel.val[0]>160 &&pixel.val[0]<=168) {
                        //ROSA
                        CORES[ROSA].SetMinMax2(pixel);
                    }else  if(pixel.val[0]>168 &&pixel.val[0]<=180) {
                        //VERMELHO
                        CORES[VERMELHO].SetMinMax2(pixel);
                    }
                }
            }
        }


    }

    //    std::cout <<"-----------------" <<std::endl;


}
void Calibracao::Exibir(){
    Mat Threshold;

    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
    }

    while(!JANELA->FINALIZADA){
        Mat final;
        camera >> frame;

        dilate(frame, frame, Mat(), Point(-1, -1), 2, 1, 1);
        cv::cvtColor(frame,HSV,cv::COLOR_BGR2HSV);
        cv::inRange(
                    HSV,
                    cv::Scalar(CORES[JANELA->INDICE_OBJETO].S_H[0],
                CORES[JANELA->INDICE_OBJETO].S_S[0],
                CORES[JANELA->INDICE_OBJETO].S_V[0]),
                cv::Scalar( CORES[JANELA->INDICE_OBJETO].S_H[1] ,
                CORES[JANELA->INDICE_OBJETO].S_S[1] ,
                CORES[JANELA->INDICE_OBJETO].S_V[1] ),Threshold);
        bitwise_and(frame, frame, final, Threshold );
        final = final(tamanho);
        JANELA->SetImage( final);
        if (cv::waitKey(30)>= 0) break;

    }
    camera.release();
    SalvarArquivo();
}
void Calibracao::Fechar(){
    FIM =true;
    cv::destroyAllWindows();

}
void Calibracao::SalvarArquivo(){
    std::ofstream out;
    //  std::cout << " salvando " << std::endl;
    out.open("cores.arff");
    for(int i = 0; i < CORES.size(); i++){
        out << i << " : " << CORES[i].S_H[0] << "." << CORES[i].S_S[0]<< "."<< CORES[i].S_V[0] << std::endl;
        out << i << " : " << CORES[i].S_H[1] << "." << CORES[i].S_S[1]<< "."<< CORES[i].S_V[1] << std::endl;
    }
    out.close();
}


void Calibracao::AutoFoco() {
    FOCO = FOCO == 0 ? 1 : 0;
    camera.set(CAP_PROP_AUTOFOCUS, FOCO);

}
