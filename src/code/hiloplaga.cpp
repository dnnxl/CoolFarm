#include "hiloplagas.h"
#include <QtCore>

HiloPlaga::HiloPlaga(QObject *parent) :
    QThread(parent)
{
    this->Stop = false;
    this->bandera = false;
}


void HiloPlaga::asignarValores(ListaDatos*pLista)
{
    this->lista = pLista;
    NodoDato* datoOveja = pLista->buscarArbol("Oveja");
    this->oveja = new Oveja(datoOveja->comeFruto1,datoOveja->comeFruto2);

    int probabilidad = datoOveja->probabilidad;
    int minuto1 = datoOveja->minuto1;
    int minuto2 = datoOveja->minuto2;
    int fruto = datoOveja->comeFruto1;
    int tiempoFruto = datoOveja->comeFruto2;

    this->oveja->probabilidad = probabilidad;
    this->oveja->minuto1 = minuto1;
    this->oveja->minuto2 = minuto2;
    this->oveja->fruto = fruto;
    this->oveja->tiempoFruto = tiempoFruto;

    NodoDato* datoCuervo = pLista->buscarArbol("Cuervo");
    this->cuervo = new Cuervo(datoCuervo->comeFruto1,datoCuervo->comeFruto2);

    int probabilidadC = datoCuervo->probabilidad;
    int minuto1C = datoCuervo->minuto1;
    int minuto2C = datoCuervo->minuto2;
    int frutoC = datoCuervo->comeFruto1;
    int tiempoFrutoC = datoCuervo->comeFruto2;

    this->cuervo->probabilidad = probabilidadC;
    this->cuervo->minuto1 = minuto1C;
    this->cuervo->minuto2 = minuto2C;
    this->cuervo->fruto = frutoC;
    this->cuervo->tiempoFruto = tiempoFrutoC;


    NodoDato* datoGusano = pLista->buscarArbol("Gusano");
    this->plaga = new Plaga(datoGusano->destruye);

    int probabilidadg = datoGusano->probabilidad;


    this->plaga->probabilidad = probabilidadg;
    this->plaga->tiempo = datoGusano->destruye;
}

void HiloPlaga ::run()
{
    int i = 0;
    int iCuervo = 0;
    int iPlaga = 0;

    int segundosOveja = this->oveja->minuto2*60;
    int segundosCuervo = this->cuervo->minuto2*60;
    int segundosPlaga = 2*60;
    //---------------------------------- Dentro del while
    int probabilidadOveja = rand()%100;

    int probabilidadCuervo = rand()%100;

    int probabilidadGusano = rand()%100;

    while(true)
    {
        if(bandera == true)
        {

        }
        else if(Stop == true)
        {
            break;
        }

        else if(i == segundosOveja)
        {
            if(0< probabilidadOveja <this->oveja->probabilidad)
            {
                emit eeColocarPlaga(this->oveja->minuto1, 0);
                i = 0;
                probabilidadOveja = rand()%100;
                probabilidadCuervo = rand()%100;
                probabilidadGusano = rand()%100;

            }
            else
            {
                i=0;
                probabilidadOveja = rand()%100;

                probabilidadCuervo = rand()%100;

                probabilidadGusano = rand()%100;
            }
        }
        else if(iCuervo == segundosCuervo)
        {
            if((0< probabilidadCuervo) &&(probabilidadCuervo< this->cuervo->probabilidad))
            {
                emit eeColocarPlaga(this->cuervo->minuto1, 1);
                iCuervo = 0;
                probabilidadOveja = rand()%100;

                probabilidadCuervo = rand()%100;

                probabilidadGusano = rand()%100;

            }
            else
            {
                iCuervo =0;
                probabilidadOveja = rand()%100;

                probabilidadCuervo = rand()%100;

                probabilidadGusano = rand()%100;
            }
        }
        else if(iPlaga == segundosPlaga)
        {
            if(0<probabilidadGusano< plaga->probabilidad)
            {
                emit eeColocarPlaga(1, 2);
                iPlaga = 0;
                probabilidadOveja = rand()%100;

                probabilidadCuervo = rand()%100;

                probabilidadGusano = rand()%100;

            }
            else
            {
                iPlaga = 0;
                probabilidadOveja = rand()%100;

                probabilidadCuervo = rand()%100;

                probabilidadGusano = rand()%100;
            }
        }
        else
        {
            iPlaga++;
            i++;
            iCuervo++;
            probabilidadOveja = rand()%100;

            probabilidadCuervo = rand()%100;

            probabilidadGusano = rand()%100;
        }
    sleep(1);
  }

}
