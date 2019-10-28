#include "finca.h"

finca::finca()
{
    this->hayEspantapajaro = false;
    this->ListaArbolesVender = new ListNodoArbolMercado();
    createThreads();
}

void finca::desactivarThreads()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            this->myFinca[i][j]->Stop = false;
        }
    }
}

void finca::createThreads()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            HiloNodoFinca* nodeFinca = new HiloNodoFinca();
            QString threadName = "hilo"+QString::number(i)+QString::number(j);
            nodeFinca->posicion = i+(j*0.1);
            nodeFinca->identificador = threadName;
            this->myFinca[i][j] = nodeFinca;
        }
    }
}

void finca::activarArbolOrdenado(int x, int y)
{
    int cosecha = this->lDatos->buscarArbol("Ordenado")->cosecha;
    int crece = this->lDatos->buscarArbol("Ordenado")->crece;
    int tiempoCosecha = this->lDatos->buscarArbol("Ordenado")->tiempoCosecha;
    int precio1 = this->lDatos->buscarArbol("Ordenado")->precio1;
    int precio2 = this->lDatos->buscarArbol("Ordenado")->precio2;

    this->myFinca[x][y]->ArbolBinario = new arbolBB();
    this->myFinca[x][y]->ArbolBinario->cantidadCosecha = cosecha;
    this->myFinca[x][y]->ArbolBinario->EmpiezaCrece = crece;
    this->myFinca[x][y]->ArbolBinario->precioUno = precio1;
    this->myFinca[x][y]->ArbolBinario->precioDos = precio2;
    this->myFinca[x][y]->ArbolBinario->tiempoCosecha = tiempoCosecha;

    this->myFinca[x][y]->start();
}

void finca::activarArbolHeap(int x, int y)
{
    int cosecha = this->lDatos->buscarArbol("Heap")->cosecha;
    int crece = this->lDatos->buscarArbol("Heap")->crece;
    int tiempoCosecha = this->lDatos->buscarArbol("Heap")->tiempoCosecha;
    int precio1 = this->lDatos->buscarArbol("Heap")->precio1;
    int precio2 = this->lDatos->buscarArbol("Heap")->precio2;

    this->myFinca[x][y]->ArbolHeap = new arbolHeap();
    this->myFinca[x][y]->ArbolHeap->cantidadCosecha = cosecha;
    this->myFinca[x][y]->ArbolHeap->EmpiezaCrece = crece;
    this->myFinca[x][y]->ArbolHeap->precioUno = precio1;
    this->myFinca[x][y]->ArbolHeap->precioDos = precio2;
    this->myFinca[x][y]->ArbolHeap->tiempoCosecha = tiempoCosecha;

    this->myFinca[x][y]->start();
}

void finca::activarArbolAvl(int x, int y)
{
    int cosecha = this->lDatos->buscarArbol("Avl")->cosecha;
    int crece = this->lDatos->buscarArbol("Avl")->crece;
    int tiempoCosecha = this->lDatos->buscarArbol("Avl")->tiempoCosecha;
    int precio1 = this->lDatos->buscarArbol("Avl")->precio1;
    int precio2 = this->lDatos->buscarArbol("Avl")->precio2;

    this->myFinca[x][y]->ArbolAvl = new arbolAVL();
    this->myFinca[x][y]->ArbolAvl->cantidadCosecha = cosecha;
    this->myFinca[x][y]->ArbolAvl->EmpiezaCrece = crece;
    this->myFinca[x][y]->ArbolAvl->precioUno = precio1;
    this->myFinca[x][y]->ArbolAvl->precioDos = precio2;
    this->myFinca[x][y]->ArbolAvl->tiempoCosecha = tiempoCosecha;

    this->myFinca[x][y]->start();
}

