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


   // void mouseHandler(int event, int x, int y, int flags, void *param) ;
    void DeclararMatrizes();
    void SalvarArquivo();

    void CalcularHSV(cv::Point ini, cv::Point fim) ;
    void mouseWrapper(int event, int x, int y, int flags, void *param);


};

#endif // CALIBRACAOMANUAL_H
