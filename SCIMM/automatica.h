#ifndef AUTOMATICA_H
#define AUTOMATICA_H
#include "calibracao.h"
#include "janelaprincipal.h"
#include "tdestudent.h"


#define LARANJA 4
#define AMARELO 0
#define AZUL 1
#define VERMELHO 3
#define VERDE 2
#define ROSA 5
#define ROXO 6

class Automatica : public Calibracao
{
public:
 Automatica();
 void ConfigurarCamera(JanelaPrincipal* janela);
 void Calibrar(JanelaPrincipal* janela);
 void Iniciar(JanelaPrincipal *janela, int c);
 void ReconhecerFundo(JanelaPrincipal* janela);
 void ExtrairObjetos(JanelaPrincipal* janela);
private:

    int thresh = 40;
    int brilho = 0, contraste = 50;
    std::vector<Rect> boundRect;
     std::vector<Rect> EliminarExcessos();
     void AplicarThresh(int, void *);
     double ObterPorcentagem(int valor, int porcentagem);

     bool CompararRectPorArea(Rect a, Rect b);

};

#endif // AUTOMATICA_H
