#include "juego.h"
#include "ui_juego.h"
#include <QKeyEvent> // Librería para eventos del teclado.
#include <QLabel>

Juego::Juego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Juego)
{
    ui->setupUi(this);
    ui->bInsertarAvl->setDisabled(true);
    ui->bInsertarEspantapajaros->setDisabled(true);
    ui->bInsertarHeap->setDisabled(true);
    ui->bInsertarOrdenado->setDisabled(true);
    ui->bInsertarSplay->setDisabled(true);

    // Contador de espantapajaro 2
    this->cantidadEspantapajaro = 0;
    ui->lCantidadEspanta->setText(QString::number(this->cantidadEspantapajaro ));

    this->cantidadOrdenado = 2;
    ui->lCantidadOrdenado->setText(QString::number(this->cantidadOrdenado));

    this->cantidadSplay = 2;
    ui->lCantidadSplay->setText(QString::number(this->cantidadSplay));

    this->cantidadHeap = 2;
    ui->lCantidadHeap->setText(QString::number(this->cantidadHeap));

    this->cantidadAvl = 2;
    ui->lCantidadAvl->setText(QString::number(this->cantidadAvl));

    this->Granja = new finca(); //inicializar finca

    // Hilo Cronometro

    hCronometro = new HiloCronometro(this);//crea el objeto
    hCronometro->Stop = false;
    hCronometro->bandera = false;
    hCronometro->abiertoJuego = true;
    hCronometro->abiertoMercado = false;
    hCronometro->tiempoMercado = 0;
    //Inicializar los listaMercado
    this->mercadoListaComprado = new listaMercado();

    this->hPlaga = new HiloPlaga(this);
    this->hPlaga->bandera = true;
    connect(hPlaga, SIGNAL(eeColocarPlaga(int,int)), this, SLOT(enColocarPlaga(int,int)));//Se conectan, seguir la sintaxis
}

void Juego::asignarValues()
{
    this->hPlaga->asignarValores(this->lDatos);
}

void Juego::recorrerInterfaz()
{
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            QString sPlaga = "Gusano"+QString::number(i)+QString::number(j);
            QLabel *lPlaga = this->findChild<QLabel *>(sPlaga);
            QString sAvl = "Avl"+QString::number(i)+QString::number(j);
            QLabel *lAvl = this->findChild<QLabel *>(sAvl);
            QString sSplay = "Splay"+QString::number(i)+QString::number(j);
            QLabel *lSplay = this->findChild<QLabel *>(sSplay);
            QString sOrdenado = "Ordenado"+QString::number(i)+QString::number(j);
            QLabel *lOrdenado = this->findChild<QLabel *>(sOrdenado);
            QString sHeap = "Heap"+QString::number(i)+QString::number(j);
            QLabel *lHeap = this->findChild<QLabel *>(sHeap);

            if(this->Granja->myFinca[i][j]->Gusano == NULL && lPlaga != NULL)
            {
                delete(lPlaga);
                if(lAvl != 0)
                {
                    delete(lAvl);
                }
                else if(lSplay != 0)
                {
                    delete(lSplay);
                }
                else if(lOrdenado != 0)
                {
                    delete(lOrdenado);
                }
                else if(lHeap != 0)
                {
                    delete(lHeap);
                }
                else
                {
                }
            }
        }
    }
}

void Juego::setTiempoCronometro()
{
    NodoDato* tmp = this->lDatos->buscarArbol("Mercado");
    hCronometro->tiempoMercado = tmp->Abre;
}

Juego::~Juego()
{
    delete ui;
}

void Juego::ponerNombreDinero()
{
    NodoDato* nombre = this->lDatos->primerNodo;
    while(nombre->nombre != "Nombre")
    {
        nombre = nombre->siguiente;
    }
    this->name = nombre->myName;
    this->dinero = 0;
    ui->lNombre->setText(this->name.c_str());
    ui->lDinero->setText(QString::number(this->dinero));
}

void Juego::deletePlague(QLabel*pPlague)
{
    delete(pPlague);
}

