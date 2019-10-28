#include "mercado.h"
#include "ui_mercado.h"

#include <QPushButton>
mercado::mercado(Juego *parent, QWidget *parent2) :
    QWidget(parent2),
    ui(new Ui::mercado)
{
    this->ventana = parent;
    ui->setupUi(this);
    this->mercadoLista = new listaMercado();
    this->cronometro = new HiloCronometro(this);
    this->cronometro->tiempoParaVender = 0;
    this->cronometro->abiertoMercado = true;
    cronometro->Stop = false;
    cronometro->bandera = false;
    cronometro->abiertoJuego = false;
    this->cronometro->start();
    this->ListaArbolesVender = new ListNodoArbolMercado();
}

void mercado::setIndisponible()
{
    this->ui->pushButton_10->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_11->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_12->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_13->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_3->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_6->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_7->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_8->setText("Bloqueado");//setDisabled(true);
    this->ui->pushButton_9->setText("Bloqueado");//setDisabled(true);
}

void mercado::setTime(int i)
{
    ui->cronometro->setText(QString::number(i));
}

void mercado::colocarObjectos()
{
    ui->lDinero->setText(QString::number(this->dinero));
    this->mercadoListaComprado = new listaMercado();
    colocarArboles();
}

mercado::~mercado()
{
    delete ui;
}

void mercado::insertProductsLabels()
{
    Nodo* tmp = this->mercadoLista->primerNodo;
    while(tmp != NULL)
    {
        QFrame* viejo = new QFrame(ui->bMercadoAritulo); // Crea un frame.
        QLabel* nuevo = new QLabel(viejo); // Crea un label.
        nuevo->setGeometry(0,0,60,20);
        nuevo->setText(tmp->nombreMercado.c_str());
        nuevo->setVisible(true); // Visibilidad verdadera.
        viejo->setGeometry(11,this->x,800,60); // Tamaño.
        viejo->setVisible(true); // Es visible.
        viejo->show(); // Enseña.
        nuevo->show(); // Enseña.
        //Precios
        QLabel* nuevo2 = new QLabel(viejo); // Crea un label.
        nuevo2->setGeometry(200,0,60,20);
        nuevo2->setText(QString::number(tmp->precioMercado));
        nuevo2->setVisible(true); // Visibilidad verdadera.
        nuevo2->show(); // Enseña.

        QPushButton* pnuevo = new QPushButton(viejo); // Crea un label.
        pnuevo->setText("Comprar");//QString::number(tmp->contador)); // Coloca la cantidad.
        pnuevo->setObjectName(tmp->nombreMercado.c_str()); // Coloca un nombre al objecto, identificador importante.
        pnuevo->setVisible(true); // Visibilidad verdadera.
        pnuevo->setGeometry(800,0,150,20); // Tamaño.
        pnuevo->show(); // Enseña el label.
        this->h = this->h+30; // Aumenta la altura.
        this->x = this->x+23; // Aumenta el eje x.
        tmp = tmp->siguiente;
    }
}

void mercado::actualizarFrameArbol(float pPosicion)
{
    QString CantidadFrutos = "cantFrutos" + QString::number(pPosicion);
    QString MontoTotal = "monto" + QString::number(pPosicion);
    QString Vendidos = "vendidos" + QString::number(pPosicion);

    NodoArbolMercado* tmp = this->ListaArbolesVender->buscarArbol(pPosicion);

    QLabel*lCantidadFrutos = this->ui->bMercadoAgricultor->findChild<QLabel *>(CantidadFrutos); // Encontrar el label por medio del identificador.
    lCantidadFrutos->setText(QString::number(tmp->cantFrutos));

    QLabel*lMonto = this->ui->bMercadoAgricultor->findChild<QLabel *>(MontoTotal); // Encontrar el label por medio del identificador.
    lMonto->setText(QString::number(tmp->montoTotal));

    QLabel*lVendidos = this->ui->bMercadoAgricultor->findChild<QLabel *>(Vendidos); // Encontrar el label por medio del identificador.
    lVendidos->setText(QString::number(tmp->vendidos));
}

