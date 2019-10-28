#ifndef FINCA_H
#define FINCA_H

#include "hilonodofinca.h"
#include "estructuras.h"

class finca //: public QThread
{
    //Q_OBJECT

public:

    finca();
    HiloNodoFinca* myFinca [8][8];
    int tiempoMercado = 10;
    bool hayEspantapajaro; //true o false en caso de haber o no espantapajaros
    ListaDatos *lDatos; // Datos de los arboles en la configuración
    void createThreads(); //crea el hilo
    void imprimir(); //imprime

    void activarOveja(int x, int y); //activa la oveja en el hilo
    void activarCuervo(int x, int y); //activa el cuervo en el hilo
    void activarPlaga(int x, int y); //activa el gusano en el hilo
    void activarHilo(int x, int y); //activar el hilo
    void activarArbolOrdenado(int x, int y); //activa el arbol binario
    void activarArbolHeap(int x, int y); //activar el arbol heap
    void activarArbolAvl(int x, int y); //activar el arbol avl
    void activarArbolSplay(int x, int y); //activar el arbol splay
    void detenerHilos(int x, int y); //detener los hilos
    string ArbolPosicion(int x, int y);
    void eliminarFrutosVendidos(int x, int y, int cantidad); //se eliminan los frutos vendidos
    void PonerEspantapajaros(int x, int y); //se colocan los espantapajaros
    bool revisarEspantapajaros(int xPlaga, int yPlaga); //revisar espantapajaros
    bool hayPlaga(int x, int y); //true or false de si hay plaga o no
    ListNodoArbolMercado *ListaArbolesVender; //lista de los arboles vendidos
    void recogerDatosDeLosArboles(); //analizar los datos de todos los arboles
    bool hayArboles(HiloNodoFinca*hilo); //true or false de si hay o no arboles
    void espantarPlaga(int x, int y);
    void desactivarThreads();


public slots:
};

#endif // FINCA_H
