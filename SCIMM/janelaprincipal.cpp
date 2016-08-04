#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

#include "qcustomplot.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <qdebug.h>
#include <QCloseEvent>
#include "calibracao.h"
#include "automatica.h"
#include <stdio.h>
#include <stdlib.h>
Automatica CA;
QComboBox *op;
bool INDISPONIVEL;
int CAMERA =1;
JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaPrincipal)
{
    setWindowIcon(QIcon(":/icons/icone.png"));


    ui->setupUi(this);
    //Inicialização de Variaveis
    cor.COR_INDICE = 0;
    MIN[0] = MIN[1]  = MIN[2] = 0;
    MAX[0] = MAX[1]  = MAX[2] =256;
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
}
void JanelaPrincipal::SetText(int qtd){



}
void JanelaPrincipal::CameraIndisponivel(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "SCIMM", "Camera Indisponivel");
    INDISPONIVEL = true;
}

void JanelaPrincipal::ResetarTelas(){
    ui->BT_CA_INICIAR_CAM->setEnabled(true);
    ui->BT_CA_INICIAR->setEnabled(false);
    ui->BT_CA_FINALIZAR->setEnabled(false);
    ui->CB_CA_CORES->setEnabled(false);
    ui->PROGRESS_CA->setEnabled(false);
    INDISPONIVEL= false;

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
}
void JanelaPrincipal::SetStatus(int porcento, std::string mensagem){

    ui->LABEL_CA_STATUS->setText(QString::fromStdString(mensagem));
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
}

void JanelaPrincipal::BotaoSalvarFundo(){
    ui->BT_FUNDO->setEnabled(false);
     ui->PB_FUNDO->setEnabled(true);
    std::cout << "salvar fundo" << std::endl;
    CA.ReconhecerFundo(this);
    ui->BT_CONFIGURAR->setEnabled(true);
}

void JanelaPrincipal::BotaoConfigurar() {
   ui->BT_CONFIGURAR->setEnabled(false);
   CA.ConfigurarCamera(this);
   ui->BT_EXTRAIR->setEnabled(true);
}

void JanelaPrincipal::BotaoExtrair(){
ui->BT_EXTRAIR->setEnabled(false);
CA.ExtrairObjetos(this);
}

void JanelaPrincipal::ComboCorChanged(int index){
    INDICE_OBJETO = index;
    std::cout <<INDICE_OBJETO << std::endl;
}
void JanelaPrincipal::IniciarCameraAutomatico(){

    ui->BT_CA_INICIAR_CAM->setEnabled(false);
    //   ui->BT_CA_INICIAR->setEnabled(true);
    // ui->BT_CA_FINALIZAR->setEnabled(true);
    //ui->CB_CA_CORES->setEnabled(true);
    //ui->PROGRESS_CA->setEnabled(true);
    ui->BT_FUNDO->setEnabled(true);
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