void Juego::adaptarArticulosComprados()
{
    Nodo* tmp = this->mercadoListaComprado->primerNodo;
    while(tmp != NULL)
    {
        if("Ordenado" == tmp->nombreMercado)
        {
            int total = ui->lCantidadOrdenado->text().toInt() + tmp->cantidad;
            this->cantidadOrdenado = total;
            ui->lCantidadOrdenado->setText(QString::number(total));
            tmp = tmp->siguiente;
        }
        else if("Heap" == tmp->nombreMercado)
        {
            int total = ui->lCantidadHeap->text().toInt() + tmp->cantidad;
            this->cantidadHeap = total;
            ui->lCantidadHeap->setText(QString::number(total));
            tmp = tmp->siguiente;
        }
        else if("Avl" == tmp->nombreMercado)
        {
            int total = ui->lCantidadAvl->text().toInt() + tmp->cantidad;
            this->cantidadAvl =total;
            ui->lCantidadAvl->setText(QString::number(total));
            tmp = tmp->siguiente;
        }
        else if("Splay" == tmp->nombreMercado)
        {
            int total = ui->lCantidadSplay->text().toInt() + tmp->cantidad;
            this->cantidadSplay = total;
            ui->lCantidadSplay->setText(QString::number(total));
            tmp = tmp->siguiente;
        }
        else if ("Espantapajaros" == tmp->nombreMercado)
        {
            int total = ui->lCantidadEspanta->text().toInt() + tmp->cantidad;
            this->cantidadEspantapajaro = total;
            ui->lCantidadEspanta->setText(QString::number(total));
            tmp = tmp->siguiente;
        }
        else
        {
            cout<<tmp->nombreMercado<<endl;
            tmp = tmp->siguiente;
        }
    }
}

bool Juego::isPlague(int pXPlague, int pYPlague, int pXFarmer, int pYFarmer)
{
    if(pXPlague == pXFarmer && pYPlague == pYFarmer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------
// Events of the farmer
//-----------------------

void Juego::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Up)
    {
        int x = ui->Billy->x();
        int y = ui->Billy->y();

        if(x == 590 && y == 122 || y == 122 || x == 668 && y == 570)
        {
            return;
        }
        int posX = (x-44)/78;
        int posY = (y-122-64)/64;

        espantarPlaga(posX,posY); // Espantar Plaga
        recorrerInterfaz();
        ui->Billy->move(QPoint(x,y-64));
        event->accept();
    }

    else if(event->key() == Qt::Key_Right)
    {
        int x = ui->Billy->x();
        int y = ui->Billy->y();

        if(x == 668 && y == 570)
        {
            return;
        }
        if(x == 590 && y == 570)
        {
            ui->Billy->move(QPoint(x+78,y));
            int posX = (x-44+78)/78;
            int posY = (y-122)/64;
            espantarPlaga(posX,posY); // Espantar Plaga
            recorrerInterfaz();
            event->accept();
            return;
        }
        if(x == 590 && y == 122 || x == 590)
        {
            return;
        }
        int posX = (x-44+78)/78;
        int posY = (y-122)/64;

        espantarPlaga(posX,posY); // Espantar Plaga
        recorrerInterfaz();
        ui->Billy->move(QPoint(x+78,y));
        event->accept();
    }
    else if(event->key() == Qt::Key_Left)
    {
        int x = ui->Billy->x();
        int y = ui->Billy->y();

        if(x == 44)
        {
            return;
        }
        int posX = (x-44-78)/78;
        int posY = (y-122)/64;

        espantarPlaga(posX,posY); // Espantar Plaga
        recorrerInterfaz();
        ui->Billy->move(QPoint(x-78,y));
        event->accept();
    }

    else if(event->key() == Qt::Key_Down)
    {
        int x = ui->Billy->x();
        int y = ui->Billy->y();

        if(y == 570)
        {
            return;
        }
        int posX = (x-44)/78;
        int posY = (y+64-122)/64;
        ui->Billy->move(QPoint(x,y+64));
        recorrerInterfaz();
        espantarPlaga(posX,posY); // Espantar Plaga
        event->accept();
    }
}

