#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H
#include "corcalibrada.h"
#include <QMainWindow>

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();
    void ResetarTelas();
    void CameraIndisponivel();

    // -----------  Métodos Calibração Manual
    void Plot(int h[256] , int s[256], int v[256]);
    void RePlot(int a[256]);
    void SetHSV(int h[256] , int s[256], int v[256]);

    // -----------  Métodos Calibração Automatica
    void SetText(int qtd);
    void SetStatus(int porcento, std::string mensagem);

    // -----------  Variaveis Publicas
    bool CALIBRADO[7];

    // -----------  Variaveis Publicas Calibração Manual
    int MIN[3], MAX[3],INDICE_CALIBRACAO;
    bool FINALIZADA, CALIBRAR;
    CorCalibrada cor;

    // -----------  Variaveis Publicas Calibração Automatica
    int INDICE_COR = 0    , INDICE_OBJETO = 0;
    bool SALVAR, INICIAR;



public slots:
    // ----------- Slots Menu
    void MenuManual();
    void MenuAutomatico();
    void MenuSobre();

    //-----------Slots Calibração Manual
    void TabChangedTo(int index);
    void ComboChanged(int index);
    void SalvarCalibracao();
    void FinalizarCalibracao();
    void IniciarCalibracao();
    void setMaxTextInt( int value);
    void setMaxSliderValue();
    void setMinTextInt( int value);
    void setMinSliderValue();

    //----------- Slots Calibração Automatica
    void ComboObjetoChanged(int index);
    void BotaoIniciar();
    void BotaoSalvar();
    void BotaoFinalizar();
    void ComboCorChanged(int index);

    void IniciarCameraManual();
    void IniciarCameraAutomatico();



private:
    Ui::JanelaPrincipal *ui;
    // -----------  Variaveis Publicas Calibração Manual
    int INDEX;
    int* H,*S, *V;


};

#endif // JANELAPRINCIPAL_H
