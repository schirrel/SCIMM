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



    // -----------  Métodos Calibração Automatica
    void SetText(int qtd);
    void SetStatus(int porcento, std::string mensagem);
    void SetStatusFundo(int n);

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

    //----------- Slots Calibração Automatica
    void ComboObjetoChanged(int index);
    void BotaoIniciar();
    void BotaoSalvar();
    void BotaoSalvarFundo();
    void BotaoConfigurar();
    void BotaoFinalizar();
    void BotaoExtrair();
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
