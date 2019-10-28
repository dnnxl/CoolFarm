#include "hilocronometro.h"
#include <QtCore>

HiloCronometro::HiloCronometro(Juego *parent) :
    QThread(parent)
{
    this->ventana = parent;
}

HiloCronometro::HiloCronometro(mercado *parent) :
    QThread(parent)
{
    this->ventanaMercado = parent;
}

void HiloCronometro::run()
{
    QMutex mutex;
    mutex.lock();
    int i = 0;
    while(true)
    {
        if(this->Stop == true)
        {
            break;
        }
        else if(this->bandera == true)
        {

        }
        else if(i == this->tiempoMercado+1 && this->abiertoJuego || i == this->tiempoParaVender+1 && this->abiertoMercado)
        {
            if(i == this->tiempoMercado+1 && this->abiertoJuego)
            {
                this->bandera = true;
                i = 0;
            }
            else
            {
                this->Stop = true;

            }
        }
        else
        {
            if(this->abiertoMercado)
            {
                ventanaMercado->setTime(i);
                i++;
            }
            else
            {
                ventana->setTextCronometro(i);
                i++;
            }
        }
        this->msleep(1000);//mslepp es en milisegundos entonces 1000ms = 1s
    }
    mutex.unlock();
    if(this->abiertoMercado)
    {
        this->ventanaMercado->setIndisponible();
    }
}
