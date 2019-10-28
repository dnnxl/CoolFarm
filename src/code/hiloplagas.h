#ifndef HILOPLAGAS_H
#define HILOPLAGAS_H

#include "estructuras.h"
#include "hilonodofinca.h"
#include <QtCore>
#include <QDebug>
#include <juego.h>

#include <QThread>
#include <QWaitCondition>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <QMutex>

using namespace std;

class HiloPlaga : public QThread
{
    Q_OBJECT

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
    void eeColocarPlaga(int,int);

public slots:

};

#endif // HILOPLAGAS_H
