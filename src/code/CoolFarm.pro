#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T18:00:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoolFarm
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    juego.cpp \
    puntajes.cpp \
    mercado.cpp \
    info.cpp \
    principalwindow.cpp \
    hilocronometro.cpp \
    estructuras.cpp \
    hiloprincipal.cpp \
    finca.cpp \
    hilonodofinca.cpp \
    hiloplaga.cpp

HEADERS  += mainwindow.h \
    juego.h \
    puntajes.h \
    mercado.h \
    info.h \
    principalwindow.h \
    hilocronometro.h \
    estructuras.h \
    hiloprincipal.h \
    finca.h \
    hilonodofinca.h \
    hiloplagas.h

FORMS    += mainwindow.ui \
    puntajes.ui \
    mercado.ui \
    juego.ui \
    info.ui \
    principalwindow.ui

RESOURCES +=
