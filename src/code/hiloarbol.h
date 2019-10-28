#ifndef HILOARBOL_H
#define HILOARBOL_H

#include <QString>
#include <QThread>

class HiloArbol : public QThread
{
public:
    HiloArbol(); //hilo de persona
    void run(); //Sacar botella y poner botella.
    QString nombre; //nombre que recibe
    bool Stop = true; //condicion de parada
    bool Pausa = false; //Este bandera es para resume y pausa.
    int velocidad; //velocidad que tiene
    int frutos;

    // Aqui va el arbolito que se va a comer
};


#endif // HILOARBOL_H