void finca::activarArbolSplay(int x, int y)
{
    int cosecha = this->lDatos->buscarArbol("Splay")->cosecha;
    int crece = this->lDatos->buscarArbol("Splay")->crece;
    int tiempoCosecha = this->lDatos->buscarArbol("Splay")->tiempoCosecha;
    int precio1 = this->lDatos->buscarArbol("Splay")->precio1;
    int precio2 = this->lDatos->buscarArbol("Splay")->precio2;

    this->myFinca[x][y]->ArbolSplay = new arbolSplay();
    this->myFinca[x][y]->ArbolSplay->cantidadCosecha = cosecha;
    this->myFinca[x][y]->ArbolSplay->EmpiezaCrece = crece;
    this->myFinca[x][y]->ArbolSplay->precioUno = precio1;
    this->myFinca[x][y]->ArbolSplay->precioDos = precio2;
    this->myFinca[x][y]->ArbolSplay->tiempoCosecha = tiempoCosecha;

    this->myFinca[x][y]->start();
}

void finca::recogerDatosDeLosArboles()
{
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            bool hayArbol = this->myFinca[i][j]->hayArbol();
            if(hayArbol)
            {
                float posicion = i + (j*0.1);
                int cantidadFrutos = this->myFinca[i][j]->cantidadDeFrutosActuales();
                int cantidadMonto = this->myFinca[i][j]->calcularMontoTotalDeFrutos();
                int perdidos = this->myFinca[i][j]->cantidadDeFrutosPerdidos();
                NodoArbolMercado* nodoMercado = this->ListaArbolesVender->buscarArbol(posicion);
                if(nodoMercado == NULL)
                {
                    this->ListaArbolesVender->insertarAlFinal(ArbolPosicion(i,j),posicion,cantidadFrutos,cantidadMonto,0,perdidos);
                }
                else
                {
                    nodoMercado->cantFrutos = cantidadFrutos;
                    nodoMercado->montoTotal = cantidadMonto;
                    nodoMercado->perdidos = perdidos;
                }
            }
        }
    }
    this->ListaArbolesVender->imprimir();
}

string finca::ArbolPosicion(int x, int y)
{
    if(this->myFinca[x][y]->ArbolAvl != NULL)
    {
        return "Avl";
    }
    else if(this->myFinca[x][y]->ArbolBinario != NULL)
    {
        return "Ordenado";
    }
    else if(this->myFinca[x][y]->ArbolHeap != NULL)
    {
        return "Heap";
    }
    else if(this->myFinca[x][y]->ArbolSplay != NULL)
    {
        return "Splay";
    }
    else
    {
        return "";
    }
}

void finca::eliminarFrutosVendidos(int x, int y, int cantidad)
{
    if(this->myFinca[x][y]->ArbolAvl != NULL)
    {
        this->myFinca[x][y]->ArbolAvl->borrarRaizAVL(cantidad);
    }
    else if(this->myFinca[x][y]->ArbolBinario != NULL)
    {
        this->myFinca[x][y]->ArbolBinario->borrarRaiz(cantidad);
    }
    else if(this->myFinca[x][y]->ArbolHeap != NULL)
    {
        this->myFinca[x][y]->ArbolHeap->borrarRaiz(cantidad);
    }
    else if(this->myFinca[x][y]->ArbolSplay != NULL)
    {
        this->myFinca[x][y]->ArbolSplay->borrarRaizSplay(cantidad);
    }
    else
    {
    }
}

void finca::activarHilo(int x, int y)
{
    this->myFinca[x][y]->start();
}

void finca::detenerHilos(int x, int y)
{
    this->myFinca[x][y]->Pausa = true;
}

void finca::imprimir()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            HiloNodoFinca* tmp = this->myFinca[i][j];
            cout<<tmp->identificador.toStdString()<<endl;
        }
    }
}

void finca::espantarPlaga(int x, int y)
{
    this->myFinca[x][y]->oveja = NULL ;
    this->myFinca[x][y]->cuervo = NULL;
    this->myFinca[x][y]->Gusano = NULL;
}
