#ifndef AUTOMATICA_H
#define AUTOMATICA_H
#include "calibracao.h"
#include "janelaprincipal.h"
#include "tdestudent.h"
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

    int thresh = 20;
    int brilho = 0, contraste = 50;
    std::vector<Rect> boundRect;
     std::vector<Rect> EliminarExcessos();
     void AplicarThresh(int, void *);
     double ObterPorcentagem(int valor, int porcentagem);

     bool CompararRectPorArea(Rect a, Rect b);

};

#endif // AUTOMATICA_H