void Juego::espantarPlaga(int x, int y)
{
    // Espantar Plaga en la interfaz y en la matriz, que apunten a nulo y en la interfaz eliminarlo
    QString sPlaga = "Plaga" + QString::number(x) + QString::number(y);
    QLabel* lPlaga = this->findChild<QLabel *>(sPlaga);

    QString sGusano = "Gusano" + QString::number(x) + QString::number(y);
    QLabel* lGusano = this->findChild<QLabel *>(sGusano);
    if(lPlaga == 0 && lGusano == 0)
    {
        return; // No hay nada que espantar
    }
    else
    {
        if(lPlaga != 0)
        {
            delete(lPlaga); // Espantado
            this->Granja->espantarPlaga(x,y);
        }
        else
        {
            delete(lGusano); // Espantado
            this->Granja->espantarPlaga(x,y);
        }
    }
}

void Juego::on_pushButton_6_clicked()
{
    info *windowInfo = new info();
    windowInfo->show();
}

int Juego::cuantosArboles()
{
    int cont = 0;
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            QString heap = "Heap"+QString::number(i)+QString::number(j);
            QString avl = "Avl"+QString::number(i)+QString::number(j);
            QString ordenado = "Ordenado"+QString::number(i)+QString::number(j);
            QString splay = "Splay"+QString::number(i)+QString::number(j);

            QLabel* Heap = this->findChild<QLabel *>(heap);
            QLabel* Avl = this->findChild<QLabel *>(avl);
            QLabel* Ordenado = this->findChild<QLabel *>(ordenado);
            QLabel* Splay = this->findChild<QLabel *>(splay);
            if(Heap != NULL || Avl != NULL || Ordenado != NULL || Splay != NULL)
            {
                cont++;
            }
        }
    }
    return cont;
}

int Juego::cuantasPlagas()
{
    int cont = 0;
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            QString gusano = "Gusano"+QString::number(i)+QString::number(j);
            QString oveja = "Oveja"+QString::number(i)+QString::number(j);
            QString cuervo = "Cuervo"+QString::number(i)+QString::number(j);

            QLabel* Gusano = this->findChild<QLabel *>(gusano);
            QLabel* Cuervo = this->findChild<QLabel *>(cuervo);
            QLabel* Oveja = this->findChild<QLabel *>(oveja);
            if(Gusano != NULL || Cuervo != NULL || Oveja != NULL)
            {
                cont++;
            }
        }
    }
    return cont;
}

// Revisa si hay un espantapajaro cerca

bool Juego::revisarEspantapajaro(int x, int y)
{
    int inicioX = x-1;
    int inicioY = y-1;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            QString sEspanta = "Espantapajaro"+QString::number(inicioX+i)+QString::number(inicioY+j);
            QLabel *lEspanta = this->findChild<QLabel *>(sEspanta);
            if(lEspanta == NULL)
            {
                continue;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

void Juego::setTextCronometro(int indice)
{
    ui->labelTiempoMercado->setText(QString::number(indice));
}

//------------------------------
// Botón para acceder a mercado
//------------------------------

void Juego::botonMercado()
{
}

//------------------------------
// Botón para acceder al Top10
//------------------------------

void Juego::on_pushButton_4_clicked()
{
    Puntajes* windowPuntaje = new Puntajes();
    windowPuntaje->listScore = this->scoreList;
    windowPuntaje->insertScores();
    windowPuntaje->show();
}

void Juego::colocarGuardado()
{
    finca* myGranja = this->Granja;
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(this->Granja->myFinca[i][j]->ArbolAvl != NULL)
            {
                colocarGuardadoAvl(i,j);
            }
            else if(this->Granja->myFinca[i][j]->ArbolBinario != NULL)
            {
                colocarGuardadoOrdenado(i,j);
            }
            else if(this->Granja->myFinca[i][j]->ArbolHeap != NULL)
            {
                colocarGuardadoHeap(i,j);
            }
            else if(this->Granja->myFinca[i][j]->ArbolSplay != NULL)
            {
                colocarGuardadoSplay(i,j);
            }
            else
            {
            }
        }
    }
}

