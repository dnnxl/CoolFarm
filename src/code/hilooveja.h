#ifndef HILOOVEJA_H
#define HILOOVEJA_H

#include "estructuras.h"
#include <QString>
#include <QThread>

class HiloOveja : public QThread
{
public:
    HiloOveja(); //hilo de persona
    void run(); //Sacar botella y poner botella.
    QString nombre; //nombre que recibe
    bool Stop = true; //condicion de parada
    bool Pausa = false; //Este bandera es para resume y pausa.
    int velocidad; //velocidad que tiene
    int frutos;

    // Aqui va el arbolito que se va a comer
};



#endif // HILOOVEJA_H
