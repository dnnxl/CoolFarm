#ifndef HILOCRONOMETRO_H
#define HILOCRONOMETRO_H
#include <QThread>

#include "ui_Juego.h"///////////
#include "juego.h"

class Juego;
class mercado;

class HiloCronometro : public QThread
{
    Q_OBJECT

public:
    explicit HiloCronometro(Juego* parent = 0);//QObject *parent = 0);
    explicit HiloCronometro(mercado* parent = 0);//QObject *parent = 0);

    Juego * ventana;///////////
    mercado* ventanaMercado;
    void run();
    bool Stop = false;
    bool bandera;
    int tiempoMercado;
    int tiempoParaVender;//hilocronometro mercado
    bool abiertoMercado;
    bool abiertoJuego;

public slots:
};

#endif // HILOCRONOMETRO_H