void mercado::venderTodoLosArboles()
{
    float dineroGanado = this->ListaArbolesVender->calcularDineroTodoVendido(this->dinero);
    this->dinero = dineroGanado; // Actualizar el dinero

    this->ListaArbolesVender->venderFrutosTodos();
    this->ui->lDinero->setText(QString::number(dineroGanado));
    NodoArbolMercado* tmp = this->ListaArbolesVender->primerNodo;
    while(tmp != NULL)
    {
        actualizarFrameArbol(tmp->ubicacion);

        int x = ((tmp->ubicacion*10)-((fmod(tmp->ubicacion*10, 10))))/10.0;
        int y = fmod(tmp->ubicacion*10, 10);
        NodoArbolMercado* ttmp = this->ListaArbolesVender->buscarArbol(tmp->ubicacion);
        int cantidad = ttmp->cantFrutos;
        this->ventana->Granja->eliminarFrutosVendidos(x,y,cantidad);
        tmp = tmp->siguiente;
    }
}

void mercado::colocarArboles()
{
    NodoArbolMercado* tmp = this->ListaArbolesVender->primerNodo;
    while(tmp != NULL)
    {
        QFrame* viejo = new QFrame(ui->bMercadoAgricultor); // Crea un frame.
        QLabel* arbol = new QLabel(viejo); // Crea un label.
        arbol->setGeometry(0,0,60,20);
        arbol->setText(tmp->nombre.c_str());
        arbol->setVisible(true); // Visibilidad verdadera.
        arbol->show(); // Enseña.

        viejo->setGeometry(11,this->x,800,60); // Tamaño.
        viejo->setVisible(true); // Es visible.
        viejo->show(); // Enseña.

        //Precios
        QLabel* ubicacion = new QLabel(viejo); // Crea un label.
        ubicacion->setGeometry(100,0,60,20);
        ubicacion->setText(QString::number(tmp->ubicacion));//n.c_str()); // Coloca el texto en el label, nombre del articulo.
        ubicacion->setVisible(true); // Visibilidad verdadera.
        ubicacion->show(); // Enseña.

        QLabel* cantFrutos = new QLabel(viejo); // Crea un label.
        cantFrutos->setGeometry(200,0,60,20);
        cantFrutos->setObjectName("cantFrutos"+QString::number(tmp->ubicacion)); ///////////////
        cantFrutos->setText(QString::number(tmp->cantFrutos));//n.c_str()); // Coloca el texto en el label, nombre del articulo.
        cantFrutos->setVisible(true); // Visibilidad verdadera.
        cantFrutos->show(); // Enseña.

        QLabel* montoTotal = new QLabel(viejo); // Crea un label.
        montoTotal->setGeometry(310,0,60,20);
        montoTotal->setObjectName("monto"+QString::number(tmp->ubicacion));/////////////////////
        montoTotal->setText(QString::number(tmp->montoTotal));//n.c_str()); // Coloca el texto en el label, nombre del articulo.
        montoTotal->setVisible(true); // Visibilidad verdadera.
        montoTotal->show(); // Enseña.

        QLabel* vendidos = new QLabel(viejo); // Crea un label.
        vendidos->setGeometry(420,0,60,20);
        vendidos->setObjectName("vendidos"+QString::number(tmp->ubicacion));///////////////////
        vendidos->setText(QString::number(tmp->vendidos));//n.c_str()); // Coloca el texto en el label, nombre del articulo.
        vendidos->setVisible(true); // Visibilidad verdadera.
        vendidos->show(); // Enseña.

        QLabel* perdidos = new QLabel(viejo); // Crea un label.
        perdidos->setGeometry(530,0,60,20);
        perdidos->setText(QString::number(tmp->perdidos));//n.c_str()); // Coloca el texto en el label, nombre del articulo.
        perdidos->setVisible(true); // Visibilidad verdadera.
        perdidos->show(); // Enseña.

        QCheckBox* pnuevo = new QCheckBox(viejo); // Crea un label.
        pnuevo->setObjectName(QString::number(tmp->ubicacion));//QString::number(tmp->contador)); // Coloca la cantidad.
        cout<<pnuevo->objectName().toStdString()<<endl;
        pnuevo->setVisible(true); // Visibilidad verdadera.
        pnuevo->setGeometry(600,0,70,20); // Tamaño.
        pnuevo->show(); // Enseña el label.
        this->h = this->h+30; // Aumenta la altura.
        this->x = this->x+23; // Aumenta el eje x.

        // Cuando compra rebajar dinero
        tmp = tmp->siguiente;

        // Configurar el boton que actualice el label y que actualice el label dinero.
    }
}

