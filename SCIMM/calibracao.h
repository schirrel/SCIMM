#ifndef CALIBRACAO_H
#define CALIBRACAO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "corcalibrada.h"
#include "janelaprincipal.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "math.h"
#include <unistd.h>
using namespace cv;
class Calibracao
{
private:



public:
    Calibracao();
      int CAMERA;
    void Iniciar(JanelaPrincipal *janela, int c);
    void DeclararMatrizes();
     void Calcular();
    void Fechar();
    void SalvarArquivo();




    bool FIM;
    Mat  HSV;
    int H[256], S[256], V[256];
    Mat frame;
   CorCalibrada coresCalibradas[8];


};
#endif
