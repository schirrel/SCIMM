#include "automatica.h"
#define PORCENTAGEM 1
#include "scimm_cor.h"
#include "opencv2/opencv.hpp"
RNG rng(12345);
Mat frameA, src_gray;
Automatica at ;
std::vector<Rect> insideRect;
char* src_window = "Configuração da Imagem";
int brightness_value = 0, contrast_value = 50;
Rect tamanho;
std::vector<CorCalibrada> cores;
int dragA, select_flagA;
bool callbackA = false;
Point point1, point2;
bool cameraIndisponivel=false;
Mat BackImg;
/*
0 AMARELO
1 AZUL
2 VERDE
3 VERMELHO
*/
std::vector<SCIMM_COR> CORES;
Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
Mat fgMaskMOG2;

double Automatica::ObterPorcentagem(int valor, int porcentagem){
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
Automatica::Automatica()
{
}
void Automatica::ConfigurarCamera(JanelaPrincipal* janela){

    cv::VideoCapture cap;
    cap.open(CAMERA);

    if( !cap.isOpened() )
    { cameraIndisponivel = true;
        janela->CameraIndisponivel();
    } else {

        while(true){
            createTrackbar("Brilho", src_window, &brightness_value, 200);
            createTrackbar("Contraste", src_window, &contrast_value, 100);
            cap >> frameA;
            frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-100);


            cv::setMouseCallback(src_window,mouseHandler,0);
            cv::rectangle(frameA, point1, point2, CV_RGB(255, 0, 0), 2, 5, 0);
            cv::imshow(src_window,frameA);
            cvtColor(frameA, src_gray, CV_BGR2GRAY);
            blur(src_gray, src_gray, Size(5, 5));
            AplicarThresh(0, 0);

            cv::imshow(src_window,frameA);
            if (cv::waitKey(30) >= 0) break;
        }

        cvDestroyAllWindows();
        tamanho = Rect( point1.x, point1.y,( point2.x- point1.x) ,( point2.y- point1.y));
        std::cout << tamanho << std::endl;
        cv::Mat croppedImage;
        while(true){
            cap >> frameA;
            frameA.convertTo(frameA, -1, contrast_value / 50.0, brightness_value-100 );
            croppedImage = frameA(tamanho);
            cv::imshow(src_window,croppedImage);
            if (cv::waitKey(30) >= 0) break;
        }
        cvDestroyAllWindows();
        cap.release();
        cvDestroyAllWindows();
    }
}

void Automatica::ReconhecerFundo(JanelaPrincipal* janela){

    //create the capture object
    VideoCapture capture(CAMERA);
    if(!capture.isOpened()){

    }
    pMOG2= createBackgroundSubtractorMOG2(); //MOG2 approach
    //read input data. ESC or 'q' for quitting
    for (int var = 0; var < 101; ++var) {
            janela->SetStatusFundo(var);
        //read the current frame
        if(capture.read(frame)) {
            //update the background model
            pMOG2->apply(frame, fgMaskMOG2);
            //get the frame number and write it on the current frame
            rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
                      cv::Scalar(255,255,255), -1);
            imshow("Frame", frame);
            imshow("FG Mask MOG 2", fgMaskMOG2);
        }
    }

    cvDestroyAllWindows();
    capture.release();
}

void Automatica::ExtrairObjetos(JanelaPrincipal *janela){
    //create the capture object
    VideoCapture capture(CAMERA);
    if(!capture.isOpened()){

    }
    Mat res;
    for (int var = 0; var < 10; ++var) {
        if(capture.read(frame)) {  //update the background model
            pMOG2->apply(frame, fgMaskMOG2);
            rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
                      cv::Scalar(255,255,255), -1);
        }
    }

    while(true) {
        if(capture.read(frame)) {
            imshow("FG Mask MOG 2", fgMaskMOG2);
            bitwise_and(frame, frame, res, fgMaskMOG2);
            imshow("Final", res);
        }
        if( waitKey(30)> 0)
            break;
    }

    //delete capture object
    capture.release();
}

