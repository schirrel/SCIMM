/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QAction *actionManual;
    QAction *actionAutomatica;
    QAction *actionSobre;
    QWidget *centralWidget;
    QStackedWidget *TELAS;
    QWidget *TelaManual;
    QWidget *TelaAutomatico;
    QFrame *frame_2;
    QLabel *label_6;
    QPushButton *BT_CA_INICIAR;
    QProgressBar *PROGRESS_CA;
    QLabel *LABEL_CA_STATUS;
    QLabel *label_9;
    QComboBox *CB_CA_CORES;
    QPushButton *BT_CA_FINALIZAR;
    QPushButton *BT_CA_INICIAR_CAM;
    QPushButton *BT_FUNDO;
    QPushButton *BT_CONFIGURAR;
    QPushButton *BT_EXTRAIR;
    QProgressBar *PB_EXTRAIR;
    QProgressBar *PB_FUNDO;
    QWidget *TelaSobre;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QStringLiteral("JanelaPrincipal"));
        JanelaPrincipal->resize(800, 600);
        actionManual = new QAction(JanelaPrincipal);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionAutomatica = new QAction(JanelaPrincipal);
        actionAutomatica->setObjectName(QStringLiteral("actionAutomatica"));
        actionSobre = new QAction(JanelaPrincipal);
        actionSobre->setObjectName(QStringLiteral("actionSobre"));
        centralWidget = new QWidget(JanelaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TELAS = new QStackedWidget(centralWidget);
        TELAS->setObjectName(QStringLiteral("TELAS"));
        TELAS->setGeometry(QRect(0, 0, 800, 600));
        TelaManual = new QWidget();
        TelaManual->setObjectName(QStringLiteral("TelaManual"));
        TELAS->addWidget(TelaManual);
        TelaAutomatico = new QWidget();
        TelaAutomatico->setObjectName(QStringLiteral("TelaAutomatico"));
        frame_2 = new QFrame(TelaAutomatico);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 800, 600));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 800, 50));
        QFont font;
        font.setPointSize(20);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        BT_CA_INICIAR = new QPushButton(frame_2);
        BT_CA_INICIAR->setObjectName(QStringLiteral("BT_CA_INICIAR"));
        BT_CA_INICIAR->setEnabled(false);
        BT_CA_INICIAR->setGeometry(QRect(10, 210, 141, 21));
        PROGRESS_CA = new QProgressBar(frame_2);
        PROGRESS_CA->setObjectName(QStringLiteral("PROGRESS_CA"));
        PROGRESS_CA->setEnabled(false);
        PROGRESS_CA->setGeometry(QRect(160, 210, 281, 21));
        PROGRESS_CA->setValue(0);
        LABEL_CA_STATUS = new QLabel(frame_2);
        LABEL_CA_STATUS->setObjectName(QStringLiteral("LABEL_CA_STATUS"));
        LABEL_CA_STATUS->setGeometry(QRect(450, 130, 241, 21));
        QFont font1;
        font1.setPointSize(15);
        LABEL_CA_STATUS->setFont(font1);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 270, 67, 17));
        CB_CA_CORES = new QComboBox(frame_2);
        CB_CA_CORES->setObjectName(QStringLiteral("CB_CA_CORES"));
        CB_CA_CORES->setEnabled(false);
        CB_CA_CORES->setGeometry(QRect(50, 270, 111, 27));
        BT_CA_FINALIZAR = new QPushButton(frame_2);
        BT_CA_FINALIZAR->setObjectName(QStringLiteral("BT_CA_FINALIZAR"));
        BT_CA_FINALIZAR->setEnabled(false);
        BT_CA_FINALIZAR->setGeometry(QRect(10, 240, 141, 21));
        BT_CA_INICIAR_CAM = new QPushButton(frame_2);
        BT_CA_INICIAR_CAM->setObjectName(QStringLiteral("BT_CA_INICIAR_CAM"));
        BT_CA_INICIAR_CAM->setGeometry(QRect(10, 90, 141, 21));
        BT_FUNDO = new QPushButton(frame_2);
        BT_FUNDO->setObjectName(QStringLiteral("BT_FUNDO"));
        BT_FUNDO->setEnabled(false);
        BT_FUNDO->setGeometry(QRect(10, 120, 141, 23));
        BT_CONFIGURAR = new QPushButton(frame_2);
        BT_CONFIGURAR->setObjectName(QStringLiteral("BT_CONFIGURAR"));
        BT_CONFIGURAR->setEnabled(false);
        BT_CONFIGURAR->setGeometry(QRect(10, 150, 141, 23));
        BT_EXTRAIR = new QPushButton(frame_2);
        BT_EXTRAIR->setObjectName(QStringLiteral("BT_EXTRAIR"));
        BT_EXTRAIR->setEnabled(false);
        BT_EXTRAIR->setGeometry(QRect(10, 180, 141, 23));
        PB_EXTRAIR = new QProgressBar(frame_2);
        PB_EXTRAIR->setObjectName(QStringLiteral("PB_EXTRAIR"));
        PB_EXTRAIR->setEnabled(false);
        PB_EXTRAIR->setGeometry(QRect(160, 180, 281, 21));
        PB_EXTRAIR->setValue(0);
        PB_FUNDO = new QProgressBar(frame_2);
        PB_FUNDO->setObjectName(QStringLiteral("PB_FUNDO"));
        PB_FUNDO->setEnabled(false);
        PB_FUNDO->setGeometry(QRect(160, 120, 281, 21));
        PB_FUNDO->setValue(0);
        TELAS->addWidget(TelaAutomatico);
        TelaSobre = new QWidget();
        TelaSobre->setObjectName(QStringLiteral("TelaSobre"));
        TelaSobre->setEnabled(true);
        label_7 = new QLabel(TelaSobre);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 800, 100));
        QFont font2;
        font2.setPointSize(80);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(TelaSobre);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 97, 800, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(TelaSobre);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 120, 800, 71));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(TelaSobre);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(-20, 350, 800, 20));
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(TelaSobre);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-20, 490, 800, 20));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(TelaSobre);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(-10, 410, 800, 100));
        QFont font3;
        font3.setPointSize(30);
        label_14->setFont(font3);
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(TelaSobre);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(0, 180, 800, 20));
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(TelaSobre);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 200, 800, 20));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(TelaSobre);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 220, 800, 20));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(TelaSobre);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 240, 800, 20));
        label_18->setAlignment(Qt::AlignCenter);
        TELAS->addWidget(TelaSobre);
        JanelaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JanelaPrincipal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        JanelaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JanelaPrincipal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JanelaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(JanelaPrincipal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JanelaPrincipal->setStatusBar(statusBar);

        retranslateUi(JanelaPrincipal);

        TELAS->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "SCIMM", 0));
        actionManual->setText(QApplication::translate("JanelaPrincipal", "Manual", 0));
        actionAutomatica->setText(QApplication::translate("JanelaPrincipal", "Automatica", 0));
        actionSobre->setText(QApplication::translate("JanelaPrincipal", "Sobre", 0));
        label_6->setText(QApplication::translate("JanelaPrincipal", "Calibra\303\247\303\243o Autom\303\241tica", 0));
        BT_CA_INICIAR->setText(QApplication::translate("JanelaPrincipal", "Iniciar Calibra\303\247\303\243o", 0));
        LABEL_CA_STATUS->setText(QString());
        label_9->setText(QApplication::translate("JanelaPrincipal", "Cores:", 0));
        CB_CA_CORES->clear();
        CB_CA_CORES->insertItems(0, QStringList()
         << QApplication::translate("JanelaPrincipal", "Amarelo", 0)
         << QApplication::translate("JanelaPrincipal", "Azul", 0)
         << QApplication::translate("JanelaPrincipal", "Verde", 0)
         << QApplication::translate("JanelaPrincipal", "Vermelho", 0)
         << QApplication::translate("JanelaPrincipal", "Laranja", 0)
        );
        BT_CA_FINALIZAR->setText(QApplication::translate("JanelaPrincipal", "FInalizar Calibra\303\247\303\243o", 0));
        BT_CA_INICIAR_CAM->setText(QApplication::translate("JanelaPrincipal", "Ligar Camera", 0));
        BT_FUNDO->setText(QApplication::translate("JanelaPrincipal", "Salvar Fundo", 0));
        BT_CONFIGURAR->setText(QApplication::translate("JanelaPrincipal", "Configurar", 0));
        BT_EXTRAIR->setText(QApplication::translate("JanelaPrincipal", "Extrair Objetos", 0));
        label_7->setText(QApplication::translate("JanelaPrincipal", "SCIMM", 0));
        label_10->setText(QApplication::translate("JanelaPrincipal", "Sistema de Calibra\303\247\303\243o de Intervalos Minimos e Maximos", 0));
        label_11->setText(QApplication::translate("JanelaPrincipal", "Desenvolvido por Jasane Schio.", 0));
        label_12->setText(QApplication::translate("JanelaPrincipal", "Trabalho de Conclus\303\243o de Curso", 0));
        label_13->setText(QApplication::translate("JanelaPrincipal", "Universidade Federal do Mato Grosso do Sul - Campus Coxim", 0));
        label_14->setText(QApplication::translate("JanelaPrincipal", "Equipe Cedro de Futebol de Rob\303\264s", 0));
        label_15->setText(QApplication::translate("JanelaPrincipal", "Linguagem: C++", 0));
        label_16->setText(QApplication::translate("JanelaPrincipal", "Framework GUI: Qt", 0));
        label_17->setText(QApplication::translate("JanelaPrincipal", "Widget de Plotagem de Grafico: QCustomPlot", 0));
        label_18->setText(QApplication::translate("JanelaPrincipal", "Biblioteca  de Processamento de Imagens: OpenCV", 0));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