void Juego::colocarGuardadoAvl(int i, int j)
{
    QPixmap image("C:/Users/dnnxl/Downloads/CoolFarmImages/arbolAvl.png");
    QString xString = QString::number(i);
    QString yString = QString::number(j);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        lHierba->setObjectName("Avl"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
    }
}

void Juego::colocarGuardadoHeap(int i, int j)
{
    QPixmap image("C:/Users/dnnxl/Downloads/CoolFarmImages/arbolHeap.png");
    QString xString = QString::number(i);
    QString yString = QString::number(j);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        lHierba->setObjectName("Heap"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
    }
}

void Juego::colocarGuardadoOrdenado(int i, int j)
{
    QPixmap image("C:/Users/dnnxl/Downloads/CoolFarmImages/arbolOrdenado.png");
    QString xString = QString::number(i);
    QString yString = QString::number(j);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        lHierba->setObjectName("Ordenado"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
    }
}

void Juego::colocarGuardadoSplay(int i, int j)
{
    QPixmap image("C:/Users/dnnxl/Downloads/CoolFarmImages/arbolSplay.png");
    QString xString = QString::number(i);
    QString yString = QString::number(j);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        lHierba->setObjectName("Splay"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
    }
}

//------------------------------
// Botón para guardar el juego
//------------------------------

void Juego::on_pushButton_3_clicked()
{
    ListScores* n = new ListScores();
    this->reader->writerFile(n);
    this->scoreList = this->reader->readFile();
    this->scoreList->insertarOrdenado(this->name.c_str(),this->dinero);
    this->reader->writerFile(this->scoreList);
}

void Juego::on_pushButton_clicked()
{
    ui->bInsertarAvl->setDisabled(false);
    ui->bInsertarEspantapajaros->setDisabled(false);
    ui->bInsertarHeap->setDisabled(false);
    ui->bInsertarOrdenado->setDisabled(false);
    ui->bInsertarSplay->setDisabled(false);

    this->hCronometro->start(); // Empezar hilo
    this->hPlaga->start();
 }

//--------------------
// Colocar arboles
//--------------------

void Juego::colocarArbolHeap()
{
    QPixmap image("C:/Users/dnnxl/Downloads/arbolHeap.png");
    int x = (ui->Billy->x()-44)/78;
    int y = (ui->Billy->y()-122)/64;
    QString xString = QString::number(x);
    QString yString = QString::number(y);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        this->cantidadHeap = this->cantidadHeap-1;
        ui->lCantidadHeap->setText(QString::number(this->cantidadHeap ));
        lHierba->setPixmap(image);
        lHierba->setObjectName("Heap"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
        this->Granja->activarArbolHeap(x,y);
    }
}

void Juego::colocarArbolOrdenado()
{
    QPixmap image("C:/Users/dnnxl/Downloads/arbolOrdenado.png");

    int x = (ui->Billy->x()-44)/78;
    int y = (ui->Billy->y()-122)/64;
    QString xString = QString::number(x);
    QString yString = QString::number(y);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        this->cantidadOrdenado = this->cantidadOrdenado-1;
        ui->lCantidadOrdenado->setText(QString::number(this->cantidadOrdenado ));
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->setObjectName("Ordenado"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->show();
        this->Granja->activarArbolOrdenado(x,y);
    }
}

void Juego::colocarArbolSplay()
{
    QPixmap image("C:/Users/dnnxl/Downloads/arbolSplay.png");
    int x = (ui->Billy->x()-44)/78;
    int y = (ui->Billy->y()-122)/64;
    QString xString = QString::number(x);
    QString yString = QString::number(y);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        this->cantidadSplay = this->cantidadSplay-1;
        ui->lCantidadSplay->setText(QString::number(this->cantidadSplay ));
        lHierba->setObjectName("Splay"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
        this->Granja->activarArbolSplay(x,y);
    }
}

void Juego::colocarArbolAvl()
{
    QPixmap image("C:/Users/dnnxl/Downloads/ArbolAvl.png");
    int x = (ui->Billy->x()-44)/78;
    int y = (ui->Billy->y()-122)/64;
    QString xString = QString::number(x);
    QString yString = QString::number(y);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        this->cantidadAvl = this->cantidadAvl-1;
        ui->lCantidadAvl->setText(QString::number(this->cantidadAvl ));
        lHierba->setObjectName("Avl"+xString+yString); //Poner  Heap y posiion x y.
        lHierba->setPixmap(image);
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
        this->Granja->activarArbolAvl(x,y);
    }
}

