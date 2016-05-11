#include "calibracaomanual.h"
#include "janelaprincipal.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define CAMERA 0
using namespace cv;
bool FIM=false;
CalibracaoManual::CalibracaoManual()
{

}

void CalibracaoManual::Iniciar(JanelaPrincipal*  janela){
    int CALIBRANDO_ATUAL;
    Mat frame, src;
    cv::VideoCapture camera(0);
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
            cv::imshow(janelasNome[0], frame);
            //  cv::setMouseCallback("janelasNome[0]",mouseWrapper,this);
            if(janela->CALIBRAR){
                janela->SetHSV(H,S,V);
                janela->CALIBRAR = false;

            }
            key = cv::waitKey(5) & 255;
            if (key == 99 || FIM) {
                 cv::destroyAllWindows();
                camera.release();
                camera.release();
                camera.release();
                camera.release();
                camera.release();
                cv::destroyAllWindows();

                break;
            }
        }
        cv::destroyWindow(janelasNome[0]);
        cv::destroyAllWindows();


        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();
        camera.release();

        cv::destroyAllWindows();
SalvarArquivo();
    }


}
void CalibracaoManual::Fechar(){
    FIM =true;

}

void CalibracaoManual::DeclararMatrizes(){
    memset(H, 0, sizeof(H));
    memset(S, 0, sizeof(S));
    memset(V, 0, sizeof(V));
}
void CalibracaoManual::SalvarArquivo(){
    std::ofstream out;
    out.open("cores.arff");
    for(int i = 0; i < 8; i++){
        out << i << " : " << coresCalibradas[i].MIN[0] << "." << coresCalibradas[i].MIN[1]<< "."<< coresCalibradas[i].MIN[2] << std::endl;
        out << i << " : " << coresCalibradas[i].MAX[0] << "." << coresCalibradas[i].MAX[1]<< "."<< coresCalibradas[i].MAX[2] << std::endl;
    }
    out.close();
}
void CalibracaoManual::CalcularHSV(cv::Point ini, cv::Point fim) {
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