void mercado::on_pushButton_clicked()
{
    venderTodoLosArboles();
    this->ListaArbolesVender->imprimir();
}

void mercado::on_pushButton_3_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 50)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Ordenado");
        this->dinero = this->dinero - 50;
        ui->lDinero->setText(QString::number(this->dinero));
    }
}

void mercado::on_pushButton_13_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 70)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Avl");
        this->dinero = this->dinero - 70;
        ui->lDinero->setText(QString::number(this->dinero));
    }
}

void mercado::on_pushButton_12_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 90)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Heap");
        this->dinero = this->dinero - 90;
        ui->lDinero->setText(QString::number(this->dinero));
    }
}

void mercado::on_pushButton_10_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 100)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Splay");
        this->dinero = this->dinero - 100;
        ui->lDinero->setText(QString::number(this->dinero));
    }
}

void mercado::on_pushButton_9_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 150)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Gato");
        this->dinero = this->dinero - 150;
        ui->lDinero->setText(QString::number(this->dinero));
        ui->pushButton_9->setDisabled(true);
    }
}

void mercado::on_pushButton_8_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 200)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Perro");
        this->dinero = this->dinero - 200;
        ui->lDinero->setText(QString::number(this->dinero));
        ui->pushButton_8->setDisabled(true);
    }
}

void mercado::on_pushButton_7_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 300)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Vaca");
        this->dinero = this->dinero - 300;
        ui->lDinero->setText(QString::number(this->dinero));
        ui->pushButton_7->setDisabled(true);
    }
}

void mercado::on_pushButton_11_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 500)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Espantapajaros");
        this->dinero = this->dinero - 500;
        ui->lDinero->setText(QString::number(this->dinero));
    }
}

void mercado::on_pushButton_6_clicked()
{
    if(this->dinero == 0)
    {
        return;
    }
    else if(this->dinero < 1000)
    {
        return;
    }
    else
    {
        this->mercadoListaComprado->insertarAlInicioArticuloComprado(1,"Casa");
        this->dinero = this->dinero - 1000;
        ui->lDinero->setText(QString::number(this->dinero));
        ui->pushButton_6->setDisabled(true);
    }
}

void mercado::on_bAceptar_clicked()
{
    this->ventana->dinero = this->dinero;
    this->ventana->ui->lDinero->setText(QString::number(this->dinero));
    this->ventana->ListaArbolesVender = this->ListaArbolesVender;
    this->ventana->Granja->ListaArbolesVender = this->ListaArbolesVender;
    this->ventana->mercadoListaComprado = this->mercadoListaComprado;
    this->ventana->mercadoListaComprado->imprimir();
    this->cronometro->Stop = true;
    this->ventana->adaptarArticulosComprados();
    this->close();
}

void mercado::on_pushButton_2_clicked()
{
     NodoArbolMercado* tmp = this->ListaArbolesVender->primerNodo;
     this->ListaArbolesVender->imprimir();
    for (int i = 0; i < this->ListaArbolesVender->largo(); i++)
    {
        QCheckBox* check = ui->bMercadoAgricultor->findChild<QCheckBox *>(QString::number(tmp->ubicacion));
        if (check->checkState() == 0)
        {
            tmp = tmp->siguiente;
            continue;
        }
        else
        {
            float numero = check->objectName().toFloat();

            int x = ((numero*10)-((fmod(numero*10, 10))))/10.0;
            int y = fmod(numero*10, 10);
            NodoArbolMercado* ttmp = this->ListaArbolesVender->buscarArbol(numero);
            int cantidad = ttmp->cantFrutos;
            this->ventana->Granja->eliminarFrutosVendidos(x,y,cantidad);
            int dinero = this->ListaArbolesVender->calcularDinero(numero,this->dinero);
            this->dinero = dinero;
            ui->lDinero->setText(QString::number(dinero));
            this->ListaArbolesVender->venderFrutos(numero);
            actualizarFrameArbol(numero);
            tmp = tmp->siguiente;
        }
    }
}