void Juego::eliminarPlagaPorPosicion(int x, int y)
{

    int inicioX = x-1;
    int inicioY = y-1;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            QString sPlaga = "Plaga"+QString::number(inicioX+i)+QString::number(inicioY+j);
            QLabel *lPlaga = this->findChild<QLabel *>(sPlaga);
            if(lPlaga == NULL)
            {
                continue;
            }
            else
            {
                delete(lPlaga);
            }
        }
    }
}

void Juego::colocarEspantapajaros()
{
    QPixmap image("C:/Users/dnnxl/Downloads/scarecrow.png");
    int x = (ui->Billy->x()-44)/78;
    int y = (ui->Billy->y()-122)/64;
    QString xString = QString::number(x);
    QString yString = QString::number(y);
    QString posicionHierba = "hierba"+xString+yString;
    QLabel*lHierba = this->findChild<QLabel *>(posicionHierba); // Encontrar el label por medio del identificador.

    if(lHierba == NULL)
    {
        return;
    }
    else
    {
        lHierba->setPixmap(image);
        lHierba->setObjectName("Espantapajaro"+QString::number(x)+QString::number(y));
        this->cantidadEspantapajaro = this->cantidadEspantapajaro-1;
        ui->lCantidadEspanta->setText(QString::number(this->cantidadEspantapajaro ));
        lHierba->adjustSize();
        lHierba->setVisible(true);
        lHierba->show();
        eliminarPlagaPorPosicion(x,y);
    }
}

void Juego::on_bInsertarSplay_clicked()
{
    if(this->cantidadSplay > 0)
    {
        colocarArbolSplay();
    }
    else
    {
        return;
    }
}

void Juego::on_bInsertarOrdenado_clicked()
{
    if(this->cantidadOrdenado > 0)
    {
        colocarArbolOrdenado();
    }
    else
    {
        return;
    }
}

void Juego::on_bInsertarHeap_clicked()
{
    if(this->cantidadHeap > 0)
    {
        colocarArbolHeap();
    }
    else
    {
        return;
    }
}

void Juego::on_bInsertarAvl_clicked()
{
    if(this->cantidadAvl > 0)
    {
        colocarArbolAvl();
    }
    else
    {
        return;
    }
}

void Juego::on_bInsertarEspantapajaros_clicked()
{
    if(this->cantidadEspantapajaro > 0)
    {
        colocarEspantapajaros();
    }
    else
    {
        return;
    }
}

void Juego::on_botonMercado_clicked()
{
    mercado* tienda = new mercado(this);
    NodoDato * tmp = this->lDatos->buscarArbol("Mercado");
    tienda->cronometro->tiempoParaVender = tmp->Vender;
    tienda->dinero = this->dinero;
    this->Granja->recogerDatosDeLosArboles();
    tienda->ListaArbolesVender = this->Granja->ListaArbolesVender;

    tienda->colocarObjectos();

    tienda->show();
}

void Juego::on_pushButton_2_clicked()
{
    this->hCronometro->bandera = false;
}

