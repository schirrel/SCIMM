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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QAction *actionManual;
    QAction *actionAutomatica;
    QAction *actionSobre;
    QWidget *centralWidget;
    QLabel *label_6;
    QPushButton *BT_CA_INICIAR;
    QPushButton *BT_CA_INICIAR_CAM;
    QProgressBar *PROGRESS_CA;
    QPushButton *BT_CA_FINALIZAR;
    QPushButton *BT_FUNDO;
    QProgressBar *PB_FUNDO;
    QLabel *IMAGEM;
    QPushButton *BT_CONFIGURAR;
    QFrame *frame;
    QLabel *label_9;
    QComboBox *CB_CA_CORES;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QStringLiteral("JanelaPrincipal"));
        JanelaPrincipal->setWindowModality(Qt::WindowModal);
        JanelaPrincipal->resize(657, 580);
        JanelaPrincipal->setLayoutDirection(Qt::LeftToRight);
        JanelaPrincipal->setAutoFillBackground(false);
        JanelaPrincipal->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        JanelaPrincipal->setDocumentMode(true);
        JanelaPrincipal->setTabShape(QTabWidget::Rounded);
        JanelaPrincipal->setDockNestingEnabled(false);
        actionManual = new QAction(JanelaPrincipal);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionAutomatica = new QAction(JanelaPrincipal);
        actionAutomatica->setObjectName(QStringLiteral("actionAutomatica"));
        actionSobre = new QAction(JanelaPrincipal);
        actionSobre->setObjectName(QStringLiteral("actionSobre"));
        centralWidget = new QWidget(JanelaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 0, 661, 41));
        QFont font;
        font.setPointSize(20);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        BT_CA_INICIAR = new QPushButton(centralWidget);
        BT_CA_INICIAR->setObjectName(QStringLiteral("BT_CA_INICIAR"));
        BT_CA_INICIAR->setEnabled(true);
        BT_CA_INICIAR->setGeometry(QRect(263, 49, 36, 36));
        QIcon icon;
        icon.addFile(QStringLiteral("color.png"), QSize(), QIcon::Normal, QIcon::Off);
        BT_CA_INICIAR->setIcon(icon);
        BT_CA_INICIAR->setIconSize(QSize(28, 28));
        BT_CA_INICIAR_CAM = new QPushButton(centralWidget);
        BT_CA_INICIAR_CAM->setObjectName(QStringLiteral("BT_CA_INICIAR_CAM"));
        BT_CA_INICIAR_CAM->setEnabled(true);
        BT_CA_INICIAR_CAM->setGeometry(QRect(65, 49, 36, 36));
        QIcon icon1;
        icon1.addFile(QStringLiteral("camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        BT_CA_INICIAR_CAM->setIcon(icon1);
        BT_CA_INICIAR_CAM->setIconSize(QSize(28, 28));
        BT_CA_INICIAR_CAM->setShortcut(QStringLiteral(""));
        BT_CA_INICIAR_CAM->setAutoDefault(false);
        BT_CA_INICIAR_CAM->setFlat(false);
        PROGRESS_CA = new QProgressBar(centralWidget);
        PROGRESS_CA->setObjectName(QStringLiteral("PROGRESS_CA"));
        PROGRESS_CA->setEnabled(false);
        PROGRESS_CA->setGeometry(QRect(300, 50, 71, 35));
        PROGRESS_CA->setValue(0);
        BT_CA_FINALIZAR = new QPushButton(centralWidget);
        BT_CA_FINALIZAR->setObjectName(QStringLiteral("BT_CA_FINALIZAR"));
        BT_CA_FINALIZAR->setEnabled(true);
        BT_CA_FINALIZAR->setGeometry(QRect(553, 50, 36, 36));
        QIcon icon2;
        icon2.addFile(QStringLiteral("salvar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BT_CA_FINALIZAR->setIcon(icon2);
        BT_CA_FINALIZAR->setIconSize(QSize(24, 24));
        BT_FUNDO = new QPushButton(centralWidget);
        BT_FUNDO->setObjectName(QStringLiteral("BT_FUNDO"));
        BT_FUNDO->setEnabled(true);
        BT_FUNDO->setGeometry(QRect(148, 49, 36, 36));
        QIcon icon3;
        icon3.addFile(QStringLiteral("fundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BT_FUNDO->setIcon(icon3);
        BT_FUNDO->setIconSize(QSize(28, 28));
        PB_FUNDO = new QProgressBar(centralWidget);
        PB_FUNDO->setObjectName(QStringLiteral("PB_FUNDO"));
        PB_FUNDO->setEnabled(false);
        PB_FUNDO->setGeometry(QRect(185, 50, 71, 35));
        PB_FUNDO->setValue(0);
        IMAGEM = new QLabel(centralWidget);
        IMAGEM->setObjectName(QStringLiteral("IMAGEM"));
        IMAGEM->setGeometry(QRect(8, 100, 741, 461));
        IMAGEM->setAutoFillBackground(false);
        BT_CONFIGURAR = new QPushButton(centralWidget);
        BT_CONFIGURAR->setObjectName(QStringLiteral("BT_CONFIGURAR"));
        BT_CONFIGURAR->setGeometry(QRect(106, 49, 36, 36));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(378, 50, 171, 35));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(6, 9, 49, 17));
        QFont font1;
        font1.setPointSize(12);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);
        CB_CA_CORES = new QComboBox(frame);
        CB_CA_CORES->setObjectName(QStringLiteral("CB_CA_CORES"));
        CB_CA_CORES->setEnabled(false);
        CB_CA_CORES->setGeometry(QRect(55, 4, 111, 27));
        label_9->raise();
        CB_CA_CORES->raise();
        BT_CA_FINALIZAR->raise();
        label_6->raise();
        JanelaPrincipal->setCentralWidget(centralWidget);

        retranslateUi(JanelaPrincipal);

        BT_CA_INICIAR_CAM->setDefault(false);


        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "SCIMM", 0));
        actionManual->setText(QApplication::translate("JanelaPrincipal", "Manual", 0));
        actionAutomatica->setText(QApplication::translate("JanelaPrincipal", "Automatica", 0));
        actionSobre->setText(QApplication::translate("JanelaPrincipal", "Sobre", 0));
        label_6->setText(QApplication::translate("JanelaPrincipal", "SCIMM", 0));
        BT_CA_INICIAR->setText(QString());
        BT_CA_INICIAR_CAM->setText(QString());
        BT_CA_FINALIZAR->setText(QString());
        BT_FUNDO->setText(QString());
        IMAGEM->setText(QString());
        BT_CONFIGURAR->setText(QString());
        label_9->setText(QApplication::translate("JanelaPrincipal", "Cores:", 0));
        CB_CA_CORES->clear();
        CB_CA_CORES->insertItems(0, QStringList()
         << QApplication::translate("JanelaPrincipal", "Amarelo", 0)
         << QApplication::translate("JanelaPrincipal", "Azul", 0)
         << QApplication::translate("JanelaPrincipal", "Verde", 0)
         << QApplication::translate("JanelaPrincipal", "Vermelho", 0)
         << QApplication::translate("JanelaPrincipal", "Laranja", 0)
         << QApplication::translate("JanelaPrincipal", "Rosa", 0)
         << QApplication::translate("JanelaPrincipal", "Roxo", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
