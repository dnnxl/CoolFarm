#ifndef HILOCUERVO_H
#define HILOCUERVO_H

#include "estructuras.h"
#include <QString>
#include <QThread>

class HiloCuervo : public QThread
{
public:
    HiloCuervo(); //hilo de persona
    void run(); //Sacar botella y poner botella.
    QString nombre; //nombre que recibe
    bool Stop = true; //condicion de parada
    bool Pausa = false; //Este bandera es para resume y pausa.
    int velocidad; //velocidad que tiene
    int frutos;

    // Aqui va el arbolito que se va a comer
};

#endif // HILOCUERVO_H
