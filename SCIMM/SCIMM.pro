#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T07:52:32
#
#-------------------------------------------------

QT       += core gui
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SCIMM
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core

SOURCES += main.cpp\
        janelaprincipal.cpp \
    corcalibrada.cpp \
    qcustomplot.cpp \
    calibracaoautomatica.cpp \
    calibracaomanual.cpp \
    camera.cpp \
    tdestudent.cpp

HEADERS  += janelaprincipal.h \
    corcalibrada.h \
    qcustomplot.h \
    calibracaoautomatica.h \
    calibracaomanual.h \
    camera.h \
    tdestudent.h

FORMS    += janelaprincipal.ui
