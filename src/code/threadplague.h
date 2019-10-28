#ifndef THREADPLAGUE_H
#define THREADPLAGUE_H

#include "estructuras.h"
#include "hilonodofinca.h"
#include <QThread>
#include <QWaitCondition>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <QMutex>
#include <QtCore>
#include <QDebug>
#include <juego.h>

using namespace std;
class HiloPlaga;
//class Juego;

class HiloPlaga : public QThread
{
   // Q_OBJECT

public:
    explicit HiloPlaga(QObject *parent = 0);
    void run();
    bool Stop ;
    bool bandera;
    //void colocarPlaga(int pCantidad, int pType); //colocar la plaga
    void asignarValores(ListaDatos*pLista);
    //tipos de plaga
    Oveja *oveja; //oveja y cuervo funcionan igual
    Cuervo *cuervo; //oveja y cuervo funcionan igual
    Plaga *plaga; //gusano
    ListaDatos* lista;


signals:
    void ColocarPlaga(int,int);

public slots:

};

#endif // THREADPLAGUE_H
