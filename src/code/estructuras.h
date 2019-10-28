#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <QMutex>
//#include "finca.h"

using namespace std;

//class finca;

//--------------------------
// Nodo Arbol Binario
//--------------------------

struct nodoABB
{
   int costoFrutoBB; //Costo de cada fruto
   nodoABB *hijoDerBB; //hijo izquierdo
   nodoABB *hijoIzqBB; //hijo derecho
   nodoABB(int costoFBB)
   {
       costoFrutoBB = costoFBB; //costoF va a ser el costo del fruto
       hijoIzqBB = hijoDerBB = NULL; //inician en NULL
   }
};

//--------------------------
// Nodo Arbol Heap
//--------------------------

struct nodoHeap
{
   int costoFrutoHeap; //Costo de cada fruto
   nodoHeap *hijoDerHeap; //hijo izquierdo
   nodoHeap *hijoIzqHeap; //hijo derecho
   nodoHeap(float costoFHeap)
   {
       costoFrutoHeap = costoFHeap; //costoF va a ser el costo del fruto
       hijoIzqHeap = hijoDerHeap = NULL; //inician en NULL
   }
};

//--------------------------
// Nodo Arbol Avl
//--------------------------

struct nodoAVL
{
   int costoFrutoAVL; //Costo de cada fruto
   int equilibrioAVL; //Factor de equilibrio
   nodoAVL *hijoDerAVL; //hijo izquierdo
   nodoAVL *hijoIzqAVL; //hijo derecho
   nodoAVL(int costoFAVL)
   {
        equilibrioAVL = 0;
        costoFrutoAVL = costoFAVL; //costoF va a ser el costo del fruto
        hijoIzqAVL = hijoDerAVL = NULL; //inician en NULL
   }
    nodoAVL()
    {
        hijoIzqAVL = hijoDerAVL = NULL;
    }
};

//--------------------------
// Nodo Arbol Splay
//--------------------------

struct nodoSplay
{
    int keySplay; //int key
    int costoFrutoSplay;
    nodoSplay *raizSplay2;
    nodoSplay *hijoDerSplay; //hijo izquierdo
    nodoSplay *hijoIzqSplay; //hijo derecho
    int equilibrioSplay;
    nodoSplay(int costoFSplay, int key)
    {
        equilibrioSplay = 0;
        keySplay = key;
        costoFrutoSplay = costoFSplay; //costoF va a ser el costo del fruto
        hijoIzqSplay = hijoDerSplay = NULL; //inician en NULL
    }
    nodoSplay(int costoFSplay)
    {
        costoFrutoSplay = costoFSplay; //costoF va a ser el costo del fruto
        hijoIzqSplay = hijoDerSplay = NULL;
    }
};

//----------------------------
// Arbol Binario Ordenado
//----------------------------