void Automatica::Calibrar(JanelaPrincipal *janela){
    FIM=false;
    cv::Mat croppedImage;
    cv::VideoCapture camera(CAMERA);
    if (!camera.isOpened()) {
        std::cerr << "ERROR: Could not open camera" << std::endl;
    }
    int cont=0;

    while (!janela->INICIAR) {
        camera >> frame;
        frame = frame(tamanho);
        frame.convertTo(frame, -1, contrast_value / 50.0, brightness_value-100 );

        cvtColor(frame, src_gray, CV_BGR2GRAY);
        blur(src_gray, src_gray, Size(5, 5));
        AplicarThresh(0, 0);
        if (cv::waitKey(30) >= 0 || FIM) break;

    }

    if(!FIM){
        janela->SetStatus(25, "Detectando Objetos");

        cvtColor(frame, src_gray, CV_BGR2GRAY);
        blur(src_gray, src_gray, Size(3, 3));
        AplicarThresh(0, 0);
        sleep(1);
        //insideRect = EliminarExcessos();
        janela->SetStatus(50, "Eliminando Objetos Indesejados");
        sleep(1);
        Calcular();
        janela->SetStatus(75, "Calculando Valores HSV");
        sleep(1);
        janela->SetText(cores.size() );
        janela->SetStatus(100, "Exibindo Objetos com Threshold");
        sleep(1);


        Mat Threshold;
        Mat res;

        while(1){
            camera >> frame;
            dilate(frame, frame, Mat(), Point(-1, -1), 2, 1, 1);
            cv::cvtColor(frame,HSV,cv::COLOR_BGR2HSV);
            cv::inRange(
                        HSV,
                        cv::Scalar(CORES[janela->INDICE_OBJETO].S_H[0],
                    CORES[janela->INDICE_OBJETO].S_S[0],
                    CORES[janela->INDICE_OBJETO].S_V[0]),
                    cv::Scalar( CORES[janela->INDICE_OBJETO].S_H[1] ,
                    CORES[janela->INDICE_OBJETO].S_S[1] ,
                    CORES[janela->INDICE_OBJETO].S_V[1] ),Threshold);
            Mat res;
            bitwise_and(frame, frame, res, Threshold );
            // res = res(tamanho);
            cv::imshow("Limiar por Objeto", res);
            if(janela->FINALIZADA){
                break;
            }
            if (cv::waitKey(30) >= 0 || FIM) break;
        }
        SalvarArquivo();

    }
    camera.release();
    camera.release();
    camera.release();
    cvDestroyAllWindows();
    cvDestroyAllWindows();


}
void Calibracao::Calcular(){
    cv::cvtColor(frame, HSV, CV_BGR2HSV_FULL);
    cv::Vec3b pixel;
    int H[257], S[257], V[257];
    int MIN[3], MAX[0];
    int k;
    for (unsigned int i = 0; i < insideRect.size(); i++) {
        memset(H, 0, sizeof(H));
        memset(S, 0, sizeof(S));
        memset(V, 0, sizeof(V));
        memset(MIN, 0, sizeof(MIN));
        memset(MAX, 0, sizeof(MAX));

        for (int y = insideRect.at(i).tl().y; y < insideRect.at(i).br().y; y++) {
            for (int x = insideRect.at(i).tl().x; x < insideRect.at(i).br().x; x++) {
                pixel = HSV.at<cv::Vec3b>(y, x);


                if(pixel.val[1]>20 && pixel.val[2]>20) {
                    if(pixel.val[0]>0 &&pixel.val[0]<=22) {
                        //LARANJA
                        CORES[4].SetMinMax(pixel);
                    } else  if(pixel.val[0]>22 &&pixel.val[0]<=38) {
                        //AMARELO
                        CORES[0].SetMinMax(pixel);
                    } else  if(pixel.val[0]>38 &&pixel.val[0]<=75) {
                        //VERDE
                        CORES[2].SetMinMax(pixel);
                    }else  if(pixel.val[0]>75 &&pixel.val[0]<=130) {
                        //AZUL
                        CORES[1].SetMinMax(pixel);
                    }else  if(pixel.val[0]>130 &&pixel.val[0]<=160) {
                        //VIOLETA
                    }else  if(pixel.val[0]>160 &&pixel.val[0]<=179) {
                        //VERMELHO
                        CORES[3].SetMinMax(pixel);
                    }
                }


            }
        }

    }
}
void Automatica::Iniciar(JanelaPrincipal *janela, int c){
    CAMERA =c ;
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
    }

    //    if(!cameraIndisponivel){
    //        SCIMM_COR a, b, c1, d, e;
    //        CORES.push_back(a);
    //        CORES.push_back(b);
    //        CORES.push_back(c1);
    //        CORES.push_back(d);
    //        CORES.push_back(e);
    //        this->Calibrar(janela);
    //    }

}

void Automatica::AplicarThresh(int, void *){
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
    namedWindow("Contours", CV_WINDOW_AUTOSIZE);
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
    imshow("Contours", drawing);
}
