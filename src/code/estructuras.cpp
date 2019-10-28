#include "estructuras.h"

//-----------------------------------------
// Funciones de listaSimple vender Arboles
//-----------------------------------------

float ListNodoArbolMercado::calcularDinero(float pUbicacion, float pDineroActual)
{
    NodoArbolMercado *tmp = buscarArbol(pUbicacion);
    return tmp->montoTotal + pDineroActual;
}

void ListNodoArbolMercado::venderFrutos(float pUbicacion)
{
    NodoArbolMercado *tmp = buscarArbol(pUbicacion); //nodo temporal igual a la funcion buscar arbol
    tmp->vendidos = tmp->vendidos + tmp->cantFrutos; //temporal vendidos = temporal vendidos mas la cantidad actual del arbol
    tmp->cantFrutos = 0;
    tmp->montoTotal = 0;
}

float ListNodoArbolMercado::calcularDineroTodoVendido(float pDineroActual) //calcula el total de dienro vendido
{
    NodoArbolMercado* tmp = primerNodo;
    float dineroTmp = 0;
    while (tmp != NULL) //mientras el nodo no sea nulo
    {
        dineroTmp = dineroTmp + tmp->montoTotal; //agregando el monto hacia el total
        tmp = tmp->siguiente;
    }
    return dineroTmp + pDineroActual;
}

void ListNodoArbolMercado::venderFrutosTodos() //vender todos los frutos de un arbol
{
    NodoArbolMercado* tmp = primerNodo;
    while (tmp != NULL)
    {
        tmp->vendidos = tmp->vendidos + tmp->cantFrutos;
        tmp->cantFrutos = 0;
        tmp->montoTotal = 0;
        tmp = tmp->siguiente;
    }
}

NodoArbolMercado *ListNodoArbolMercado::buscarArbol(float pUbicacion) //buscar el arbol dentro de la matriz
{
    NodoArbolMercado *tmp = primerNodo;
    while (tmp != NULL)
    {
        if (tmp->ubicacion == pUbicacion)
            return tmp;
        tmp = tmp->siguiente;
    }
    return NULL;
}