struct arbolBB
{
    //--------------------------DATOS--------------------------
    int frutosPerdidos; //cantidd de frutos que se han perdido
    int EmpiezaCrece; //la velocidad que va a tener
    int tiempoCosecha;//modificable
    int cantidadCosecha; //csntidad de frutos que va a dar
    int precioUno; //precio numero uno
    int precioDos; //precio numero dos
    int vendidos; //cantidad de frutos vendidos
    float ubicacion; //ubicacion del arbol
    //--------------------------DATOS--------------------------
    nodoABB *raizAB; //nodo raiz del arbol
    arbolBB() //inicializacion de los datos
    {
        frutosPerdidos = 0;
        raizAB = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    arbolBB(int pEmpiezaCrecer, int pTiempoCosecha, int pCantidadCosecha, int pPrecio1, int pPrecio2)
    { //inicializacion de los datos
        EmpiezaCrece = pEmpiezaCrecer;
        tiempoCosecha = pTiempoCosecha;
        cantidadCosecha = pCantidadCosecha;
        precioUno = pPrecio1;
        precioDos = pPrecio2;
        frutosPerdidos = 0;
        raizAB = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    void insertarFrutoBBAux(int); //insertar frutos
    nodoABB *insertarFrutoBB(int pValor, nodoABB*); //insertar fruto mediante nodo
    int cantidadFrutosBB(nodoABB*); //cantidad de frutos
    int precioDelArbolBB(nodoABB*); //precio de todo el arbol
    nodoABB *borrarFrutoBB(int, nodoABB*); //borrar fruto del arbol
    int borrarRaiz(int pCantidadBB); //borrar desde la raiz
    nodoABB *mayorBB(nodoABB*); //Saca el mayor de los menores
    void agregar(int cantidadCosecha); //aregar mediante int
};

//----------------------------
// Arbol Binario Heap
//----------------------------

struct arbolHeap
{
    int frutosPerdidos; //cantidad de frutos perdidos
    int EmpiezaCrece; //la velocidad que va a tener
    int tiempoCosecha;//modificable
    int cantidadCosecha; //cantidad de la cosecha
    int precioUno; //precio del numero uno
    int precioDos; //precio numero dos
    int ubicacion; //ubicacion del arbol
    int vendidos; //cantidad de fruto vendidos
    nodoHeap *raizHeap; //raiz del arbol heap
    arbolHeap(int pEmpiezaCrecer, int pTiempoCosecha, int pCantidadCosecha, int pPrecio1, int pPrecio2)
    { //inicializacion de los datos
        EmpiezaCrece = pEmpiezaCrecer;
        tiempoCosecha = pTiempoCosecha;
        cantidadCosecha = pCantidadCosecha;
        precioUno = pPrecio1;
        precioDos = pPrecio2;
        frutosPerdidos = 0;
        raizHeap = NULL;
        ubicacion = 0;
        vendidos = 0;
    }

    arbolHeap()
    { //inicializacion de datos
        frutosPerdidos = 0;
        raizHeap = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    void insertarFrutoHeapAux(int); //insertar fruto
    nodoHeap *insertarFrutoHeap(int, nodoHeap*); //insertar mediante nodo
    int cantidadFrutosHeap(nodoHeap*); //cantidad de frutos
    int precioDelArbolHeap(nodoHeap*); //precio del arbol
    nodoHeap *borrarFrutoHeap(int, nodoHeap*); //borrar un fruto
    int borrarRaiz(int pCantidadHeap); //borrar desde la raiz
    nodoHeap *mayorHeap(nodoHeap*); //mayor de los menores
    void agregar(int cantidadCosecha); //agregar la cantidad de la cosecha

};

//--------------------------
// Arbol Avl
//--------------------------

struct arbolAVL
{
    int frutosPerdidos; //frutos que se han perdido
    int EmpiezaCrece; //la velocidad que va a tener
    int tiempoCosecha;//modificable
    int cantidadCosecha; //cnatidad de la cosecha
    int precioUno; //precio del uno
    int precioDos; //precio del dos
    int ubicacion; //ubicacion del arbol AVL
    int vendidos; //cantidad de frutos vendidos
    nodoAVL *raizAVL; //nodo raiz del arbol AVL
    arbolAVL(int pEmpiezaCrecer, int pTiempoCosecha, int pCantidadCosecha, int pPrecio1, int pPrecio2)
    { //inicializacion de los parametros
        EmpiezaCrece = pEmpiezaCrecer;
        tiempoCosecha = pTiempoCosecha;
        cantidadCosecha = pCantidadCosecha;
        precioUno = pPrecio1;
        precioDos = pPrecio2;
        frutosPerdidos = 0;
        raizAVL = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    arbolAVL()
    { //inicializacion de los parametros
        frutosPerdidos = 0;
        raizAVL = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    //Las funciones con AVL hacen referencia a los arboles AVL
    nodoAVL *rSimpleIAVL(nodoAVL*, nodoAVL*);
    nodoAVL *rDobleIAVL(nodoAVL*, nodoAVL*);
    nodoAVL *rSimpleDAVL(nodoAVL*, nodoAVL*);
    nodoAVL *rDobleDAVL(nodoAVL*, nodoAVL*);
    int alturaAVL(nodoAVL*);//calcular la altura del arbol
    int mayorAVL(int, int);//calcula el mayor de los numeros que recive como parametro
    nodoAVL *balancearArbolAVL(nodoAVL *nActualAVL);
    void insertarFrutoAVLAux(int);
    nodoAVL *insertarFrutoAVL(int, nodoAVL*);
    int cantidadFrutosAVL(nodoAVL*);
    int precioDelArbolAVL(nodoAVL*);
    nodoAVL *borrarFrutoAVL(int, nodoAVL*);
    int borrarRaizAVL(int pCantidadAVL);
    nodoAVL *borrarFrutoAuxAVL(int);
    nodoAVL *mayorAVL(nodoAVL*);
    void mostrarArbolAVL();
    void imprimirArbolAVL(nodoAVL*, int);
    void agregar(int cantidadCosecha);
    int precioDelArbol();
};

//-----------------------------------
// Arbol Splay
//-----------------------------------

struct arbolSplay
{
    int frutosPerdidos; //frutos perdidos
    int EmpiezaCrece; //la velocidad que va a tener
    int tiempoCosecha;//modificable
    int cantidadCosecha; //cantidad de cosecha
    int precioUno; //precio del uno
    int precioDos; //precio del dos
    int ubicacion; //ubicacion del arbol
    int vendidos; //cantidad de vendidos
    nodoSplay *raizSplay; //nodo raiz del arbol splay
    arbolSplay(int pEmpiezaCrecer, int pTiempoCosecha, int pCantidadCosecha, int pPrecio1, int pPrecio2)
    { //inicializacion de parametros
        EmpiezaCrece = pEmpiezaCrecer;
        tiempoCosecha = pTiempoCosecha;
        cantidadCosecha = pCantidadCosecha;
        precioUno = pPrecio1;
        precioDos = pPrecio2;
        frutosPerdidos = 0;
        raizSplay = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    arbolSplay()
    { //inicialiacion de parametros
        frutosPerdidos = 0;
        raizSplay = NULL;
        ubicacion = 0;
        vendidos = 0;
    }
    //Las funciones con Splay hacen referencia a los arboles Splay
    nodoSplay *rSimpleISplay(nodoSplay*, nodoSplay*);
    nodoSplay *rDobleISplay(nodoSplay*, nodoSplay*);
    nodoSplay *rSimpleDSplay(nodoSplay*, nodoSplay*);
    nodoSplay *rDobleDSplay(nodoSplay*, nodoSplay*);
    int alturaSplay(nodoSplay*);//calcular la altura del arbol
    int mayorSplay(int, int);//calcula el mayor de los numeros que recive como parametro
    nodoSplay *balancearArbolSplay(nodoSplay *nActualSplay);
    void insertarFrutoSplayAux(int);
    nodoSplay *insertarFrutoSplay(int, nodoSplay*);
    int cantidadFrutosSplay(nodoSplay*);
    int precioDelArbolSplay(nodoSplay*);
    nodoSplay* borrarFrutoSplay(int, nodoSplay*);
    int borrarRaizSplay(int pCantidadSplay);
    nodoSplay *mayorSplay(nodoSplay*);
    nodoSplay *borrarFrutoAuxSplay(int);
    void mostrarArbolSplay();
    void imprimirArbolSplay(nodoSplay*, int);

    void agregar(int cantidadVeces);
    int cantidadDeNodos();
};

//-------------------------------
// Plaga Gusano
//-------------------------------

struct Plaga
{
    int tiempoNoModificable; //tiempo que no se puede modificar
    int tiempo; //tiempo modificable
    int frutos; //frutos que se va a comer
    int probabilidad; //probabilidad de que aparezca
    //nodos para cada arbol
    arbolBB* ArbolBinario;
    arbolAVL* ArbolAvl;
    arbolHeap* ArbolHeap;
    arbolSplay* ArbolSplay;

    Plaga(int pTiempo)
    { //inicializacion de los parametros
        tiempo = tiempoNoModificable = pTiempo;
        frutos = 0;
    }
    //funciones de la plaga(gusano)
    void eliminarRaiz(int segundos,int segundosTotal, arbolBB*arbol);
    void eliminarRaizSplay(int segundos,int segundosTotal, arbolSplay* ArbolSplay);
    void eliminarRaizHeap(int segundos,int segundosTotal, arbolHeap* ArbolHeap);
    void eliminarRaizAvl(int segundos,int segundosTotal, arbolAVL* ArbolAvl);
};

struct Cuervo
{
    int tiempoNoModificable; //tiempo no modificable
    int probabilidad; //probabilidad de aparicion del cuervo
    int minuto1; //minuto uno
    int minuto2; //minuto dos
    int fruto; //cantidad de frutos que se come
    int tiempoFruto; //tiempo por cada fruto
    //nodos para utilizar con cualqier arbol
    arbolBB* ArbolBinario;
    arbolAVL* ArbolAvl;
    arbolHeap* ArbolHeap;
    arbolSplay* ArbolSplay;

    Cuervo(int pTiempo, int pFrutos)
    { //inicializacion de parametros
        tiempoFruto = tiempoNoModificable = pTiempo;
        fruto = pFrutos;
    }
    //funciones de la plaga cuervo
    void eliminarRaiz(int veces, arbolBB* ArbolBinario);
    void eliminarRaizSplay(int veces, arbolAVL* ArbolAvl);
    void eliminarRaizHeap(int veces, arbolHeap* ArbolHeap);
    void eliminarRaizAvl(int veces, arbolSplay* ArbolSplay);
};

struct Oveja
{
    int tiempoNoModificable; //tiempo no modificable
    int probabilidad; //probabilidad de aparicion
    int minuto1; //minuto uno
    int minuto2; //minuto dos
    int fruto; //cantidad de frutos a comer
    int tiempoFruto; //tiempo en comer los frutos
    //nodos para cada tipo de arbol
    arbolBB* ArbolBinario;
    arbolAVL* ArbolAvl;
    arbolHeap* ArbolHeap;
    arbolSplay* ArbolSplay;

    Oveja(int pTiempo, int pFrutos)
    { //inicializacion de parametros
        tiempoFruto = tiempoNoModificable = pTiempo;
        fruto = pFrutos;
    }
    //funciones de la plaga oveja
    void eliminarRaiz(int veces, arbolBB* ArbolBinario);
    void eliminarRaizSplay(int veces, arbolAVL* ArbolAvl);
    void eliminarRaizHeap(int veces, arbolHeap* ArbolHeap);
    void eliminarRaizAvl(int veces, arbolSplay* ArbolSplay);
};

//-----------------------------
// Lista Simple Vender Arboles
//-----------------------------

struct NodoArbolMercado
{
    string nombre; //nombre del mercado
    float ubicacion; //ubicacion donde se esta posicionado
    int cantFrutos; //cantidad de frutos ue hay
    float montoTotal; //monto total de los frutos
    int vendidos; //cantidad de frutos vendidos
    int perdidos; //cantidad de frutos perdidos(plagas)
    NodoArbolMercado *siguiente;

    NodoArbolMercado(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos)
    {
        nombre = pNombre; //nombre del mercado
        ubicacion = pUbicacion; //ubicacion en la matriz
        cantFrutos = pCantFrutos; //cantidad de frutos que hay
        montoTotal = pMonto; //monto total de lso frutos que hay
        vendidos = pVendidos; //cantidad de frutos vendidos
        perdidos = pPerdidos; //cantidad de frutos perdidos(plagas)
        siguiente = NULL;
    }

    NodoArbolMercado(string pNombre)
    {
        nombre = pNombre;
        siguiente = NULL;
    }

    void imprimir()
    {
        cout<<nombre<< " ";
        cout<<ubicacion<< " ";
        cout<<cantFrutos<< " ";
        cout<<montoTotal<< " ";
        cout<<vendidos<< " ";
        cout<<perdidos<< " ";

    }
};

struct ListNodoArbolMercado
{
    NodoArbolMercado *primerNodo; //puntero primer nodo
    NodoArbolMercado *ultimoNodo; //puntero al ultimo nodo

    ListNodoArbolMercado()
    {
        primerNodo = ultimoNodo = NULL;
    }

    NodoArbolMercado *borrarAlInicio(void); //borra al inicio de la lista
    NodoArbolMercado *insertarAlFinal(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos); //inserta al final de la lista
    NodoArbolMercado *borrarAlFinal(void); //elimina al final de la lista
    bool vacia(); //vacia toda la lista
    int largo(); //determina el largo de la lista
    NodoArbolMercado *insertarAlInicio (string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos); //inserta al inicio de la lista
    void imprimir(); //imprime por consola los datos
    NodoArbolMercado *insertarEnPosicion(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos, int pos); //inserta en determinada posicion de la lista
    NodoArbolMercado *insertarOrdenado(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos); //inserta ordenadamente
    NodoArbolMercado *buscarArbol(float pUbicacion); //busca el arbol segun la ubicacion
    float calcularDinero(float pUbicacion, float pDineroActual); //calcula la cantidad de dinero
    void venderFrutos(float pUbicacion); //vende los frutos de un arbol segun ubicacion
    float calcularDineroTodoVendido(float pDineroActual); //calcula eldinero total de todo los arboles vendidos
    void venderFrutosTodos(); //vender todos los frutos
};



//---------------------------
// Lista Simple Puntuación
//---------------------------

struct nodoPts
{
    string nombrePuntos; //nombre del jugador
    int dineroPuntos; //dinero que se ha generado
    nodoPts *siguientePts;
    nodoPts(string nombre, int dinero)
    {
        nombrePuntos = nombre;
        dineroPuntos = dinero;
        siguientePts = NULL;
    }
};

struct ListScores
{
    nodoPts *primerPts;
    nodoPts *ultimoPts;
    ListScores()
    {
        primerPts = ultimoPts = NULL;
    }
    nodoPts *borrarAlInicio(void); //elimina al inicio
    nodoPts *insertarAlFinal(string nombrePuntos, int dineroPuntos); //inserta al final
    nodoPts *borrarAlFinal(void); //borra al final
    bool vacia(); //vaia la lista
    int largo(); //determina el largo de la lista
    nodoPts *insertarAlInicio(int dineroPuntos, string nombrePuntos); //inserta al inicio de la lista
    void imprimir(); //imprime la lsita simple
    nodoPts *insertarEnPosicion(string nombrePuntos, int dineroPuntos,int pos); //inserta en determinada posicion
    nodoPts *insertarOrdenado(string nombrePuntos, int dineroPuntos); //inserta ordenadamente
};

//---------------------------
// Lista Simple Mercado
//---------------------------

struct Nodo
{
    string nombreMercado; //nombre del mercado
    int precioMercado; //precio de que este tiene
    Nodo *siguiente;
    int cantidad; //cantidad
    Nodo(string p, int pp)
    {
        nombreMercado = p;
        precioMercado = pp; //precio mercado
        siguiente = NULL;
    }
    Nodo(int pCantidad,string nombre)
    {
        nombreMercado = nombre;
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

struct listaMercado
{
    Nodo *primerNodo;
    Nodo *ultimoNodo;
    listaMercado()
    {
        primerNodo = ultimoNodo = NULL;
    }

    void insertarAlInicioArticuloComprado(int cantidad, string nombreMercado); //inserta el articulo que se compro al inicio
    bool esta(string name); //determina si el nombre ya se encuentra o no
    void insertarAlInicio(string nombreMercado, int precioMercado); //inserta al inicio de la lista
    void imprimir(); //imprime la lista
    Nodo *borrarAlInicio(void); //borra al inicio de la lista
    void insertarAlFinal(string nombreMercado, int precioMercado); //inserta al final de la lista
    Nodo *borrarAlFinal(void); //borra al final de la lista
    int largo(void); //determina el largo de la lista
    int largoRec (void); //largo del recorrido
    int largo_aux(Nodo*); //funcion auxiliar para determinar el largo
    void insertarAlFinalConRecorrido(int dato); //inserta al final del recorrido
    bool vacia(void); //vaciar la lista
    void insertarEnPosicion(int dato, int pos); //insertar en una determinada posicion
    void borrarEnPosicion(int pos); //borrar en una posicion especifica
    Nodo *buscar(string nombre); //busca segun el nombre dado
};


//--------------------------
// File Reader
//--------------------------

struct FileReader
{
    ListScores *scoreList; //puntero de la puntuacion
    FileReader()
    {
        scoreList = NULL;
    }
    void writerFile(ListScores *pList); //escribe en el archivo
    ListScores *readFile(); //lee el archivo
    //void writerGameFile(finca *matriz); //escribe en el archivo la matriz
    //finca *readGameFile(); //lee el juego una vez guardado
    //void writeMatrizGame(finca *pGame); //escribe la matriz del juego
    //finca *readMatriz(finca *pGame); //lee la matriz del juego

};

//----------------------------
// Lista de datos
//----------------------------

struct NodoDato
{
    string nombre; //nombre del articulo(arbol)
    int crece; //cuanto dura creciendo
    int cosecha; //cosecha del arbol
    int tiempoCosecha; //tiempo que dura dando frutos
    int precio1; //variable uno del precio
    int precio2; //variable dos del precio
    NodoDato *siguiente; //puntero a siguiente
    int probabilidad; //probabilidad
    int minuto1; //variable uno de minutos
    int minuto2; //variable dos de minutos
    int comeFruto1; //variable uno del costo del fruto
    int comeFruto2; //variable dos del costo del fruto
    int destruye; //destruye el arbol en determinado tiempo
    string myName; //nombre
    int Abre; //tiempo que dura en abrir el mercado
    int Vender; //tiempo para vender en el mercado

    NodoDato(string pNombre)
    {
        siguiente = NULL;
        nombre = "Nombre";
        myName = pNombre;
    }

// NodoDato del arbol
    NodoDato(string pNombre, int pCrece, int pCosecha, int pTiempoCosecha, int pPrecio1, int pPrecio2)
    {
        nombre = pNombre; //nombre del arbol
        crece = pCrece; //tiempo en el que termina de sembrarse
        cosecha = pCosecha; //cosecha del arbol
        precio1 = pPrecio1; //precio que va a tener el arbol
        precio2 = pPrecio2; //precio que va a tener el fruto
        tiempoCosecha = pTiempoCosecha; //cada cuanto tiempo da cosechas
        siguiente = NULL;
    }

    NodoDato(string pNombre,int pProbabilidad, int pMinuto1, int pMinuto2, int pComeFruto1, int pComeFruto2, int nada)
    {
        nombre = pNombre; //nombre de la plaga
        probabilidad = pProbabilidad; //probabilidad de que salga
        minuto1 = pMinuto1; //cada cuanto tiempo puede aparecer
        minuto2 = pMinuto2; //cada cuanto tiempo va a comer frutos
        comeFruto1 = pComeFruto1; //frutos que se puede comer
        comeFruto2 = pComeFruto2; //frutos segun tiempo
        siguiente = NULL;
    }

    NodoDato(string pNombre, int pDestruye, int pProbabilidad)
    {
        probabilidad = pProbabilidad; //probabilidad de los gusanos
        destruye = pDestruye; //tiempo que dura en destruir el arbol
        nombre = pNombre; //nombre de la plaga
        siguiente = NULL;
    }

    NodoDato(int pAbra, int pVenta)
    {
        Abre = pAbra; //cada cuanto abre
        Vender = pVenta; //cuanto tiempo se puede vender
        nombre = "Mercado";
        siguiente = NULL;
    }

    void imprimirArbol() //funciones para los arboles
    {
        cout<<nombre<<endl;
        cout<<crece<<endl;
        cout<<cosecha<<endl;
        cout<<tiempoCosecha<<endl;
        cout<<precio1<<endl;
        cout<<precio2<<endl;

    }

    void imprimirPlaga() //funciones para los cuervos y ovejas
    {
        cout<<nombre<<endl ;
        cout<<probabilidad<<endl ;
        cout<<minuto1<<endl ;
        cout<<minuto2<<endl ;
        cout<<comeFruto1<<endl ;
        cout<<comeFruto2<<endl ;
    }

    void imprimirGusano() //funciones para los gusanos
    {
        cout<<probabilidad<<endl;
        cout<<destruye<<endl;
        cout<<nombre<<endl;
    }
};

struct ListaDatos
{
    NodoDato *primerNodo;
    NodoDato *ultimoNodo;

    ListaDatos()
    {
        primerNodo = ultimoNodo = NULL;
    }

    bool vacia(); //vacia la lista
    int largo(); //determina el largo de la lista
    NodoDato *insertarAlInicio(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos); //inserta al inicio de la lista
    void imprimir(); //imprime la lista
    NodoDato *buscarArbol(string pNombre); //busca el arbol segun nombre
    NodoDato *insertarAlInicioArbol(string pNombre, int pCrece, int pCosecha, int pTiempoCosecha, int pPrecio1, int pPrecio2); //inserta arbol al inicio del arbol
    NodoDato *insertarAlInicioPlaga(string pNombre,int pProbabilidad, int pMinuto1, int pMinuto2, int pComeFruto1, int pComeFruto2); //inserta plaga al inicio
    NodoDato *insertarAlInicioGusano(string pNombre, int pDestruye, int pProbabilidad); //inserta gusano al inicio
    NodoDato *insertarAlInicioNombre(string pNombre); //inserta segun nombre al inicio
    NodoDato *insertarAlInicioMercado(int pAbra, int pVenta); //inserta mercado al inicio
};

#endif // ESTRUCTURAS_H
