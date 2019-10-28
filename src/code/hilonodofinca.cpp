#include "hilonodofinca.h"
#include <QtCore>

HiloNodoFinca::HiloNodoFinca()
{
    this->Stop = true;
    this->Pausa = false;

    this->globalTiempoPlaga = 0;
    this->globalTiempoGusano = 0;

    this->globalGusano = false;

    this->ArbolAvl = NULL;
    this->ArbolBinario = NULL;

    this->ArbolHeap = NULL;
    this->ArbolSplay = NULL;

    this->oveja = NULL;
    this->cuervo = NULL;
    this->Gusano = NULL;
    this->posicion = 0;
}

void HiloNodoFinca::anular()
{
    if(this->ArbolAvl != NULL)
    {
        ArbolAvl = NULL;
    }
    else if(this->ArbolBinario != NULL)
    {
        ArbolBinario = NULL;
    }
    else if(this->ArbolHeap != NULL)
    {
        ArbolHeap = NULL;
    }
    else
    {
        ArbolSplay = NULL;
    }
}

int HiloNodoFinca::cantidadDeFrutosActuales()
{

    if(this->ArbolBinario != NULL)
    {
        return this->ArbolBinario->cantidadFrutosBB(this->ArbolBinario->raizAB);
    }
    else if(this->ArbolAvl != NULL)
    {
        return this->ArbolAvl->cantidadFrutosAVL(this->ArbolAvl->raizAVL);
    }
    else if(this->ArbolHeap != NULL)
    {
        return this->ArbolHeap->cantidadFrutosHeap(this->ArbolHeap->raizHeap);
    }
    else if(this->ArbolSplay != NULL)
    {
        return this->ArbolSplay->cantidadFrutosSplay(this->ArbolSplay->raizSplay);
    }
    else
    {
        return 0;
    }
}

int HiloNodoFinca::cantidadDeFrutosPerdidos()
{
    if(this->ArbolBinario != NULL)
    {
        return this->ArbolBinario->frutosPerdidos;
    }
    else if(this->ArbolAvl != NULL)
    {
        return this->ArbolAvl->frutosPerdidos;
    }
    else if(this->ArbolHeap != NULL)
    {
        return this->ArbolHeap->frutosPerdidos;
    }
    else if(this->ArbolSplay != NULL)
    {
        return this->ArbolSplay->frutosPerdidos;
    }
    else
    {
        return 0;
    }
}

//---------------------------------------------------------------
//Entradas: Ninguno.
//Salidas: Ninguno.
//Descripcion: Hilo start, donde empieza el hilo.

void HiloNodoFinca::run()
{
    sleep(ArbolTiempoCrecimiento()); // llaama la función, en donde le dirá el tiempo de crecimiento del arbol que no está nulo
    int tiempoArbol = 0;
    int tiempoPlaga = 0;
    int tiempoGusano = 0;

    while(this->Stop) // While true
    {
        if(this->Pausa == true)
        {

        }
        else if(this->globalGusano == true)
        {
            this->Stop = false;
        }
        else if(hayArbol() == true)
        {
            if(tiempoArbol == tiempoParaDarFrutos())
            {
                tiempoArbol = 0;
                darFrutos();

                if(hayPlagas() == true)
                {
                    if(this->Gusano != NULL)
                    {
                        this->globalTiempoGusano = this->globalTiempoGusano + 1;
                        PlagaCome();
                    }

                    else if(tiempoListoParaComer() <= tiempoPlaga)
                    {
                        PlagaCome(); // come
                        tiempoPlaga = 0;
                        this->globalTiempoPlaga = 0;
                    }
                    else
                    {
                        tiempoPlaga = tiempoPlaga + 1;
                        this->globalTiempoPlaga = this->globalTiempoPlaga + 1;
                        this->globalTiempoGusano = 0;
                    }
                }
                else
                {
                    tiempoPlaga = 0;
                    this->globalTiempoPlaga = 0;
                    this->globalTiempoGusano = 0;

                }
            }

            else
            {
                 tiempoArbol = tiempoArbol + 1;
                 tiempoPlaga = tiempoPlaga + 1;
                 this->globalTiempoPlaga = this->globalTiempoPlaga + 1;
                 sleep(1);
            }
        }
    }
}

