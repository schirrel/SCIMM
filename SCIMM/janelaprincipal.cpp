#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"


#include <iostream>
#include <unistd.h>
#include <string>
#include <qdebug.h>
#include <QCloseEvent>
#include "calibracao.h"
#include <stdio.h>
#include <stdlib.h>
Calibracao CA;
QComboBox *op;
bool INDISPONIVEL;
int CAMERA =0;
JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    setWindowIcon(QIcon(":/icons/icone.png"));


    ui->setupUi(this);
    //Inicialização de Variaveis
    INDICE_CALIBRACAO =  INDEX = 0;
    memset(CALIBRADO, 0, sizeof(CALIBRADO));



    //Ações Calibração Automatica
    connect(ui->BT_CA_INICIAR, SIGNAL(clicked(bool)), SLOT(BotaoIniciar()));
    connect(ui->BT_CA_FINALIZAR, SIGNAL(clicked(bool)), SLOT(BotaoFinalizar()));
    connect(ui->CB_CA_CORES, SIGNAL(currentIndexChanged(int)), SLOT(ComboCorChanged(int)));
    connect(ui->BT_CA_INICIAR_CAM, SIGNAL(clicked(bool)), SLOT(IniciarCameraAutomatico()));
    connect(ui->BT_FUNDO, SIGNAL(clicked(bool)), SLOT(BotaoSalvarFundo()));
    connect(ui->BT_CONFIGURAR, SIGNAL(clicked(bool)), SLOT(BotaoConfigurar()));
    connect(ui->BT_EXTRAIR, SIGNAL(clicked(bool)), SLOT(BotaoExtrair()));

    ui->BT_CA_INICIAR_CAM->setIcon(QIcon(":/icons/camera.png"));
    ui->BT_FUNDO->setIcon(QIcon(":/icons/fundo.png"));
    ui->BT_CONFIGURAR->setIcon(QIcon(":/icons/configuracao.png"));
    ui->BT_EXTRAIR->setIcon(QIcon(":icons/detectar.png"));
     ui->BT_CA_INICIAR->setIcon(QIcon(":icons/color.png"));
     ui->BT_CA_FINALIZAR->setIcon(QIcon(":icons/salvar.png"));
}

void JanelaPrincipal::CameraIndisponivel(){
    //    QMessageBox::StandardButton reply;
    //    reply = QMessageBox::warning(this, "SCIMM", "Camera Indisponivel");
    //    INDISPONIVEL = true;
}

void JanelaPrincipal::ResetarTelas(){
    ui->BT_CA_INICIAR_CAM->setEnabled(true);
    ui->BT_CA_INICIAR->setEnabled(false);
    ui->BT_CA_FINALIZAR->setEnabled(false);
    ui->CB_CA_CORES->setEnabled(false);
    ui->PROGRESS_CA->setEnabled(false);
    INDISPONIVEL= false;

}


void JanelaPrincipal::SetImage(Mat frame){
    QImage img = ConverterFrame(frame);
    ui->IMAGEM->setPixmap(QPixmap::fromImage(img));
}

QImage JanelaPrincipal::ConverterFrame(Mat frame){
    switch ( frame.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( frame.data,
                      frame.cols, frame.rows,
                      static_cast<int>(frame.step),
                      QImage::Format_ARGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( frame.data,
                      frame.cols, frame.rows,
                      static_cast<int>(frame.step),
                      QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
        static QVector<QRgb>  sColorTable( 256 );

        // only create our color table the first time
        if ( sColorTable.isEmpty() )
        {
            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image( frame.data,
                      frame.cols, frame.rows,
                      static_cast<int>(frame.step),
                      QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );

        return image;
    }

    default:
        qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << frame.type();
        break;
    }
}


// ----------- Métodos Calibração Automatico -----------

void JanelaPrincipal::BotaoSalvar(){
    SALVAR=true;
    INDICE_COR = ui->CB_CA_CORES->currentIndex();
    CALIBRADO[INDICE_COR] = true;
}
void JanelaPrincipal::BotaoIniciar(){
    INICIAR = true;
    ui->BT_CA_INICIAR->setEnabled(false);
    CA.Calibrar();
    ui->BT_CA_FINALIZAR->setEnabled(true);
     FINALIZADA=false;
    CA.Exibir();

}
void JanelaPrincipal::SetStatus(int porcento){

    ui->PROGRESS_CA->setValue(porcento);
    ui->PROGRESS_CA->repaint();
    if(porcento>90){
        ui->CB_CA_CORES->setEnabled(true);
    }

}
void JanelaPrincipal::BotaoFinalizar(){
    CA.Fechar();
    FINALIZADA = true;
    this->close();

}
void JanelaPrincipal::SetStatusFundo(int n) {
    ui->PB_FUNDO->setValue(n);
    ui->PB_FUNDO->repaint();
    if(n==100)
        ui->PB_FUNDO->setEnabled(false);
}

void JanelaPrincipal::SetStatusExtrair(int n) {
    ui->PB_EXTRAIR->setValue(n);
    ui->PB_EXTRAIR->repaint();
    if(n==100)
        ui->PB_EXTRAIR->setEnabled(false);
}

void JanelaPrincipal::BotaoSalvarFundo(){
    ui->BT_FUNDO->setEnabled(false);

    CA.ReconhecerFundo();
     ui->BT_EXTRAIR->setEnabled(true);

 //
}

void JanelaPrincipal::BotaoConfigurar() {
    ui->BT_CONFIGURAR->setEnabled(false);
    CA.ConfigurarCamera();
    ui->BT_FUNDO->setEnabled(true);
    ui->PB_FUNDO->setEnabled(true);



}

void JanelaPrincipal::BotaoExtrair(){
    CA.ExtrairObjetos();

    ui->BT_EXTRAIR->setEnabled(false);
    ui->BT_CA_INICIAR->setEnabled(true);
}

void JanelaPrincipal::ComboCorChanged(int index){
    INDICE_OBJETO = index;

}
void JanelaPrincipal::IniciarCameraAutomatico(){

    ui->BT_CA_INICIAR_CAM->setEnabled(false);
    //   ui->BT_CA_INICIAR->setEnabled(true);
    // ui->BT_CA_FINALIZAR->setEnabled(true);
    //ui->CB_CA_CORES->setEnabled(true);
    //ui->PROGRESS_CA->setEnabled(true);
    ui->BT_CONFIGURAR->setEnabled(true);
    CA.Iniciar(this, CAMERA);
    // CA.ConfigurarCamera(this);
    if(INDISPONIVEL) {
        ResetarTelas();
    }

}


JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}

