#include "mainwindow.h"
#include <QApplication>
#include "juego.h" // Para poder abrir la ventana de Juego
#include "principalwindow.h" // Para poder acceder a la principal

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principalWindow p;
    p.show();
    return a.exec();
}

