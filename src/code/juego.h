#ifndef JUEGO_H
#define JUEGO_H
#include <QWidget>
#include <QLabel>
#include "hiloplagas.h"
#include "hilocronometro.h"
#include "info.h"
#include "mercado.h"
#include "puntajes.h"
#include "estructuras.h"
#include "mercado.h"
#include "finca.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class HiloCronometro;
class finca;
class HiloPlaga;

namespace Ui
{
class Juego;
}

class Juego : public QWidget
{
    Q_OBJECT

public:
    Ui::Juego *ui;
    explicit Juego(QWidget *parent = 0);
    ~Juego();
    FileReader*reader;
    ListScores* scoreList; //Puntuaciones
    string name; // Nombre del juegdor
    int cantidadEspantapajaro = 0; //cantidad de espantapajaros se puede un maximo de dos en todo el juego
    int cantidadAvl; //cantidad de arboles avl
    int cantidadHeap; //cantidad de arboles heap
    int cantidadSplay; //cantidad de arboles Splay
    int cantidadOrdenado; //cantidad de arboles binarios
    void deletePlague(QLabel *pPlague); //eliminar plaga
    bool isPlague(int pXPlague, int pYPlague, int pXFarmer, int pYFarmer); // true or false en caso de ser plaga
    HiloCronometro *hCronometro; //hilo con el cronometro
    void setTextCronometro(int indice); //reset del cronometro
    void colocarArbolOrdenado(); //colocar arbol binario
    void colocarArbolSplay(); //colocar arbol Splay
    void colocarArbolHeap(); //colocar arbol heap
    void colocarArbolAvl(); //colocar arbol Avl
    void colocarEspantapajaros(); //colocar espantapajaros
    void espantarPlaga(int x, int y); //espantar plaga segun su posicion
    void eliminarPlagaPorPosicion(int x, int y); //eliminar plaga segun posicion(gusanos)
    bool revisarEspantapajaro(int x, int y); //revisar los espantapajaros
    void ponerNombreDinero(); //ponerle nombre al dinero(jugador)
    ListaDatos *lDatos; //puntero para tener acceso a los datos
    listaMercado *mercadoListaComprado; //cosas que se compraran en el merado
    ListNodoArbolMercado *ListaArbolesVender; //lista de arboles vendidos
    void insertarArbolesParaVender(); //insertar arboles para vender
    void adaptarArticulosComprados(); //los articulos que se han comprado
    int dinero; //Cantidad de dinero
    int cuantasPlagas(); //cuantas plagas se encuentan en el juego
    int cuantosArboles(); //cuantos arboles se encuentran en el juego
    void setTiempoCronometro();
    finca* Granja;
    HiloPlaga* hPlaga;
    void recorrerInterfaz();
    void asignarValues();


    void writerFileFinca(finca*pFinca);

    void writerFileConfiguracion(ListaDatos*pData);
    void colocarGuardadoOrdenado(int,int);
    void colocarGuardadoHeap(int,int);
    void colocarGuardadoSplay(int,int);
    void colocarGuardadoAvl(int,int);
    void colocarGuardado();


public slots:
    void enColocarPlaga(int,int);

private slots:
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void botonMercado();
    void on_bInsertarSplay_clicked();
    void on_bInsertarOrdenado_clicked();
    void on_bInsertarHeap_clicked();
    void on_bInsertarAvl_clicked();
    void on_bInsertarEspantapajaros_clicked();
    void on_botonMercado_clicked();
    void on_pushButton_2_clicked();

private:
    void keyPressEvent(QKeyEvent * event);
};

#endif // JUEGO_Hs
