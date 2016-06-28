#include "calibracao.h"
using namespace std;

class Manual : public Calibracao
{
public:
    Manual();
    static void Calcular(Point point1, Point point2);
    void Iniciar(JanelaPrincipal *janela, int c);
    void Calibrar(JanelaPrincipal *janela, int c);
    void DeclararMatrizes();
private:
    int key;

};
