#ifndef AUTOMATICA_H
#define AUTOMATICA_H
#include "calibracao.h"
#include "janelaprincipal.h"
#include <fstream>
#include "scimm_cor.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <unistd.h>
using namespace cv;


#define LARANJA 4
#define AMARELO 0
#define AZUL 1
#define VERMELHO 3
#define VERDE 2
#define ROSA 5
#define ROXO 6

class Calibracao
{
public:
    Calibracao();
    void ConfigurarCamera(JanelaPrincipal* janela);
    void Calibrar(JanelaPrincipal* janela);
    void Iniciar(JanelaPrincipal *janela, int c);
    void ReconhecerFundo(JanelaPrincipal* janela);
    void ExtrairObjetos(JanelaPrincipal* janela);
    void Exibir();
    void Calcular();
    void Fechar();
    void SalvarArquivo();
private:
    bool FIM;
    Mat  HSV;
    Mat frame;
    int thresh = 40;
    int CAMERA;
    int brilho = 0, contraste = 50;
    std::vector<Rect> boundRect;
    std::vector<Rect> EliminarExcessos();
    void DetectarObjetos(int, void *);
    double ObterPorcentagem(int valor, int porcentagem);
    JanelaPrincipal* JANELA;
    bool CompararRectPorArea(Rect a, Rect b);

};

#endif // AUTOMATICA_H