void Juego::enColocarPlaga(int pCantidad, int pType)
{
    QMutex*mutex = new QMutex();
    mutex->lock();
    if(this->cuantasPlagas() == this->cuantosArboles())
    {

    }
    else
    {
        QPixmap image1("C:/Users/dnnxl/Downloads/cuervo.png");
        QPixmap image2("C:/Users/dnnxl/Downloads/gusano.png");
        QPixmap image3("C:/Users/dnnxl/Downloads/oveja.png");

        int V = rand()%8;
        int V2 = rand()%8;
        int x = V*78+44;
        int y =  V2*64+122;
        QString xString = QString::number(V);
        QString yString = QString::number(V2);
        QString sPlaga ;//= "Gusano"+xString+yString;

        if(pType == 0)
        {
            sPlaga = "Plaga"+xString+yString;
        }
        else if(pType == 1)
        {
            sPlaga = "Plaga"+xString+yString;
        }
        else
        {
            sPlaga = "Gusano"+xString+yString;
        }
        QLabel* plaga = this->findChild<QLabel *>(sPlaga);

        int cont = 0;
        while(cont != pCantidad)
        {
            QString heap = "Heap"+QString::number(V)+QString::number(V2);
            QString avl = "Avl"+QString::number(V)+QString::number(V2);
            QString ordenado = "Ordenado"+QString::number(V)+QString::number(V2);
            QString splay = "Splay"+QString::number(V)+QString::number(V2);

            QLabel* Heap = this->findChild<QLabel *>(heap);
            QLabel* Avl = this->findChild<QLabel *>(avl);
            QLabel* Ordenado = this->findChild<QLabel *>(ordenado);
            QLabel* Splay = this->findChild<QLabel *>(splay);

            QLabel* espanta = this->findChild<QLabel *>("Espantapajaro"+QString::number(V)+QString::number(V2));
            if(plaga==0 && (Heap != NULL || Avl != NULL || Ordenado != NULL || Splay != NULL))
            {
                QLabel*NewPlaga = new QLabel(this); // Encontrar el label por medio del identificador.
                NewPlaga->setGeometry(x,y,61,61);
                if(pType == 0)
                {
                    NewPlaga->setPixmap(image3);
                    NodoDato* datoOveja = this->lDatos->buscarArbol("Oveja");
                    int fruto = datoOveja->comeFruto1;
                    int tiempoFruto = datoOveja->comeFruto2;
                    this->Granja->myFinca[V][V2]->oveja = new Oveja(tiempoFruto,fruto);
                    cont++;

                }
                else if(pType == 1)
                {
                    NewPlaga->setPixmap(image1);
                    NodoDato* datoCuervo = this->lDatos->buscarArbol("Cuervo");
                    int fruto = datoCuervo->comeFruto1;
                    int tiempoFruto = datoCuervo->comeFruto2;
                    this->Granja->myFinca[V][V2]->cuervo = new Cuervo(tiempoFruto,fruto);
                    cont++;
                }
                else
                {
                    NewPlaga->setPixmap(image2);
                    NodoDato* datoGusano = this->lDatos->buscarArbol("Gusano");
                    int destruye = datoGusano->destruye;
                    this->Granja->myFinca[V][V2]->Gusano = new Plaga(destruye);
                    cont++;
                }
                NewPlaga->setObjectName(sPlaga); //Poner  Heap y posiion x y.
                NewPlaga->adjustSize();
                NewPlaga->setVisible(true);
                NewPlaga->show();
                continue;
            }
            else if(this->revisarEspantapajaro(V,V2))
            {
                V=rand()%8;
                V2=rand()%8;
                x = V*78+44;
                y =  V2*64+122;
                xString = QString::number(V);
                yString = QString::number(V2);
                if(pType == 0)
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                else if(pType == 1)
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                else
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                plaga = this->findChild<QLabel *>(sPlaga);
            }
            else
            {
                V=rand()%8;
                V2=rand()%8;
                x = V*78+44;
                y =  V2*64+122;
                xString = QString::number(V);
                yString = QString::number(V2);
                if(pType == 0)
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                else if(pType == 1)
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                else
                {
                    sPlaga = "Plaga"+xString+yString;
                }
                plaga = this->findChild<QLabel *>(sPlaga);
            }
        }
        mutex->unlock();
    }
}

void Juego::writerFileFinca(finca*pFinca) //escribe el archivo
{
    ofstream fsalida("C:/Users/dnnxl/Desktop/JuegoFinca.dat", ios::out | ios::binary);
    fsalida.write(reinterpret_cast<char *>(&pFinca),sizeof(pFinca));
    fsalida.close();
}

void Juego::writerFileConfiguracion(ListaDatos*pData) //escribe el archivo
{
    ofstream fsalida("C:/Users/dnnxl/Desktop/ConfiguracionFinca.dat", ios::out | ios::binary);
    fsalida.write(reinterpret_cast<char *>(&pData),sizeof(pData));
    fsalida.close();
}
