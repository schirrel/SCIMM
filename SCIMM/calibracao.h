#ifndef CALIBRACAO_H
#define CALIBRACAO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "janelaprincipal.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "math.h"
#include <unistd.h>
using namespace cv;
class SCIMM
{
private:



public:
    SCIMM();
    int CAMERA;
    void Iniciar(JanelaPrincipal *janela, int c);
    void DeclararMatrizes();

    void Fechar();








};
#endif
