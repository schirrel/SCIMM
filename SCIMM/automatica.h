#ifndef AUTOMATICA_H
#define AUTOMATICA_H
#include "calibracao.h"
#include "janelaprincipal.h"
#include "tdestudent.h"
class Automatica : public Calibracao
{
public:
    Automatica();
    void ConfigurarCamera();
    void Calibrar(JanelaPrincipal* janela);
 void Iniciar(JanelaPrincipal *janela, int c);
private:

    int thresh = 20;
    std::vector<Rect> boundRect;
     std::vector<Rect> EliminarExcessos();
     void thresh_callback(int, void *);
     double ObterPorcentagem(int valor, int porcentagem);

     bool CompararRectPorArea(Rect a, Rect b);

};

#endif // AUTOMATICA_H
