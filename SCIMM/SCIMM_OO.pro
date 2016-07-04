#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T16:00:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SCIMM_OO
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core


SOURCES += main.cpp\
        janelaprincipal.cpp \
    calibracao.cpp \
    manual.cpp \
    automatica.cpp \
    corcalibrada.cpp \
    qcustomplot.cpp \
    tdestudent.cpp

HEADERS  += janelaprincipal.h \
    calibracao.h \
    manual.h \
    automatica.h \
    corcalibrada.h \
    qcustomplot.h \
    tdestudent.h

FORMS    += janelaprincipal.ui

RESOURCES += \
    icon.qrc