void HiloNodoFinca::espantar()
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    if(this->oveja != NULL)
    {
        this->oveja = NULL;
    }
    else if(this->cuervo != NULL)
    {
        this->cuervo = NULL;
    }
    else if(this->Gusano != NULL)
    {
        this->Gusano = NULL;
    }
    else
    {
    }
    mutex->unlock();
}


bool HiloNodoFinca::hayGusano()
{
    if(this->Gusano == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int HiloNodoFinca::tiempoListoParaComer()
{
    if(this->oveja != NULL)
    {
        return this->oveja->tiempoFruto;
    }
    else if(this->cuervo != NULL)
    {
        return this->cuervo->tiempoFruto;
    }
    else if(this->Gusano != NULL)
    {
        return this->Gusano->tiempo;
    }
}


void HiloNodoFinca::PlagaCome()
{
    if(this->oveja != NULL)
    {
        if(this->ArbolAvl != NULL)
        {
            this->ArbolAvl->frutosPerdidos = this->ArbolAvl->borrarRaizAVL(this->oveja->fruto) + this->ArbolAvl->frutosPerdidos;
        }
        else if(this->ArbolBinario != NULL)
        {
            this->ArbolBinario->frutosPerdidos = this->ArbolBinario->borrarRaiz(this->oveja->fruto) + this->ArbolBinario->frutosPerdidos;
        }
        else if(this->ArbolHeap != NULL)
        {
            this->ArbolHeap->frutosPerdidos = this->ArbolHeap->borrarRaiz(this->oveja->fruto) + this->ArbolHeap->frutosPerdidos;
        }
        else
        {
            this->ArbolSplay->frutosPerdidos = this->ArbolSplay->frutosPerdidos + this->ArbolSplay->borrarRaizSplay(this->oveja->fruto);
        }
    }
    else if(this->cuervo != NULL)
    {
        if(this->ArbolAvl != NULL)
        {
            this->ArbolAvl->frutosPerdidos = this->ArbolAvl->frutosPerdidos + this->ArbolAvl->borrarRaizAVL(this->cuervo->fruto);

        }
        else if(this->ArbolBinario != NULL)
        {
            this->ArbolBinario->frutosPerdidos = this->ArbolBinario->frutosPerdidos + this->ArbolBinario->borrarRaiz(this->cuervo->fruto);

        }
        else if(this->ArbolHeap != NULL)
        {
            this->ArbolHeap->frutosPerdidos = this->ArbolHeap->frutosPerdidos + this->ArbolHeap->borrarRaiz(this->cuervo->fruto);

        }
        else
        {
            this->ArbolSplay->frutosPerdidos = this->ArbolSplay->frutosPerdidos + this->ArbolSplay->borrarRaizSplay(this->cuervo->fruto);

        }
    }
    else if(this->Gusano != NULL && globalTiempoGusano != 0)
    {
        if(this->ArbolAvl != NULL)
        {
            if(this->globalTiempoGusano >= this->Gusano->tiempo)
            {
                this->ArbolAvl = NULL;
                if(this->ArbolAvl == NULL)
                {
                    this->globalGusano = true;
                    this->Gusano = NULL;
                }
            }
            else
            {
                this->Gusano->eliminarRaizAvl(this->globalTiempoGusano,this->Gusano->tiempo,this->ArbolAvl);
                this->ArbolAvl->frutosPerdidos = this->ArbolAvl->frutosPerdidos + this->Gusano->frutos;
            }

        }
        else if(this->ArbolBinario != NULL)
        {
            if(this->globalTiempoGusano == this->Gusano->tiempo)
            {
                this->ArbolBinario = NULL;
                if(this->ArbolBinario == NULL)
                {
                    this->globalGusano = true;
                    this->Gusano = NULL;
                }
            }
            else
            {
                this->Gusano->eliminarRaiz(this->globalTiempoGusano,this->Gusano->tiempo,this->ArbolBinario);
                this->ArbolBinario->frutosPerdidos = this->ArbolBinario->frutosPerdidos + this->Gusano->frutos;
            }

        }
        else if(this->ArbolHeap != NULL)
        {
            if(this->globalTiempoGusano == this->Gusano->tiempo)
            {
                this->ArbolHeap = NULL;
                if(this->ArbolHeap == NULL)
                {
                    this->globalGusano = true;
                    this->Gusano = NULL;
                }
            }
            else
            {
                this->Gusano->eliminarRaizHeap(this->globalTiempoGusano,this->Gusano->tiempo,this->ArbolHeap);
                this->ArbolHeap->frutosPerdidos = this->ArbolHeap->frutosPerdidos + this->Gusano->frutos;
            }
        }
        else
        {
            if(this->globalTiempoGusano == this->Gusano->tiempo)
            {
                this->ArbolSplay = NULL;
                if(this->ArbolSplay == NULL)
                {
                    this->globalGusano = true;
                    this->Gusano = NULL;
                }
            }
            else
            {
                this->Gusano->eliminarRaizSplay(this->globalTiempoGusano,this->Gusano->tiempo,this->ArbolSplay);
                this->ArbolSplay->frutosPerdidos = this->ArbolSplay->frutosPerdidos + this->Gusano->frutos;
            }
        }
    }
    else
    {
    }
}

int HiloNodoFinca::tiempoParaDarFrutos()
{
    if(this->ArbolBinario != NULL)
    {
        return this->ArbolBinario->tiempoCosecha;
    }
    else if(this->ArbolAvl != NULL)
    {
        return this->ArbolAvl->tiempoCosecha;
    }
    else if(this->ArbolHeap != NULL)
    {
        return this->ArbolHeap->tiempoCosecha;
    }
    else if(this->ArbolSplay != NULL)
    {
        return this->ArbolSplay->tiempoCosecha;
    }
    else
    {
        return 0;
    }
}

void HiloNodoFinca::darFrutos()
{
    if(this->ArbolBinario != NULL)
    {
        this->ArbolBinario->agregar(this->ArbolBinario->cantidadCosecha);
    }
    else if(this->ArbolAvl != NULL)
    {
        this->ArbolAvl->agregar(this->ArbolAvl->cantidadCosecha);
    }
    else if(this->ArbolHeap != NULL)
    {
        this->ArbolHeap->agregar(this->ArbolHeap->cantidadCosecha);
    }
    else if(this->ArbolSplay != NULL)
    {
        this->ArbolSplay->agregar(this->ArbolSplay->cantidadCosecha); //////////////////ESPERANDO LAS FUNCIONES DE COTO/////////////////////////
    }
    else
    {
    }
}

int HiloNodoFinca::ArbolTiempoCrecimiento()
{
    if(this->ArbolBinario != NULL)
    {
        return this->ArbolBinario->EmpiezaCrece;
    }
    else if(this->ArbolAvl != NULL)
    {
        return this->ArbolAvl->EmpiezaCrece;
    }
    else if(this->ArbolHeap != NULL)
    {
        return this->ArbolHeap->EmpiezaCrece;
    }
    else if(this->ArbolSplay != NULL)
    {
        return this->ArbolSplay->EmpiezaCrece;
    }
    else
    {
        return 0;
    }
}

bool HiloNodoFinca::hayPlagas()
{
    if(this->oveja != NULL)
    {
        return true;
    }
    else if(this->cuervo != NULL)
    {
        return true;
    }
    else if(this->Gusano != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HiloNodoFinca::hayArbol()
{
    if(this->ArbolHeap != NULL)
    {
        return true;
    }

    else if(this->ArbolAvl != NULL)
    {
        return true;
    }
    else if(this->ArbolBinario != NULL)
    {
        return true;
    }
    else if(this->ArbolSplay != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int HiloNodoFinca::calcularMontoTotalDeFrutos()
{
    if(this->ArbolHeap != NULL)
    {
        return ArbolHeap->precioDelArbolHeap(ArbolHeap->raizHeap);
    }

    else if(this->ArbolAvl != NULL)
    {
        return ArbolAvl->precioDelArbol();
    }
    else if(this->ArbolBinario != NULL)
    {
        if(this->ArbolBinario->raizAB != NULL)
        {
            return ArbolBinario->precioDelArbolBB(this->ArbolBinario->raizAB);
        }
    }
    else if(this->ArbolSplay != NULL)
    {
        return ArbolSplay->precioDelArbolSplay(this->ArbolSplay->raizSplay);
    }
    else
    {
        return 0;
    }

}
