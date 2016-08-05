#include "automatica.h"
#define PORCENTAGEM 5
#include "scimm_cor.h"
#include "opencv2/opencv.hpp"
RNG rng(12345);
Mat frameA, src_gray;
Calibracao at ;
std::vector<Rect> insideRect;
char* src_window = "Configuração da Imagem";
int brightness_value = 0, contrast_value = 50;
Rect tamanho;

int dragA, select_flagA;
bool callbackA = false;
Point point1, point2;
bool cameraIndisponivel=false;
Mat res;
/*
0 AMARELO
1 AZUL
2 VERDE
3 VERMELHO
*/
std::vector<SCIMM_COR> CORES;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
Mat fgMaskMOG2;

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
        std::cout << point1 << " "<< point2 << std::endl;
        if (point1.y > point2.y || point1.x > point2.x) {
            printf("Horientação errada para detecção de cor.");

        }
    }
}
Calibracao::Calibracao()
{
}
void Calibracao::ConfigurarCamera(JanelaPrincipal* janela){

    cv::VideoCapture cap;
    cap.open(CAMERA);

    if( !cap.isOpened() )
    { cameraIndisponivel = true;
        janela->CameraIndisponivel();
    } else {

        while(true){
       //     createTrackbar("Brilho", src_window, &brightness_value, 200);
        //    createTrackbar("Contraste", src_window, &contrast_value, 100);
            cap >> frameA;
            // frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-100);


            cv::setMouseCallback(src_window,mouseHandler,0);
            cv::rectangle(frameA, point1, point2, CV_RGB(255, 0, 0), 2, 5, 0);
            cv::imshow(src_window,frameA);
            janela->SetImage(frameA);

            cv::imshow(src_window,frameA);
            if (cv::waitKey(30) >= 0) break;
        }

        cvDestroyAllWindows();
        tamanho = Rect( point1.x, point1.y,( point2.x- point1.x) ,( point2.y- point1.y));
//        std::cout << tamanho << std::endl;
//        cv::Mat croppedImage;
//        while(true){
//            cap >> frameA;
//            //   frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-100 );
//            croppedImage = frameA(tamanho);
//            cv::imshow(src_window,croppedImage);
//            if (cv::waitKey(30) >= 0) break;
//        }
        cvDestroyAllWindows();
        cap.release();
        cvDestroyAllWindows();
    }

}
void Calibracao::ReconhecerFundo(JanelaPrincipal* janela){

    //create the capture object
    VideoCapture capture(CAMERA);
    if(!capture.isOpened()){

    }
    capture >> frame;
    pMOG2= createBackgroundSubtractorMOG2(); //MOG2 approach
    //read input data. ESC or 'q' for quitting
    for (int var = 0; var < 101; ++var) {
        janela->SetStatusFundo(var);
        if(capture.read(frame)) {
            // frame.convertTo(frame, -1, contrast_value / 50.0, brightness_value-100);
            //   frame = frame(tamanho);
            janela->SetImage(frame);
            pMOG2->apply(frame, fgMaskMOG2);
        }
    }
//    while(true) {

//        imshow("Fnndo", frame);
//        if (cv::waitKey(30)>= 0) break;



//    }

    cvDestroyAllWindows();
    capture.release();
}
void Calibracao::ExtrairObjetos(JanelaPrincipal *janela){
    //create the capture object
    VideoCapture capture(CAMERA);
    if(!capture.isOpened()){

    }

    for (int var = 0; var < 11; ++var) {
        if(capture.read(frame)) {  //update the background model
            janela->SetStatusExtrair(var*10);
            pMOG2->apply(frame, fgMaskMOG2);
            janela->SetImage(fgMaskMOG2);

        }
    }

    for (int var = 0; var < 11; ++var) {
        capture >> frame;
        bitwise_and(frame, frame, res, fgMaskMOG2);
        res=res(tamanho);
        imshow("Final", res);
        janela->SetImage(res);
    }
    cvDestroyAllWindows();
    cvDestroyAllWindows();
    //delete capture object
    capture.release();
}
void Calibracao::Iniciar(JanelaPrincipal *janela, int c){
    CAMERA =c ;
    JANELA = janela;
    //this->ConfigurarCamera(janela);
    cv::VideoCapture cap;
    cap.open(CAMERA);

    if( !cap.isOpened() )
    { cameraIndisponivel = true;
        janela->CameraIndisponivel();
    } else {
        cap.release();
        cap.release();
        cap.release();
        brightness_value = 40 ;
        contrast_value = 40 ;
     //   tamanho = Rect( 166, 92,( 494- 166) ,( 389- 92));
    }
}
void Calibracao::DetectarObjetos(int, void *){
    Mat canny_output;
    std::vector< std::vector<Point> > contours;
    std::vector<Vec4i> hierarchy;


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
   // imshow("Contours", drawing);
}
void Calibracao::Calibrar(JanelaPrincipal *janela){

    FIM=false;
    cv::Mat croppedImage;
    cv::VideoCapture camera(CAMERA);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
    }