NodoArbolMercado * ListNodoArbolMercado::insertarAlInicio (string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos) //insertar al inicio
{
    if (primerNodo == NULL)
    {
        primerNodo = new NodoArbolMercado(pNombre, pUbicacion, pCantFrutos, pMonto, pVendidos, pPerdidos);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoArbolMercado *nuevo = new NodoArbolMercado(pNombre, pUbicacion, pCantFrutos, pMonto, pVendidos, pPerdidos);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}

void ListNodoArbolMercado::imprimir() //muestra por consola el mercado
{
    NodoArbolMercado *tmp = primerNodo;
    while (tmp != NULL)
    {
        tmp = tmp->siguiente;
    }
 }

NodoArbolMercado* ListNodoArbolMercado::borrarAlInicio(void) //borrar al inicio de la lista
{
      if (primerNodo == NULL)
      {
         return NULL;
      }
      else
      {
          NodoArbolMercado* borrado = primerNodo;
          primerNodo = primerNodo->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}

NodoArbolMercado *ListNodoArbolMercado::insertarAlFinal(string pNombre, float pUbicacion, int pCantFrutos, float pMonto, int pVendidos, int pPerdidos) //insertar al final de la lista
{
     if (primerNodo == NULL)
     {
         primerNodo = new NodoArbolMercado(pNombre, pUbicacion, pCantFrutos, pMonto, pVendidos, pPerdidos);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
         return primerNodo;
     }
     else
     {
         NodoArbolMercado *nuevo = new NodoArbolMercado(pNombre, pUbicacion, pCantFrutos, pMonto, pVendidos, pPerdidos);
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
         return nuevo;
     }
}

bool ListNodoArbolMercado::vacia() //si esta vacia
{
     if (primerNodo == NULL)
        return true;
     else
         return false;
}

int ListNodoArbolMercado::largo() //largo de la lista
{
    NodoArbolMercado*tmp = primerNodo;
    int cont = 0;
    while (tmp != NULL)
    {
        cont++;
        tmp = tmp->siguiente;

    }
    return cont;
}


NodoArbolMercado* ListNodoArbolMercado::borrarAlFinal(void) //borrar al final e la lista
{
    if (vacia())
        return NULL;
    else if (primerNodo->siguiente == NULL)
    {
        NodoArbolMercado* actual = primerNodo;
        primerNodo = ultimoNodo = NULL;
        return actual;
    }
    else
    {
        NodoArbolMercado* actual = primerNodo;
        while (actual->siguiente->siguiente != NULL)
          actual = actual->siguiente;
        NodoArbolMercado* tmp = ultimoNodo;
        ultimoNodo = actual;
        actual->siguiente = NULL;
        return tmp;
    }
}




//---------------------------------
// Funciones de listaSimple Mercado
//---------------------------------

Nodo *listaMercado::borrarAlInicio(void) //borrar al inicio de la lista
{
      if (primerNodo == NULL)
      {
         return NULL;
      }
      else
      {
          Nodo* borrado = primerNodo;
          primerNodo = primerNodo->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}

void listaMercado::insertarAlFinal (string nombreMercado, int precioMercado) //insertar al final de la lista
{
     if (primerNodo == NULL)
     {
         primerNodo = new Nodo(nombreMercado, precioMercado);
         ultimoNodo = primerNodo; // ambos apuntan al nuevo
     }
     else
     {
         Nodo *nuevo = new Nodo(nombreMercado, precioMercado);
         ultimoNodo->siguiente = nuevo;
         ultimoNodo = nuevo;
     }
}

bool listaMercado::vacia() //vaciar la listas
{
     if (primerNodo == NULL)
        return true;
     else
         return false;
}

int listaMercado::largo() //largo de la lista
{
    Nodo*tmp = primerNodo;
    int cont = 0;
    while (tmp != NULL)
    {
        cont++;
        tmp = tmp->siguiente;
    }
    return cont;
}


Nodo* listaMercado::borrarAlFinal(void) //borrar al final de la lista
{
    if (vacia())
        return NULL;
    else if (primerNodo->siguiente == NULL)
    {
        Nodo* actual = primerNodo;
        primerNodo = ultimoNodo = NULL;
        return actual;
    }
    else
    {
        Nodo* actual = primerNodo;
        while (actual->siguiente->siguiente != NULL)
          actual = actual->siguiente;
        Nodo* tmp = ultimoNodo;
        ultimoNodo = actual;
        actual->siguiente = NULL;
        return tmp;
    }
}

void listaMercado::insertarAlInicioArticuloComprado(int cantidad, string nombreMercado) //insertar el articulo que se haya comprado
{
    if (primerNodo == NULL)
    {
        primerNodo = new Nodo(cantidad,nombreMercado);
        ultimoNodo = primerNodo;
    }
    else if(esta(nombreMercado))
    {
        Nodo *tmp = primerNodo;
        while (tmp != NULL)
        {
            if(tmp->nombreMercado == nombreMercado)
            {
                tmp->cantidad = tmp->cantidad + cantidad;
                tmp = tmp->siguiente;
            }
            else
            {
                tmp = tmp->siguiente;
            }
        }
    }
    else
    {
        Nodo *nuevo = new Nodo(cantidad,nombreMercado);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

bool listaMercado::esta(string name) //determina si ya se encuentra o no en la lista
{
    Nodo *tmp = primerNodo;
    while (tmp != NULL)
    {
        if(tmp->nombreMercado == name)
        {
            return true;
        }
        else
        {
            tmp = tmp->siguiente;
        }
    }
    return false;
}

Nodo *listaMercado::buscar(string nombre) //buscar dentro de la lista
{
    Nodo *tmp = primerNodo;
    while (tmp != NULL)
    {
        if(tmp->nombreMercado == nombre)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->siguiente;
        }
    }
    return NULL;
}


void listaMercado::insertarAlInicio (string nombreMercado, int precioMercado) //insertar al inicio de la lista
{
    if (primerNodo == NULL)
    {
        primerNodo = new Nodo(nombreMercado, precioMercado);
        ultimoNodo = primerNodo;
    }
    else
    {
        Nodo *nuevo = new Nodo(nombreMercado, precioMercado);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void listaMercado::imprimir() //imprimir la lista
{
    Nodo *tmp = primerNodo;
    while (tmp != NULL)
    {
        tmp = tmp->siguiente;
    }
}

//--------------------------
// Funciones de ListScores
//--------------------------

nodoPts * ListScores::insertarAlInicio (int dineroPuntos, string nombrePuntos) //insertar al inicio de la lista
{
    if (primerPts == NULL)
    {
        primerPts = new nodoPts(nombrePuntos, dineroPuntos);
        ultimoPts = primerPts;
        return primerPts;
    }
    else
    {
        nodoPts *nuevo = new nodoPts(nombrePuntos, dineroPuntos);
        nuevo->siguientePts = primerPts;
        primerPts = nuevo;
        return nuevo;
    }
}

void ListScores::imprimir() //imprimir la lista
{
    nodoPts *tmp = primerPts;
    while (tmp != NULL)
    {
        tmp = tmp->siguientePts;
    }
}

nodoPts* ListScores::borrarAlInicio(void) //borrar al inicio de la lista
{
      if (primerPts == NULL)
      {
         return NULL;
      }
      else
      {
          nodoPts* borrado = primerPts;
          primerPts = primerPts->siguientePts;
          borrado->siguientePts = NULL;
          return borrado;
      }
}

nodoPts *ListScores::insertarAlFinal(string nombrePuntos, int dineroPuntos) //insertar al final de la lista
{
     if (primerPts == NULL)
     {
         primerPts = new nodoPts( nombrePuntos,  dineroPuntos);
         ultimoPts = primerPts; // ambos apuntan al nuevo
         return primerPts;
     }
     else
     {
         nodoPts *nuevo = new nodoPts( nombrePuntos,  dineroPuntos);
         ultimoPts->siguientePts = nuevo;
         ultimoPts = nuevo;
         return nuevo;
     }
}

bool ListScores::vacia() //vaciar la lista
{
     if (primerPts == NULL)
        return true;
     else
         return false;
}

int ListScores::largo() //largo de la lista
{
    nodoPts*tmp = primerPts;

    int cont = 0;
    while (tmp != NULL)
    {
        cont++;
        tmp = tmp->siguientePts;

    }
    return cont;
}


nodoPts* ListScores::borrarAlFinal(void) //borrar al final de la lista
{
    if (vacia())
        return NULL;
    else if (primerPts->siguientePts == NULL)
    {
        nodoPts* actual = primerPts;
        primerPts = ultimoPts = NULL;
        return actual;
    }
    else
    {
        nodoPts* actual = primerPts;
        while (actual->siguientePts->siguientePts != NULL)
          actual = actual->siguientePts;
        nodoPts* tmp = ultimoPts;
        ultimoPts = actual;
        actual->siguientePts = NULL;
        return tmp;
    }
}

nodoPts*  ListScores::insertarEnPosicion(string nombrePuntos, int dineroPuntos,int pos) //insertar en la posicion que se le indique
{
     if (vacia() || pos == 0)
     {
        nodoPts* nodolista = insertarAlInicio(dineroPuntos,nombrePuntos);
        return nodolista;
     }
     else
     {
         nodoPts* actual = primerPts;
         for (int i=1; i < pos && actual->siguientePts != NULL;i++)
             actual=actual->siguientePts;
         if (actual->siguientePts == NULL)
         {
            nodoPts* nodolista = insertarAlFinal(nombrePuntos, dineroPuntos);
            return nodolista;
         }
         else
         {
            nodoPts* nuevo = new nodoPts(nombrePuntos, dineroPuntos);
            nuevo->siguientePts = actual->siguientePts;
            actual->siguientePts=nuevo;
            return nuevo;
         }
     }
}

nodoPts* ListScores::insertarOrdenado(string nombrePuntos, int dineroPuntos) //insertar de forma ordenada
{
    if(vacia() == true)
    {
        nodoPts*nodito = insertarAlInicio(dineroPuntos,nombrePuntos);
        return nodito;
    }
    else if (largo() == 1)
    {
        if(primerPts->dineroPuntos> dineroPuntos)
        {
            nodoPts*nodito = insertarAlFinal(nombrePuntos,dineroPuntos);
            return nodito;
        }
        else
        {
            nodoPts*nodito = insertarAlInicio(dineroPuntos,nombrePuntos);
            return nodito;
        }
    }
    else
    {
        nodoPts* actual = primerPts;
        int cont = 0;
        while(dineroPuntos < actual->dineroPuntos && actual != NULL)
        {
            actual = actual->siguientePts;
            cont++;
        }
        nodoPts* nodolista = insertarEnPosicion(nombrePuntos,dineroPuntos,cont);
        return nodolista;
    }
}

//------------------------------
// FileReader Struct
//------------------------------

void FileReader::writerFile(ListScores*pList) //escribe el archivo
{
    ofstream fsalida("C:/Users/dnnxl/Desktop/Puntuaciones.dat", ios::out | ios::binary);
    fsalida.write(reinterpret_cast<char *>(&pList),sizeof(ListScores));
    fsalida.close();
}

ListScores* FileReader::readFile() //lee el archivo
{
    ListScores*tmp;
    ifstream fentrada("C:/Users/dnnxl/Desktop/Puntuaciones.dat",ios::in | ios::binary);
    fentrada.read(reinterpret_cast<char *>(&tmp), sizeof(ListScores));
    fentrada.close();
    if(tmp->primerPts == NULL)
    {
        ListScores*tmpp = new ListScores();
        return tmpp;
    }
    else
        return tmp;
}


//------------------------------
// Lista Datos
//------------------------------

NodoDato *ListaDatos::buscarArbol(string pNombre) //buscar el arbol
{
    NodoDato *tmp = primerNodo;
    while (tmp != NULL)
    {
        if (tmp->nombre == pNombre)
            return tmp;
        tmp = tmp->siguiente;
    }
    return NULL;
}

NodoDato * ListaDatos::insertarAlInicioPlaga (string pNombre,int pProbabilidad, int pMinuto1, int pMinuto2, int pComeFruto1, int pComeFruto2) //insertar la plaga al inicio
{
    if (primerNodo == NULL)
    {
        primerNodo = new NodoDato(pNombre, pProbabilidad, pMinuto1, pMinuto2, pComeFruto1, pComeFruto2,0);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoDato *nuevo = new NodoDato(pNombre, pProbabilidad, pMinuto1, pMinuto2, pComeFruto1, pComeFruto2,0);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}


NodoDato *ListaDatos::insertarAlInicioArbol (string pNombre, int pCrece, int pCosecha, int pTiempoCosecha, int pPrecio1, int pPrecio2) //insertar al inicio del arbol
{
    if (primerNodo == NULL)
    {
        primerNodo = new NodoDato(pNombre, pCrece, pCosecha, pTiempoCosecha, pPrecio1, pPrecio2);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoDato *nuevo = new NodoDato(pNombre, pCrece, pCosecha, pTiempoCosecha, pPrecio1, pPrecio2);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}

NodoDato * ListaDatos::insertarAlInicioGusano(string pNombre, int pDestruye, int pProbabilidad) //insetar el gusano al inicio
{
    if (primerNodo == NULL)
    {
        primerNodo = new  NodoDato(pNombre, pDestruye, pProbabilidad);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoDato *nuevo = new NodoDato(pNombre, pDestruye, pProbabilidad);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}

NodoDato *ListaDatos::insertarAlInicioNombre(string pNombre) //insertar al inicio segun nombre
{
    if (primerNodo == NULL)
    {
        primerNodo = new  NodoDato(pNombre);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoDato *nuevo = new NodoDato(pNombre);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}

NodoDato *ListaDatos::insertarAlInicioMercado(int pAbra, int pVenta) //insertar al inicio del mercado
{
    if (primerNodo == NULL)
    {
        primerNodo = new  NodoDato(pAbra, pVenta);
        ultimoNodo = primerNodo;
        return primerNodo;
    }
    else
    {
        NodoDato *nuevo = new NodoDato(pAbra, pVenta);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
        return nuevo;
    }
}

void ListaDatos::imprimir() //imprimirlo
{
    NodoDato *tmp = primerNodo;
    while (tmp != NULL)
    {
        tmp = tmp->siguiente;
    }
}


int ListaDatos::largo() //largo de la lista
{
    NodoDato*tmp = primerNodo;
    int cont = 0;
    while (tmp != NULL)
    {
        cont++;
        tmp = tmp->siguiente;

    }
    return cont;
}

//----------------------------
// Árbol Binario de busqueda
//----------------------------

//--------------------------------------------
int arbolBB::borrarRaiz(int pCantidadBB) //borrar raiz
{
    if(raizAB == NULL)
    {
        return NULL;
    }
    else
    {
        int cont = 0;
        while(pCantidadBB != cont)
        {
            if(raizAB == NULL || cantidadFrutosBB(raizAB) == 1)
            {
                return cont;
            }
            else
            {
                int precioBB = raizAB->costoFrutoBB;
                borrarFrutoBB(precioBB, raizAB);
                cont++;
            }
        }
        return cont;
    }
}

//--------------------------------------------

void arbolBB::insertarFrutoBBAux(int pValor) //insertar el fruto
{
    raizAB = insertarFrutoBB(pValor, raizAB);
}

//--------------------------------------------

nodoABB *arbolBB::insertarFrutoBB(int pValor, nodoABB *raizBB) //funcion auxiliar para insertar
{
    if(raizBB == NULL)
    {
        return new nodoABB(pValor);
    }
    else if(raizBB->costoFrutoBB < pValor)
    {
        raizBB->hijoDerBB = insertarFrutoBB(pValor, raizBB->hijoDerBB);
    }
    else if(raizBB->costoFrutoBB >= pValor)
    {
        raizBB->hijoIzqBB = insertarFrutoBB(pValor, raizBB->hijoIzqBB);
    }
    return raizBB;
}

int arbolBB::cantidadFrutosBB(nodoABB *raizBB) //cantidad de frutos
{
    QMutex* mutex = new QMutex();
    mutex->lock();
     if(raizBB == NULL)
     {
         mutex->unlock();
         return 0;
     }
     else
     {
        mutex->unlock();
        return 1 + cantidadFrutosBB(raizBB->hijoDerBB) + cantidadFrutosBB(raizBB->hijoIzqBB);
     }
}

int arbolBB::precioDelArbolBB(nodoABB *raizBB) //precio de todo el arbol
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    if(raizBB == NULL)
    {
        mutex->unlock();
        return 0;
    }
    else
    {
        mutex->unlock();
        return raizBB->costoFrutoBB + raizBB->costoFrutoBB + cantidadFrutosBB(raizBB->hijoDerBB) + cantidadFrutosBB(raizBB->hijoIzqBB);
    }
}

nodoABB *arbolBB::borrarFrutoBB(int costoFBB, nodoABB *raizBB) //borrar un fruto
{
    if(raizBB == NULL)
    {
        return NULL;
    }
    else if(costoFBB < raizBB->costoFrutoBB)
        raizBB->hijoIzqBB = borrarFrutoBB(costoFBB, raizBB->hijoIzqBB);
    else if(costoFBB > raizBB->costoFrutoBB)
        raizBB->hijoDerBB = borrarFrutoBB(costoFBB, raizBB->hijoDerBB);
    else if(raizBB->hijoIzqBB == NULL && raizBB->hijoDerBB == NULL)
        raizBB = NULL;
    else if(raizBB->hijoIzqBB == NULL)
        raizBB = raizBB->hijoDerBB;
    else if(raizBB->hijoDerBB == NULL)
        raizBB = raizBB->hijoIzqBB;
    else
    {
        nodoABB *maxBB = mayorBB(raizBB->hijoIzqBB); // mayor de los menores
        raizBB->hijoIzqBB = borrarFrutoBB(maxBB->costoFrutoBB, raizBB->hijoIzqBB);
        raizBB->costoFrutoBB = maxBB->costoFrutoBB;
    }
    return raizBB;
}

nodoABB *arbolBB::mayorBB(nodoABB *raizBB) //mayor de los menores para borrar fruto
{
    if(raizBB == NULL)
        return NULL;
    else if(raizBB->hijoDerBB == NULL)
        return raizBB;
    else
        return mayorBB(raizBB->hijoDerBB);
}

void arbolBB::agregar(int cantidadCosecha) //agregar segun cantidad de cosecha
{
    int precioUno = this->precioUno;
    int precioDos = this->precioDos;
    int cont = 0;
    while(cont != cantidadCosecha)
    {
        int numero = rand () % (precioDos-precioUno+1) + precioUno; // random de donde debería ir cuando es máquina de limpiado
        insertarFrutoBBAux(numero);
        cont++;
    }
}

//---------------------------------------
// Funciones Arboles Avl
//---------------------------------------

int arbolAVL::borrarRaizAVL(int pCantidadAVL) //borrar raiz del avl
{
    if(raizAVL == NULL)
    {
        return 0;
    }
    else
    {
        int cont = 0;
        while(pCantidadAVL != cont)
        {
            if(raizAVL == NULL && cantidadFrutosAVL(raizAVL) == 1)
            {
                return cont;
            }
            else
            {
                int precioAVL = raizAVL->costoFrutoAVL;
                borrarFrutoAVL(precioAVL, raizAVL);
                cont++;
            }
        }
        return cont;
    }
}

//Funciones Arbol AVL
void arbolAVL::insertarFrutoAVLAux(int costoFAVL) //insertar fruto
{
     raizAVL = insertarFrutoAVL(costoFAVL, raizAVL);
}

nodoAVL *arbolAVL::insertarFrutoAVL(int costoFAVL, nodoAVL *raizAVL) //funcion auxiliar de insertar
{
      if(raizAVL == NULL)
      {
        return new nodoAVL(costoFAVL);
      }
      else if(raizAVL->costoFrutoAVL < costoFAVL)
      {
        raizAVL->hijoDerAVL = insertarFrutoAVL(costoFAVL, raizAVL->hijoDerAVL);
      }
      else if(raizAVL->costoFrutoAVL >= costoFAVL)
      {
        raizAVL->hijoIzqAVL = insertarFrutoAVL(costoFAVL, raizAVL->hijoIzqAVL);
      }
      return raizAVL;
}


int arbolAVL::cantidadFrutosAVL(nodoAVL *raizAVL) //cantidad de frutos
{
    QMutex*mutex =new QMutex();
    mutex->lock();
    if(raizAVL == NULL)
    {
        mutex->unlock();
        return 0;
    }
    else
    {
        mutex->unlock();
        return 1 + cantidadFrutosAVL(raizAVL->hijoDerAVL) + cantidadFrutosAVL(raizAVL->hijoIzqAVL);
    }
}


int arbolAVL::precioDelArbolAVL(nodoAVL *raizAVL) //precio del total del arbol
{
    QMutex*mutex =new QMutex();
    mutex->lock();
     if(raizAVL == NULL)
     {
         mutex->unlock();
         return 0;
     }
     else
     {
         mutex->unlock();
         return raizAVL->costoFrutoAVL + raizAVL->costoFrutoAVL + cantidadFrutosAVL(raizAVL->hijoDerAVL) + cantidadFrutosAVL(raizAVL->hijoIzqAVL);
     }
}

nodoAVL *arbolAVL::borrarFrutoAuxAVL(int datoAVL) //borrar frutos
{
    return borrarFrutoAVL(datoAVL, raizAVL);
}

nodoAVL *arbolAVL::borrarFrutoAVL(int costoFAVL, nodoAVL *raizAVL) //borrar el fruto del arbol
{
    if(raizAVL == NULL)
    {
        return NULL;
    }
    else if(costoFAVL < raizAVL->costoFrutoAVL)
        raizAVL->hijoIzqAVL = borrarFrutoAVL(costoFAVL, raizAVL->hijoIzqAVL);
    else if(costoFAVL > raizAVL->costoFrutoAVL)
        raizAVL->hijoDerAVL = borrarFrutoAVL(costoFAVL, raizAVL->hijoDerAVL);
    else if(raizAVL->hijoIzqAVL == NULL && raizAVL->hijoDerAVL == NULL)
        raizAVL = NULL;
    else if(raizAVL->hijoIzqAVL == NULL)
        raizAVL = raizAVL->hijoDerAVL;
    else if(raizAVL->hijoDerAVL == NULL)
        raizAVL = raizAVL->hijoIzqAVL;
    else
    {
        nodoAVL *maxAVL = mayorAVL(raizAVL->hijoIzqAVL); // mayor de los menores
        raizAVL->hijoIzqAVL = borrarFrutoAVL(maxAVL->costoFrutoAVL, raizAVL->hijoIzqAVL);
        raizAVL->costoFrutoAVL = maxAVL->costoFrutoAVL;
    }
    return raizAVL;
}

nodoAVL *arbolAVL::mayorAVL(nodoAVL *raizAVL) //funcion que saca el mayor de los menores
{
    if(raizAVL == NULL)
        return NULL;
    else if(raizAVL->hijoDerAVL == NULL)
        return raizAVL;
    else
        return mayorAVL(raizAVL->hijoDerAVL);
}

void arbolAVL::mostrarArbolAVL()
{
    imprimirArbolAVL(raizAVL, 1);
}

void arbolAVL::imprimirArbolAVL(nodoAVL *pRaizAVL, int altAVL)
{
    if(pRaizAVL != NULL)
    {
        imprimirArbolAVL(pRaizAVL->hijoDerAVL, altAVL + 1);
        for(int i = 1; i <= altAVL; i++)
        imprimirArbolAVL(pRaizAVL->hijoIzqAVL, altAVL + 1);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

nodoAVL *arbolAVL::rSimpleIAVL(nodoAVL *nCargadoAVL, nodoAVL *hijoDerAux)
{
    nCargadoAVL->hijoDerAVL = hijoDerAux->hijoIzqAVL;
    hijoDerAux->hijoIzqAVL = nCargadoAVL;

    nCargadoAVL->equilibrioAVL = alturaAVL(nCargadoAVL->hijoDerAVL) - alturaAVL(nCargadoAVL->hijoIzqAVL);
    hijoDerAux->equilibrioAVL = alturaAVL(hijoDerAux->hijoDerAVL) - alturaAVL(hijoDerAux->hijoIzqAVL);
    return hijoDerAux;
}

nodoAVL *arbolAVL::rDobleIAVL(nodoAVL *nCargadoAVL, nodoAVL *hijoDerAux)
{
    nodoAVL *raizAVL = hijoDerAux->hijoIzqAVL;
    raizAVL->hijoDerAVL = hijoDerAux;
    raizAVL->hijoIzqAVL = nCargadoAVL;
    nCargadoAVL->hijoDerAVL = NULL;
    hijoDerAux->hijoIzqAVL = NULL;

    nCargadoAVL->equilibrioAVL = 0 - alturaAVL(nCargadoAVL->hijoIzqAVL);
    hijoDerAux->equilibrioAVL = alturaAVL(hijoDerAux->hijoDerAVL) - 0;
    raizAVL->equilibrioAVL = alturaAVL(raizAVL->hijoDerAVL) - alturaAVL(raizAVL->hijoIzqAVL);
    return raizAVL;
}

nodoAVL *arbolAVL::rDobleDAVL(nodoAVL *nCargadoAVL, nodoAVL *hijoIzqAux)
{
    nodoAVL *raizAVL = hijoIzqAux->hijoDerAVL;
    raizAVL->hijoDerAVL = nCargadoAVL;
    raizAVL->hijoIzqAVL = hijoIzqAux;

    nCargadoAVL->hijoIzqAVL = NULL;
    hijoIzqAux->hijoDerAVL = NULL;

    nCargadoAVL->equilibrioAVL = alturaAVL(nCargadoAVL->hijoDerAVL) ;
    hijoIzqAux->equilibrioAVL = 0 - alturaAVL(hijoIzqAux->hijoIzqAVL);
    raizAVL->equilibrioAVL = alturaAVL(raizAVL->hijoDerAVL) - alturaAVL(raizAVL->hijoIzqAVL);
    return raizAVL;
}

nodoAVL *arbolAVL::rSimpleDAVL(nodoAVL *nCargadoAVL, nodoAVL *hijoIzqAux)
{
    nCargadoAVL->hijoIzqAVL = hijoIzqAux->hijoDerAVL;
    hijoIzqAux->hijoDerAVL = nCargadoAVL;

    nCargadoAVL->equilibrioAVL = alturaAVL(nCargadoAVL->hijoDerAVL) - alturaAVL(nCargadoAVL->hijoIzqAVL);
    hijoIzqAux->equilibrioAVL = alturaAVL(hijoIzqAux->hijoDerAVL) - alturaAVL(hijoIzqAux->hijoIzqAVL);
    return hijoIzqAux;
}

int arbolAVL::alturaAVL(nodoAVL *nActualAVL)
{
    if(nActualAVL != NULL)
    {
        return mayorAVL(alturaAVL(nActualAVL->hijoIzqAVL), alturaAVL(nActualAVL->hijoDerAVL)) + 1;
    } else
    {
        return 0;
    }
}

int arbolAVL::mayorAVL(int num1AVL, int num2AVL)
{
    return (num1AVL > num2AVL ? num1AVL : num2AVL);
}

nodoAVL *arbolAVL::balancearArbolAVL(nodoAVL *nActualAVL)
{
    if(nActualAVL == NULL)
        return NULL;
    nActualAVL->hijoIzqAVL = balancearArbolAVL(nActualAVL->hijoIzqAVL);
    nActualAVL->hijoDerAVL = balancearArbolAVL(nActualAVL->hijoDerAVL);

    nActualAVL->equilibrioAVL = alturaAVL(nActualAVL->hijoDerAVL) - alturaAVL(nActualAVL->hijoIzqAVL);
    //Se equilibra el arbol tras haber borrado los nodos
    if(nActualAVL->equilibrioAVL >= 2 )
    {
        if(nActualAVL->hijoDerAVL->equilibrioAVL == -1)
            nActualAVL = rDobleIAVL(nActualAVL, nActualAVL->hijoDerAVL);
        else
            nActualAVL = rSimpleIAVL(nActualAVL, nActualAVL->hijoDerAVL);
    }
    else if(nActualAVL->equilibrioAVL <= -2)
    {
        if(nActualAVL->hijoIzqAVL->equilibrioAVL == -1)
            nActualAVL = rSimpleDAVL(nActualAVL, nActualAVL->hijoIzqAVL);
        else
            nActualAVL = rDobleDAVL(nActualAVL, nActualAVL->hijoIzqAVL);
    }
    return nActualAVL;
}

int arbolAVL::precioDelArbol()
{
    return precioDelArbolAVL(raizAVL);
}

void arbolAVL::agregar(int cantidadCosecha)
{
    int precioUno = this->precioUno;
    int precioDos = this->precioDos;
    int cont = 0;
    while(cont != cantidadCosecha)
    {
        int numero = rand () % (precioDos-precioUno+1) + precioUno; // random de donde debería ir cuando es máquina de limpiado
        insertarFrutoAVLAux(numero);
        cont++;
    }
}

//------------------------------
// Funciones de arboles Splay
//------------------------------


int arbolSplay::borrarRaizSplay(int pCantidadSplay)
{
    if(raizSplay == NULL)
    {
    }
    else
    {
        int cont = 0;
        while(pCantidadSplay != cont)
        {
            if(raizSplay == NULL && cantidadFrutosSplay(raizSplay) == 1)
            {
                return cont;
            }
            else
            {
                int precioSplay = raizSplay->costoFrutoSplay;
                borrarFrutoSplay(precioSplay, raizSplay);
                cont++;
            }
        }
        return cont;
    }
}

//Funciones Arbol Splay
void arbolSplay::insertarFrutoSplayAux(int costoFSplay)
{
     raizSplay = insertarFrutoSplay(costoFSplay, raizSplay);
}

nodoSplay *arbolSplay::insertarFrutoSplay(int costoFSplay, nodoSplay *raizSplay)
{
    if(raizSplay == NULL)
    {
        return new nodoSplay(costoFSplay);
    }
    else if(raizSplay->costoFrutoSplay < costoFSplay)
    {
        raizSplay->hijoDerSplay = insertarFrutoSplay(costoFSplay, raizSplay->hijoDerSplay);
    }
    else if(raizSplay->costoFrutoSplay >= costoFSplay)
    {
        raizSplay->hijoIzqSplay = insertarFrutoSplay(costoFSplay, raizSplay->hijoIzqSplay);
    }
    return raizSplay;
}


int arbolSplay::cantidadFrutosSplay(nodoSplay *raizSplay)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
     if(raizSplay == NULL)
     {
         mutex->unlock();
        return 0;
     }
     else
     {
         mutex->unlock();
        return 1 + cantidadFrutosSplay(raizSplay->hijoDerSplay) + cantidadFrutosSplay(raizSplay->hijoIzqSplay);
     }
}


int arbolSplay::precioDelArbolSplay(nodoSplay *raizSplay)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    if(raizSplay == NULL)
    {
        mutex->unlock();
        return 0;
    }
    else
    {
        mutex->unlock();
        return raizSplay->costoFrutoSplay + raizSplay->costoFrutoSplay + cantidadFrutosSplay(raizSplay->hijoDerSplay) + cantidadFrutosSplay(raizSplay->hijoIzqSplay);
    }
}

nodoSplay *arbolSplay::borrarFrutoAuxSplay(int datoSplay)
{
    return borrarFrutoSplay(datoSplay, raizSplay);
}

nodoSplay *arbolSplay::borrarFrutoSplay(int costoFSplay, nodoSplay *raizSplay)
{
    if(raizSplay == NULL)
    {
        return NULL;
    }
    else if(costoFSplay < raizSplay->costoFrutoSplay)
        raizSplay->hijoIzqSplay = borrarFrutoSplay(costoFSplay, raizSplay->hijoIzqSplay);
    else if(costoFSplay > raizSplay->costoFrutoSplay)
        raizSplay->hijoDerSplay = borrarFrutoSplay(costoFSplay, raizSplay->hijoDerSplay);
    else if(raizSplay->hijoIzqSplay == NULL && raizSplay->hijoDerSplay == NULL)
        raizSplay = NULL;
    else if(raizSplay->hijoIzqSplay == NULL)
        raizSplay = raizSplay->hijoDerSplay;
    else if(raizSplay->hijoDerSplay == NULL)
        raizSplay = raizSplay->hijoIzqSplay;
    else
    {
        nodoSplay *maxSplay = mayorSplay(raizSplay->hijoIzqSplay); // mayor de los menores
        raizSplay->hijoIzqSplay = borrarFrutoSplay(maxSplay->costoFrutoSplay, raizSplay->hijoIzqSplay);
        raizSplay->costoFrutoSplay = maxSplay->costoFrutoSplay;
    }
    return raizSplay;
}

// Funcion auxiliar de borrarFrutoSplay
nodoSplay *arbolSplay::mayorSplay(nodoSplay *raizSplay)
{
    if(raizSplay == NULL)
        return NULL;
    else if(raizSplay->hijoDerSplay == NULL)
        return raizSplay;
    else
        return mayorSplay(raizSplay->hijoDerSplay);
}

void arbolSplay::mostrarArbolSplay()
{
    imprimirArbolSplay(raizSplay, 1);
}

void arbolSplay::imprimirArbolSplay(nodoSplay *pRaizSplay, int altSplay)
{
    if(pRaizSplay != NULL)
    {
        imprimirArbolSplay(pRaizSplay->hijoDerSplay, altSplay + 1);
        for(int i = 1; i <= altSplay; i++)
        imprimirArbolSplay(pRaizSplay->hijoIzqSplay, altSplay + 1);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
nodoSplay *arbolSplay::rSimpleISplay(nodoSplay *nCargadoSplay, nodoSplay *hijoDerAux)
{
    nCargadoSplay->hijoDerSplay = hijoDerAux->hijoDerSplay;
    hijoDerAux->hijoIzqSplay = nCargadoSplay;

    nCargadoSplay->equilibrioSplay = alturaSplay(nCargadoSplay->hijoDerSplay) - alturaSplay(nCargadoSplay->hijoIzqSplay);
    hijoDerAux->equilibrioSplay = alturaSplay(hijoDerAux->hijoDerSplay) - alturaSplay(hijoDerAux->hijoIzqSplay);
    return hijoDerAux;
}

nodoSplay *arbolSplay::rDobleISplay(nodoSplay *nCargadoSplay, nodoSplay *hijoDerAux)
{
    nodoSplay *raizSplay = hijoDerAux->hijoIzqSplay;
    raizSplay->hijoDerSplay = hijoDerAux;
    raizSplay->hijoIzqSplay = nCargadoSplay;
    nCargadoSplay->hijoDerSplay = NULL;
    hijoDerAux->hijoIzqSplay = NULL;

    nCargadoSplay->equilibrioSplay = 0 - alturaSplay(nCargadoSplay->hijoIzqSplay);
    hijoDerAux->equilibrioSplay = alturaSplay(hijoDerAux->hijoDerSplay) - 0;
    raizSplay->equilibrioSplay = alturaSplay(raizSplay->hijoDerSplay) - alturaSplay(raizSplay->hijoIzqSplay);
    return raizSplay;
}

nodoSplay *arbolSplay::rDobleDSplay(nodoSplay *nCargadoSplay, nodoSplay *hijoIzqAux)
{
    nodoSplay *raizSplay = hijoIzqAux->hijoDerSplay;
    raizSplay->hijoDerSplay = nCargadoSplay;
    raizSplay->hijoIzqSplay = hijoIzqAux;

    nCargadoSplay->hijoIzqSplay = NULL;
    hijoIzqAux->hijoDerSplay = NULL;

    nCargadoSplay->equilibrioSplay = alturaSplay(nCargadoSplay->hijoDerSplay);
    hijoIzqAux->equilibrioSplay = 0 - alturaSplay(hijoIzqAux->hijoIzqSplay);
    raizSplay->equilibrioSplay = alturaSplay(raizSplay->hijoDerSplay) - alturaSplay(raizSplay->hijoIzqSplay);
    return raizSplay;
}

nodoSplay *arbolSplay::rSimpleDSplay(nodoSplay *nCargadoSplay, nodoSplay *hijoIzqAux)
{
    nCargadoSplay->hijoIzqSplay = hijoIzqAux->hijoDerSplay;
    hijoIzqAux->hijoDerSplay = nCargadoSplay;

    nCargadoSplay->equilibrioSplay = alturaSplay(nCargadoSplay->hijoDerSplay) - alturaSplay(nCargadoSplay->hijoIzqSplay);
    hijoIzqAux->equilibrioSplay = alturaSplay(hijoIzqAux->hijoDerSplay) - alturaSplay(hijoIzqAux->hijoIzqSplay);
    return hijoIzqAux;
}

int arbolSplay::alturaSplay(nodoSplay *nActualSplay)
{
    if(nActualSplay != NULL)
    {
        return mayorSplay(alturaSplay(nActualSplay->hijoIzqSplay), alturaSplay(nActualSplay->hijoDerSplay)) + 1;
    } else
    {
        return 0;
    }
}

int arbolSplay::mayorSplay(int num1Splay, int num2Splay)
{
    return (num1Splay > num2Splay ? num1Splay : num2Splay);
}

nodoSplay *arbolSplay::balancearArbolSplay(nodoSplay *nActualSplay)
{
    if(nActualSplay == NULL)
        return NULL;
    nActualSplay->hijoIzqSplay = balancearArbolSplay(nActualSplay->hijoIzqSplay);
    nActualSplay->hijoDerSplay = balancearArbolSplay(nActualSplay->hijoDerSplay);

    nActualSplay->equilibrioSplay = alturaSplay(nActualSplay->hijoDerSplay) - alturaSplay(nActualSplay->hijoIzqSplay);
    //Se equilibra el arbol tras haber borrado los nodos
    if(nActualSplay->equilibrioSplay >= 2)
    {
        if(nActualSplay->hijoDerSplay->equilibrioSplay == -1)
            nActualSplay = rDobleISplay(nActualSplay, nActualSplay->hijoDerSplay);
        else
            nActualSplay = rSimpleISplay(nActualSplay, nActualSplay->hijoDerSplay);
    }
    else if(nActualSplay->equilibrioSplay <= -2)
    {
        if(nActualSplay->hijoIzqSplay->equilibrioSplay == -1)
            nActualSplay = rSimpleDSplay(nActualSplay, nActualSplay->hijoIzqSplay);
        else
            nActualSplay = rDobleDSplay(nActualSplay, nActualSplay->hijoIzqSplay);
    }
    return nActualSplay;
}

void arbolSplay::agregar(int cantidadVeces)
{
    int precioUno = this->precioUno;
    int precioDos = this->precioDos;
    int cont = 0;
    while(cont != cantidadVeces)
    {
        int numero = rand () % (precioDos-precioUno+1) + precioUno; // random de donde debería ir cuando es máquina de limpiado
        insertarFrutoSplayAux(numero);
        cont++;
    }
}

//------------------------
// Arbol Heap
//------------------------

void arbolHeap::insertarFrutoHeapAux(int costoFHeap)
{
     raizHeap = insertarFrutoHeap(costoFHeap, raizHeap);
}

nodoHeap *arbolHeap::insertarFrutoHeap(int costoFHeap, nodoHeap *raizAux)
{
      if(raizAux == NULL)
      {
        return new nodoHeap(costoFHeap);
      }
      else if(raizAux->costoFrutoHeap < costoFHeap)
      {
        raizAux->hijoDerHeap = insertarFrutoHeap(costoFHeap, raizAux->hijoDerHeap);
      }
      else if(raizAux->costoFrutoHeap >= costoFHeap)
      {
        raizAux->hijoIzqHeap = insertarFrutoHeap(costoFHeap, raizAux->hijoIzqHeap);
      }

      return raizAux;
}


int arbolHeap::cantidadFrutosHeap(nodoHeap *raizAux)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    if(raizAux == NULL)
    {
        mutex->unlock();
        return 0;
    }
    else
    {
        mutex->unlock();
        return 1 + cantidadFrutosHeap(raizAux->hijoDerHeap) + cantidadFrutosHeap(raizAux->hijoIzqHeap);
    }
}


int arbolHeap::precioDelArbolHeap(nodoHeap *raizAux)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    if(raizAux == NULL)
    {
        mutex->unlock();
        return 0;
    }
    else
    {
        mutex->unlock();
        return raizAux->costoFrutoHeap + raizAux->costoFrutoHeap + cantidadFrutosHeap(raizAux->hijoDerHeap) + cantidadFrutosHeap(raizAux->hijoIzqHeap);
    }
}

nodoHeap *arbolHeap::borrarFrutoHeap(int costoFHeap, nodoHeap *raizAux)
{
    if(raizAux == NULL)
    {
        return NULL;
    }
    else if(costoFHeap < raizAux->costoFrutoHeap)
        raizAux->hijoIzqHeap = borrarFrutoHeap(costoFHeap, raizAux->hijoIzqHeap);
    else if(costoFHeap > raizAux->costoFrutoHeap)
        raizAux->hijoDerHeap = borrarFrutoHeap(costoFHeap, raizAux->hijoDerHeap);
    else if(raizAux->hijoIzqHeap == NULL && raizAux->hijoDerHeap == NULL)
        raizAux = NULL;
    else if(raizAux->hijoIzqHeap == NULL)
        raizAux = raizAux->hijoDerHeap;
    else if(raizAux->hijoDerHeap == NULL)
        raizAux = raizAux->hijoIzqHeap;
    else
    {
        nodoHeap *maxHeap = mayorHeap(raizAux->hijoIzqHeap); // mayor de los menores
        raizAux->hijoIzqHeap = borrarFrutoHeap(maxHeap->costoFrutoHeap, raizAux->hijoIzqHeap);
        raizAux->costoFrutoHeap = maxHeap->costoFrutoHeap;
    }
    return raizAux;
}

// Funcion auxiliar de borrarFrutoBB
nodoHeap *arbolHeap::mayorHeap(nodoHeap *raizAux)
{
    if(raizAux == NULL)
        return NULL;
    else if(raizAux->hijoDerHeap == NULL)
        return raizAux;
    else
        return mayorHeap(raizAux->hijoDerHeap);
}

void arbolHeap::agregar(int cantidadCosecha)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    int precioUno = this->precioUno;
    int precioDos = this->precioDos;
    int cont = 0;
    while(cont != cantidadCosecha)
    {
        int numero = rand () % (precioDos-precioUno+1) + precioUno; // random de donde debería ir cuando es máquina de limpiado
        insertarFrutoHeapAux(numero);
        cont++;
    }
    mutex->unlock();
}

int arbolHeap::borrarRaiz(int pCantidadHeap)
{
    if(raizHeap == NULL)
    {
        return 0;
    }
    else
    {
        int cont = 0;
        while(pCantidadHeap != cont)
        {
            if(raizHeap == NULL || cantidadFrutosHeap(raizHeap) == 1)
            {
                return cont;
            }
            else
            {
                int precioHeap = raizHeap->costoFrutoHeap;
                borrarFrutoHeap(precioHeap, raizHeap);
                cont++;
            }
        }
        return cont;
    }
}

void Plaga::eliminarRaiz(int segundos,int segundosTotal, arbolBB*arbol)
{
    float cuantos = (segundos*1.0/segundosTotal*1.0)*arbol->cantidadFrutosBB(arbol->raizAB);
    this->frutos = this->frutos + cuantos;
    if(segundos == segundosTotal)
    {
        arbol->raizAB = NULL;
        arbol = NULL;
    }
    else if(segundos <segundosTotal)
    {
        arbol->borrarRaiz(cuantos);
    }
    else
    {

    }
}

void Plaga::eliminarRaizAvl(int segundos,int segundosTotal, arbolAVL* ArbolAvl)
{
    float cuantos = (segundos*1.0/segundosTotal*1.0)*ArbolAvl->cantidadFrutosAVL(ArbolAvl->raizAVL);
    int cont = 0;
    this->frutos = this->frutos + cuantos;
    if(segundos <segundosTotal)
    {
        ArbolAvl->borrarRaizAVL(cuantos);
    }
    else if(segundos == segundosTotal)
    {
        ArbolAvl = NULL;
    }
}

void Plaga::eliminarRaizHeap(int segundos,int segundosTotal, arbolHeap* ArbolHeap)
{
    int cuantos = (segundos*1.0/segundosTotal*1.0)*ArbolHeap->cantidadFrutosHeap(ArbolHeap->raizHeap);
    int cont = 0;
    this->frutos = this->frutos + cuantos;

    if(segundos <segundosTotal)
    {
        ArbolHeap->borrarRaiz(cuantos);
    }
    else if(segundos == segundosTotal)
    {
        ArbolHeap = NULL;
    }
}

void Plaga::eliminarRaizSplay(int segundos,int segundosTotal, arbolSplay* ArbolSplay)
{
    int cuantos = (segundos*1.0/segundosTotal*1.0)*(ArbolSplay->cantidadFrutosSplay(ArbolSplay->raizSplay));
    int cont = 0;
    this->frutos = this->frutos + cuantos;

    if(segundos <segundosTotal)
    {
        ArbolSplay->borrarRaizSplay(cuantos);
    }
    else if(segundos == segundosTotal)
    {
        ArbolSplay = NULL;
    }
}


//----------
//Oveja
//----------

void Oveja::eliminarRaiz(int veces, arbolBB*arbolComida)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    arbolComida->frutosPerdidos = arbolComida->frutosPerdidos + veces;
    arbolComida->borrarRaiz(veces);
    mutex->unlock();
}


void Oveja::eliminarRaizHeap(int veces, arbolHeap*arbolComida)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    arbolComida->frutosPerdidos = arbolComida->frutosPerdidos + veces; // Sumarle a frutos perdidos.
    arbolComida->borrarRaiz(veces);
    mutex->unlock();
}

//----------
//Cuervo
//----------

void Cuervo::eliminarRaiz(int veces, arbolBB *arbolComida)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    arbolComida->frutosPerdidos = arbolComida->frutosPerdidos + veces;
    arbolComida->borrarRaiz(veces);
    mutex->unlock();
}

void Cuervo::eliminarRaizHeap(int veces, arbolHeap*arbolComida)
{
    QMutex* mutex = new QMutex();
    mutex->lock();
    arbolComida->frutosPerdidos = arbolComida->frutosPerdidos + veces;
    arbolComida->borrarRaiz(veces);
    mutex->unlock();
}
