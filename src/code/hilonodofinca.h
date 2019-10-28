#ifndef HILONODOFINCA_H
#define HILONODOFINCA_H

#include "estructuras.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <QMutex>
#include <QtCore>
#include <QDebug>

using namespace std;

class HiloNodoFinca : public QThread
{
public:
    HiloNodoFinca(); //hilo del inspector
    void run(); //Sacar botella y poner botella.
    QString identificador; //nobre que se le da
    bool Stop; //condicion para detener el hilo
    bool Pausa; //Este bandera es para resume y pausa.
    float posicion; //posicion en la que se encuentra
    bool hayPlagas();
    bool hayArbol();
    int calcularMontoTotalDeFrutos();
    int cantidadDeFrutosActuales();
    int calcularMontoTotalFrutosPerdidos();
    void darFrutos();// Agrega frutos a cualquier arbol.
    int ArbolTiempoCrecimiento(); // Tiempo del arbol para empezar a dar frutos.
    int tiempoParaDarFrutos(); // Devuelve el tiempo para dar frutos de un arbol.
    int cantidadDeFrutosPorTiempo();
    int cantidadDeFrutosPerdidos();
    int plagaComer(); //en esta función la plaga come y rebaja de la cantidad de frutos perdidos.
    void plagaDesaparecer();
    void PlagaCome();
    void anular();
    Oveja* oveja;
    Cuervo* cuervo;
    Plaga* Gusano;
    int globalTiempoPlaga;
    int globalTiempoGusano;
    arbolBB* ArbolBinario;
    arbolSplay* ArbolSplay;
    arbolHeap* ArbolHeap;
    arbolAVL* ArbolAvl;
    bool hayGusano();
    void espantar();
    void PlagaComeOrdenado(arbolBB*comida);
    int tiempoListoParaComer();

    bool globalGusano;
};
#endif // HILONODOFINCA_H