//Mat res;
  for(int i = 0; i < 20; i++){
       camera >> frame;
      //  frame = frame(tamanho);
         bitwise_and(frame, frame, res, fgMaskMOG2);
  }
        //frame.(frame, -1, contrast_value / 50.0, brightness_value-100 );
//
//        cvtColor(res, src_gray, CV_BGR2GRAY);
//        blur(src_gray, src_gray, Size(5, 5));
//        AplicarThresh(0, 0);
//        if (cv::waitKey(30) >= 0 || FIM) break;

//    }

    camera.release();
        cvDestroyAllWindows();
        cvDestroyAllWindows();
        janela->SetStatus(25);
        frame = frame(tamanho);
        cvtColor(frame, src_gray, CV_BGR2GRAY);
        blur(src_gray, src_gray, Size(3, 3));
        DetectarObjetos(0, 0);
        sleep(1);
        //insideRect = EliminarExcessos();
        janela->SetStatus(50);
        sleep(1);
        Calcular();
        janela->SetStatus(75);
        sleep(1);

        janela->SetStatus(100);
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
    cv::cvtColor(frame, HSV, CV_BGR2HSV );
    cv::Vec3b pixel;
    for (unsigned int i = 0; i < insideRect.size(); i++) {
        for (int y = insideRect.at(i).tl().y; y < insideRect.at(i).br().y; y++) {
            for (int x = insideRect.at(i).tl().x; x < insideRect.at(i).br().x; x++) {
                pixel = HSV.at<cv::Vec3b>(y, x);


                if(pixel.val[0]>0 &&pixel.val[0]<=20) {
                    //LARANJA
                    CORES[LARANJA].SetMinMax(pixel);
                } else  if(pixel.val[0]>20 &&pixel.val[0]<=30) {
                    //AMARELO
                    CORES[AMARELO].SetMinMax(pixel);
                } else  if(pixel.val[0]>60 &&pixel.val[0]<=90) {
                    //VERDE
                    CORES[VERDE].SetMinMax(pixel);
                }else  if(pixel.val[0]>90 &&pixel.val[0]<=120) {
                    //AZUL
                    pixel.val[1] = pixel.val[1] < 100 ? 100 : pixel.val[1];
                    pixel.val[2] = pixel.val[2] < 100 ? 100 : pixel.val[2];
                    CORES[AZUL].SetMinMax(pixel);
                }else  if(pixel.val[0]>120 &&pixel.val[0]<=160) {
                    //ROXO
                    CORES[ROXO].SetMinMax(pixel);
                }else  if(pixel.val[0]>160 &&pixel.val[0]<=168) {
                    //ROSA
                    CORES[ROSA].SetMinMax(pixel);
                }else  if(pixel.val[0]>168 &&pixel.val[0]<=180) {
                    //VERMELHO
                    CORES[VERMELHO].SetMinMax(pixel);
                }
            }
        }


    }
}
void Calibracao::Exibir(){
    Mat Threshold;
    cv::VideoCapture camera(CAMERA);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
    }

  Mat final;
    while(!JANELA->FINALIZADA){

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
    std::cout << " salvando " << std::endl;
    out.open("cores.arff");
//    for(int i = 0; i < 8; i++){
//        out << i << " : " << coresCalibradas[i].MIN[0] << "." << coresCalibradas[i].MIN[1]<< "."<< coresCalibradas[i].MIN[2] << std::endl;
//        out << i << " : " << coresCalibradas[i].MAX[0] << "." << coresCalibradas[i].MAX[1]<< "."<< coresCalibradas[i].MAX[2] << std::endl;
//    }
    out.close();
}
