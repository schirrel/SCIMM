/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

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
    QFrame *frameManual;
    QTabWidget *TAB_HSV;
    QWidget *TAB_H;
    QCustomPlot *customPlotH;
    QWidget *TAB_S;
    QCustomPlot *customPlotS;
    QWidget *TAB_V;
    QCustomPlot *customPlotV;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *SLIDER_CM_MIN;
    QLineEdit *EDIT_CM_MIN;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *SLIDER_CM_MAX;
    QLineEdit *EDIT_CM_MAX;
    QPushButton *BT_CM_FINALIZAR;
    QPushButton *BT_CM_SALVAR;
    QPushButton *BT_CM_CALIBRAR;
    QComboBox *CB_CM_CORES;
    QFrame *frame;
    QCheckBox *CHECK_CM_CALIBRADO;
    QLabel *label_5;
    QPushButton *BT_CM_INICIAR;
    QWidget *TelaAutomatico;
    QFrame *frame_2;
    QLabel *label_6;
    QPushButton *BT_CA_INICIAR;
    QProgressBar *PROGRESS_CA;
    QLabel *LABEL_CA_STATUS;
    QLabel *label_8;
    QComboBox *CB_CA_OBJETOS;
    QLabel *label_9;
    QPushButton *BT_CA_SALVAR;
    QCheckBox *CHECK_CA_CALIBRADO;
    QComboBox *CB_CA_CORES;
    QPushButton *BT_CA_FINALIZAR;
    QPushButton *BT_CA_INICIAR_CAM;
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
    QMenu *menuCalibracao;
    QMenu *menuAjuda;
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
        frameManual = new QFrame(TelaManual);
        frameManual->setObjectName(QStringLiteral("frameManual"));
        frameManual->setEnabled(true);
        frameManual->setGeometry(QRect(0, 0, 800, 600));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameManual->sizePolicy().hasHeightForWidth());
        frameManual->setSizePolicy(sizePolicy);
        frameManual->setFrameShape(QFrame::StyledPanel);
        frameManual->setFrameShadow(QFrame::Raised);
        TAB_HSV = new QTabWidget(frameManual);
        TAB_HSV->setObjectName(QStringLiteral("TAB_HSV"));
        TAB_HSV->setGeometry(QRect(150, 50, 641, 371));
        TAB_H = new QWidget();
        TAB_H->setObjectName(QStringLiteral("TAB_H"));
        customPlotH = new QCustomPlot(TAB_H);
        customPlotH->setObjectName(QStringLiteral("customPlotH"));
        customPlotH->setGeometry(QRect(0, 0, 640, 340));
        TAB_HSV->addTab(TAB_H, QString());
        TAB_S = new QWidget();
        TAB_S->setObjectName(QStringLiteral("TAB_S"));
        customPlotS = new QCustomPlot(TAB_S);
        customPlotS->setObjectName(QStringLiteral("customPlotS"));
        customPlotS->setGeometry(QRect(0, 0, 640, 340));
        TAB_HSV->addTab(TAB_S, QString());
        TAB_V = new QWidget();
        TAB_V->setObjectName(QStringLiteral("TAB_V"));
        customPlotV = new QCustomPlot(TAB_V);
        customPlotV->setObjectName(QStringLiteral("customPlotV"));
        customPlotV->setGeometry(QRect(0, 0, 640, 340));
        TAB_HSV->addTab(TAB_V, QString());
        verticalLayoutWidget_2 = new QWidget(frameManual);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 420, 781, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        SLIDER_CM_MIN = new QSlider(verticalLayoutWidget_2);
        SLIDER_CM_MIN->setObjectName(QStringLiteral("SLIDER_CM_MIN"));
        SLIDER_CM_MIN->setEnabled(false);
        SLIDER_CM_MIN->setMaximum(255);
        SLIDER_CM_MIN->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(SLIDER_CM_MIN);

        EDIT_CM_MIN = new QLineEdit(verticalLayoutWidget_2);
        EDIT_CM_MIN->setObjectName(QStringLiteral("EDIT_CM_MIN"));
        EDIT_CM_MIN->setEnabled(false);
        EDIT_CM_MIN->setMinimumSize(QSize(60, 0));
        EDIT_CM_MIN->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(EDIT_CM_MIN);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        SLIDER_CM_MAX = new QSlider(verticalLayoutWidget_2);
        SLIDER_CM_MAX->setObjectName(QStringLiteral("SLIDER_CM_MAX"));
        SLIDER_CM_MAX->setEnabled(false);
        SLIDER_CM_MAX->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(SLIDER_CM_MAX);

        EDIT_CM_MAX = new QLineEdit(verticalLayoutWidget_2);
        EDIT_CM_MAX->setObjectName(QStringLiteral("EDIT_CM_MAX"));
        EDIT_CM_MAX->setEnabled(false);
        EDIT_CM_MAX->setMinimumSize(QSize(60, 0));
        EDIT_CM_MAX->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(EDIT_CM_MAX);


        verticalLayout_2->addLayout(horizontalLayout_4);

        BT_CM_FINALIZAR = new QPushButton(frameManual);
        BT_CM_FINALIZAR->setObjectName(QStringLiteral("BT_CM_FINALIZAR"));
        BT_CM_FINALIZAR->setEnabled(false);
        BT_CM_FINALIZAR->setGeometry(QRect(20, 340, 110, 60));
        BT_CM_SALVAR = new QPushButton(frameManual);
        BT_CM_SALVAR->setObjectName(QStringLiteral("BT_CM_SALVAR"));
        BT_CM_SALVAR->setEnabled(false);
        BT_CM_SALVAR->setGeometry(QRect(20, 270, 110, 60));
        BT_CM_CALIBRAR = new QPushButton(frameManual);
        BT_CM_CALIBRAR->setObjectName(QStringLiteral("BT_CM_CALIBRAR"));
        BT_CM_CALIBRAR->setEnabled(false);
        BT_CM_CALIBRAR->setGeometry(QRect(20, 120, 110, 60));
        CB_CM_CORES = new QComboBox(frameManual);
        CB_CM_CORES->setObjectName(QStringLiteral("CB_CM_CORES"));
        CB_CM_CORES->setEnabled(false);
        CB_CM_CORES->setGeometry(QRect(15, 200, 121, 27));
        frame = new QFrame(frameManual);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 190, 131, 70));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        CHECK_CM_CALIBRADO = new QCheckBox(frame);
        CHECK_CM_CALIBRADO->setObjectName(QStringLiteral("CHECK_CM_CALIBRADO"));
        CHECK_CM_CALIBRADO->setEnabled(false);
        CHECK_CM_CALIBRADO->setGeometry(QRect(10, 40, 111, 22));
        label_5 = new QLabel(frameManual);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 0, 800, 50));
        QFont font;
        font.setPointSize(20);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        BT_CM_INICIAR = new QPushButton(frameManual);
        BT_CM_INICIAR->setObjectName(QStringLiteral("BT_CM_INICIAR"));
        BT_CM_INICIAR->setGeometry(QRect(20, 50, 111, 61));
        frame->raise();
        TAB_HSV->raise();
        verticalLayoutWidget_2->raise();
        BT_CM_FINALIZAR->raise();
        BT_CM_SALVAR->raise();
        BT_CM_CALIBRAR->raise();
        CB_CM_CORES->raise();
        label_5->raise();
        BT_CM_INICIAR->raise();
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
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        BT_CA_INICIAR = new QPushButton(frame_2);
        BT_CA_INICIAR->setObjectName(QStringLiteral("BT_CA_INICIAR"));
        BT_CA_INICIAR->setEnabled(false);
        BT_CA_INICIAR->setGeometry(QRect(300, 160, 200, 50));
        PROGRESS_CA = new QProgressBar(frame_2);
        PROGRESS_CA->setObjectName(QStringLiteral("PROGRESS_CA"));
        PROGRESS_CA->setEnabled(false);
        PROGRESS_CA->setGeometry(QRect(100, 250, 600, 50));
        PROGRESS_CA->setValue(0);
        LABEL_CA_STATUS = new QLabel(frame_2);
        LABEL_CA_STATUS->setObjectName(QStringLiteral("LABEL_CA_STATUS"));
        LABEL_CA_STATUS->setGeometry(QRect(100, 300, 600, 30));
        QFont font1;
        font1.setPointSize(15);
        LABEL_CA_STATUS->setFont(font1);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 350, 150, 17));
        CB_CA_OBJETOS = new QComboBox(frame_2);
        CB_CA_OBJETOS->setObjectName(QStringLiteral("CB_CA_OBJETOS"));
        CB_CA_OBJETOS->setEnabled(false);
        CB_CA_OBJETOS->setGeometry(QRect(240, 345, 85, 27));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 400, 67, 17));
        BT_CA_SALVAR = new QPushButton(frame_2);
        BT_CA_SALVAR->setObjectName(QStringLiteral("BT_CA_SALVAR"));
        BT_CA_SALVAR->setEnabled(false);
        BT_CA_SALVAR->setGeometry(QRect(340, 360, 100, 50));
        CHECK_CA_CALIBRADO = new QCheckBox(frame_2);
        CHECK_CA_CALIBRADO->setObjectName(QStringLiteral("CHECK_CA_CALIBRADO"));
        CHECK_CA_CALIBRADO->setEnabled(false);
        CHECK_CA_CALIBRADO->setGeometry(QRect(210, 430, 97, 22));
        CB_CA_CORES = new QComboBox(frame_2);
        CB_CA_CORES->setObjectName(QStringLiteral("CB_CA_CORES"));
        CB_CA_CORES->setEnabled(false);
        CB_CA_CORES->setGeometry(QRect(215, 395, 111, 27));
        BT_CA_FINALIZAR = new QPushButton(frame_2);
        BT_CA_FINALIZAR->setObjectName(QStringLiteral("BT_CA_FINALIZAR"));
        BT_CA_FINALIZAR->setEnabled(false);
        BT_CA_FINALIZAR->setGeometry(QRect(300, 480, 200, 50));
        BT_CA_INICIAR_CAM = new QPushButton(frame_2);
        BT_CA_INICIAR_CAM->setObjectName(QStringLiteral("BT_CA_INICIAR_CAM"));
        BT_CA_INICIAR_CAM->setGeometry(QRect(309, 61, 181, 51));
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
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        menuCalibracao = new QMenu(menuBar);
        menuCalibracao->setObjectName(QStringLiteral("menuCalibracao"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        JanelaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JanelaPrincipal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JanelaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(JanelaPrincipal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JanelaPrincipal->setStatusBar(statusBar);

        menuBar->addAction(menuCalibracao->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuCalibracao->addAction(actionManual);
        menuCalibracao->addAction(actionAutomatica);
        menuAjuda->addAction(actionSobre);

        retranslateUi(JanelaPrincipal);

        TELAS->setCurrentIndex(2);
        TAB_HSV->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "SCIMM", 0));
        actionManual->setText(QApplication::translate("JanelaPrincipal", "Manual", 0));
        actionAutomatica->setText(QApplication::translate("JanelaPrincipal", "Automatica", 0));
        actionSobre->setText(QApplication::translate("JanelaPrincipal", "Sobre", 0));
        TAB_HSV->setTabText(TAB_HSV->indexOf(TAB_H), QApplication::translate("JanelaPrincipal", "H", 0));
        TAB_HSV->setTabText(TAB_HSV->indexOf(TAB_S), QApplication::translate("JanelaPrincipal", "S", 0));
        TAB_HSV->setTabText(TAB_HSV->indexOf(TAB_V), QApplication::translate("JanelaPrincipal", "V", 0));
        label_3->setText(QApplication::translate("JanelaPrincipal", "MIN", 0));
        label_4->setText(QApplication::translate("JanelaPrincipal", "MAX", 0));
        BT_CM_FINALIZAR->setText(QApplication::translate("JanelaPrincipal", "Finalizar", 0));
        BT_CM_SALVAR->setText(QApplication::translate("JanelaPrincipal", "Salvar", 0));
        BT_CM_CALIBRAR->setText(QApplication::translate("JanelaPrincipal", "Calibrar", 0));
        CB_CM_CORES->clear();
        CB_CM_CORES->insertItems(0, QStringList()
         << QApplication::translate("JanelaPrincipal", "Amarelo", 0)
         << QApplication::translate("JanelaPrincipal", "Azul", 0)
         << QApplication::translate("JanelaPrincipal", "Ciano", 0)
         << QApplication::translate("JanelaPrincipal", "Laranja", 0)
         << QApplication::translate("JanelaPrincipal", "Verde", 0)
         << QApplication::translate("JanelaPrincipal", "Vermelho", 0)
         << QApplication::translate("JanelaPrincipal", "Rosa", 0)
         << QApplication::translate("JanelaPrincipal", "Roxo", 0)
        );
        CHECK_CM_CALIBRADO->setText(QApplication::translate("JanelaPrincipal", "Calibrada", 0));
        label_5->setText(QApplication::translate("JanelaPrincipal", "Calibra\303\247\303\243o Manual", 0));
        BT_CM_INICIAR->setText(QApplication::translate("JanelaPrincipal", "Ligar Camera", 0));
        label_6->setText(QApplication::translate("JanelaPrincipal", "Calibra\303\247\303\243o Autom\303\241tica", 0));
        BT_CA_INICIAR->setText(QApplication::translate("JanelaPrincipal", "Iniciar Calibra\303\247\303\243o", 0));
        LABEL_CA_STATUS->setText(QString());
        label_8->setText(QApplication::translate("JanelaPrincipal", "Objetos Encontrado", 0));
        label_9->setText(QApplication::translate("JanelaPrincipal", "Cores:", 0));
        BT_CA_SALVAR->setText(QApplication::translate("JanelaPrincipal", "Salvar", 0));
        CHECK_CA_CALIBRADO->setText(QApplication::translate("JanelaPrincipal", "Calibrada", 0));
        CB_CA_CORES->clear();
        CB_CA_CORES->insertItems(0, QStringList()
         << QApplication::translate("JanelaPrincipal", "Amarelo", 0)
         << QApplication::translate("JanelaPrincipal", "Azul", 0)
         << QApplication::translate("JanelaPrincipal", "Ciano", 0)
         << QApplication::translate("JanelaPrincipal", "Laranja", 0)
         << QApplication::translate("JanelaPrincipal", "Verde", 0)
         << QApplication::translate("JanelaPrincipal", "Vermelho", 0)
         << QApplication::translate("JanelaPrincipal", "Rosa", 0)
         << QApplication::translate("JanelaPrincipal", "Roxo", 0)
        );
        BT_CA_FINALIZAR->setText(QApplication::translate("JanelaPrincipal", "FInalizar Calibra\303\247\303\243o", 0));
        BT_CA_INICIAR_CAM->setText(QApplication::translate("JanelaPrincipal", "Ligar Camera", 0));
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
        menuCalibracao->setTitle(QApplication::translate("JanelaPrincipal", "Calibra\303\247\303\243o", 0));
        menuAjuda->setTitle(QApplication::translate("JanelaPrincipal", "Ajuda", 0));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
