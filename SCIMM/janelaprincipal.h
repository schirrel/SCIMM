#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H
#include <QMainWindow>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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
    void SetStatus(int porcento);
    void SetStatusFundo(int n);
    void SetStatusExtrair(int n);

    // -----------  Variaveis Publicas
    bool CALIBRADO[7];

    // -----------  Variaveis Publicas Calibração Manual
    int MIN[3], MAX[3],INDICE_CALIBRACAO;
    bool FINALIZADA=false, CALIBRAR;

    // -----------  Variaveis Publicas Calibração Automatica
    int INDICE_COR = 0    , INDICE_OBJETO = 0;
    bool SALVAR, INICIAR;



public slots:

    //----------- Slots Calibração Automatica
    void BotaoIniciar();
    void BotaoSalvar();
    void BotaoSalvarFundo();
    void BotaoConfigurar();
    void BotaoFinalizar();
    void BotaoExtrair();
    void ComboCorChanged(int index);
    void SetImage(cv::Mat frame);
    void IniciarCameraAutomatico();
    QImage ConverterFrame(cv::Mat frame);


private:
    Ui::JanelaPrincipal *ui;
    // -----------  Variaveis Publicas Calibração Manual
    int INDEX;
    int* H,*S, *V;


};

#endif // JANELAPRINCIPAL_H
