#include "calibracaomanual.h"
#include "janelaprincipal.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
bool FIM=false;

char* janelasNome[2] = {"Selecão de Cores", "Threshold"};;
Mat frame;

int CALIBRANDO_ATUAL, select_flag, key;
int H[256], S[256], V[256];
bool CalibracaoFinalizada = false, callback;

CorCalibrada coresCalibradas[8];
cv::Mat hsvImagens[8], HSV, Threshold;
cv::Point ponto_inicio, ponto_fim;
cv::Vec3b pixel;
int drag;
CalibracaoManual::CalibracaoManual()
{

}
bool CalibracaoManual::CameraLiberada(){
    return FIM;
}
void CalcularHSV(cv::Point ini, cv::Point fim) {
    // std::cout << "Validando pontos de " << TEXTO << std::endl;
    cv::cvtColor(frame, HSV, CV_RGB2HSV);
    for (int y = ini.y; y < fim.y; ++y) {
        for (int x = ini.x; x < fim.x; x++) {
            pixel = HSV.at<cv::Vec3b>(y, x); // read current pixel
            H[pixel.val[0]]++;
            S[pixel.val[1]]++;
            V[pixel.val[2]]++;
        }
    }
}
static void mouseHandler(int event, int x, int y, int flags, void *param) {
    if (event == CV_EVENT_LBUTTONDOWN && !drag && !select_flag) {
         /* left button clicked. ROI selection begins */
         ponto_inicio = cv::Point(x, y);
         drag = 1;
     }
     if (event == CV_EVENT_MOUSEMOVE && drag && !select_flag) {
         /* mouse dragged. ROI being selected */
         cv::Mat img1 = frame.clone();
         ponto_fim = cv::Point(x, y);
         cv::rectangle(img1, ponto_inicio, ponto_fim, CV_RGB(255, 0, 0), 2, 5, 0);
         cv::imshow(janelasNome[0], img1);    }
     if (event == CV_EVENT_LBUTTONUP && drag && !select_flag) {
         cv::Mat img2 = frame.clone();
         ponto_fim = cv::Point(x, y);
         cv::rectangle(img2, ponto_inicio, ponto_fim, CV_RGB(255, 0, 0), 2, 5, 0);
         drag = 0;
         if (ponto_inicio.y > ponto_fim.y || ponto_inicio.x > ponto_fim.x) {
             std::cout << "Horientação errada para detecção de cor." << std::endl;
         } else {
            CalcularHSV(ponto_inicio, ponto_fim);
         }


     }
}

void CalibracaoManual::Iniciar(JanelaPrincipal*  janela, int CAMERA){
    int CALIBRANDO_ATUAL;
    Mat src;
    FIM  =false;
    cv::VideoCapture camera(CAMERA);
    if (camera.isOpened()) {
        CALIBRANDO_ATUAL = janela->INDEX_CALIBRACAO;
        while (!janela->FINALIZADA || !FIM) {
            camera >> frame;
            if(janela->CALIBRADO[CALIBRANDO_ATUAL]){
                coresCalibradas[CALIBRANDO_ATUAL] = janela->cor;
            }
            if(CALIBRANDO_ATUAL!=janela->INDEX_CALIBRACAO){
                DeclararMatrizes();
                CALIBRANDO_ATUAL = janela->INDEX_CALIBRACAO;
            }
            cv::setMouseCallback(janelasNome[0], mouseHandler, 0);
            cv::imshow(janelasNome[0], frame);
            if(janela->CALIBRAR){
                janela->SetHSV(H,S,V);
                janela->CALIBRAR = false;

            }
            key = cv::waitKey(5) & 255;
            if (FIM) {
                break;
            }
        }

       camera.release();
        camera.release();
        camera.release();

        cv::destroyAllWindows();
        cv::destroyAllWindows();
        cv::destroyAllWindows();
        cv::destroyAllWindows();

        if(janela->FINALIZADA)
            SalvarArquivo();
    }


}
void CalibracaoManual::Fechar(){

    FIM =true;
    cv::destroyAllWindows();
    cv::destroyAllWindows();
    cv::destroyAllWindows();
    cv::destroyAllWindows();


}
void CalibracaoManual::DeclararMatrizes(){
    memset(H, 0, sizeof(H));
    memset(S, 0, sizeof(S));
    memset(V, 0, sizeof(V));
}
void CalibracaoManual::SalvarArquivo(){
    std::ofstream out;
    std::cout << " salvando " << std::endl;
    out.open("cores.arff");
    for(int i = 0; i < 8; i++){
        out << i << " : " << coresCalibradas[i].MIN[0] << "." << coresCalibradas[i].MIN[1]<< "."<< coresCalibradas[i].MIN[2] << std::endl;
        out << i << " : " << coresCalibradas[i].MAX[0] << "." << coresCalibradas[i].MAX[1]<< "."<< coresCalibradas[i].MAX[2] << std::endl;
    }
    out.close();
}


