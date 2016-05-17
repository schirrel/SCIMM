#ifndef CALIBRACAOAUTOMATICA_H
#define CALIBRACAOAUTOMATICA_H
#include "janelaprincipal.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "corcalibrada.h"
#include "vector"
using namespace cv;
class CalibracaoAutomatica
{
public:
    CalibracaoAutomatica();
    void Iniciar(JanelaPrincipal* janela, int CAMERA);
    void Fechar();


private:

    CorCalibrada coresCalibradas[8];
    Mat src_gray, HSV, frame;
    int thresh = 20;
    std::vector<Rect> boundRect;
     std::vector<Rect> insideRect;
     std::vector<CorCalibrada> cores;
     std::vector<Rect> EliminarExcessos();
    void MetodoCalcular();
    void thresh_callback(int, void *);
    void SalvarArquivo();
    double ObterPorcentagem(int valor, int porcentagem);
    bool CompararRectPorArea(Rect a, Rect b);
};

#endif // CALIBRACAOAUTOMATICA_H
