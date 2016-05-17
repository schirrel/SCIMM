#ifndef CALIBRACAOMANUAL_H
#define CALIBRACAOMANUAL_H
#include "janelaprincipal.h"
#include "corcalibrada.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream> // incluir
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
class CalibracaoManual
{
public:
    CalibracaoManual();
    void Iniciar(JanelaPrincipal* janela, int CAMERA);
    void Fechar();
    bool CameraLiberada();
private:

    int CAMERA = 0;
    int CALIBRANDO_ATUAL, drag, select_flag, key;
    int H[256], S[256], V[256];
    bool CalibracaoFinalizada = false;
    char* janelasNome[2] = {"Selecão de Cores", "Threshold"};
    CorCalibrada coresCalibradas[8];
    cv::Mat hsvImagens[8],frame, HSV, Threshold;
    cv::Point ponto_inicio, ponto_fim;
    cv::Vec3b pixel;

    void DeclararMatrizes();
    void SalvarArquivo();
    static   void mouseHandler(int event, int x, int y, int flags, void *param);
    void CalcularHSV(cv::Point ini, cv::Point fim) ;
    void mouseWrapper(int event, int x, int y, int flags, void *param);


};

#endif // CALIBRACAOMANUAL_H
