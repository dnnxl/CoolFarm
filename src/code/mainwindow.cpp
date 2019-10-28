#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->lDatos = new ListaDatos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::agarrarDatos()
{
    string name = ui->eName->text().toStdString();
    this->lDatos->insertarAlInicioNombre(name);

    int crece = ui->eTreeBinaryCrece->text().toInt();
    int cosecha = ui->eTreeBinaryCosecha1->text().toInt();
    int tiempoC = ui->billy->text().toInt();
    int precio1 = ui->eTreeBinaryPrecio1->text().toInt();
    int precio2 = ui->eTreeBinaryPrecio2->text().toInt();
    this->lDatos->insertarAlInicioArbol("Ordenado",crece,cosecha,tiempoC,precio1,precio2);

    int crece1 = ui->eTreeHeapCrece->text().toInt();
    int cosecha1 = ui->eHeapCosecha1->text().toInt();
    int tiempoCosecha1 = ui->eHeapCosecha2->text().toInt();
    int precio11 = ui->eTreeHeapPrecio1->text().toInt();
    int precio21 = ui->eTreeHeapPrecio2->text().toInt();
    this->lDatos->insertarAlInicioArbol("Heap",crece1,cosecha1,tiempoCosecha1,precio11,precio21);

    int crece2 = ui->eTreeAvlCrece->text().toInt();
    int cosecha2 = ui->eAvlCosecha1->text().toInt();
    int tiempoCosecha2 = ui->eAvlCosecha2->text().toInt();
    int precio12 = ui->eTreeAvlPrecio1->text().toInt();
    int precio22 = ui->eTreeAvlPrecio2->text().toInt();
    this->lDatos->insertarAlInicioArbol("Avl",crece2,cosecha2,tiempoCosecha2,precio12,precio22);

    int crece3 = ui->eTreeSplayCrece->text().toInt();
    int cosecha3 = ui->eTreeSplayCosecha1->text().toInt();
    int tiempoCosecha3 = ui->eTreeSplayCosecha2->text().toInt();
    int precio13 = ui->eTreeSplayPrecio1->text().toInt();
    int precio23 = ui->eTreeSplayPrecio2->text().toInt();
    this->lDatos->insertarAlInicioArbol("Splay",crece3,cosecha3,tiempoCosecha3,precio13,precio23);

    int abre = ui->eMercadoAbreCada->text().toInt();
    int vende = ui->eMercadoTiempoVenta->text().toInt();
    this->lDatos->insertarAlInicioMercado(abre,vende);

    int probabilidad = ui->eOvejaProbabilidad->text().toInt();
    int minuto1 = ui->eOvejaMinuto1->text().toInt();
    int minuto2 = ui->eOvejaMinuto2->text().toInt();
    int fruto = ui->eOvejaCome1->text().toInt();
    int tiempoFruto = ui->eOvejaCome2->text().toInt();
    this->lDatos->insertarAlInicioPlaga("Oveja",probabilidad,minuto1,minuto2,fruto,tiempoFruto);

    int probabilidad1 = ui->eCuervoProbabilidad->text().toInt();
    int minuto11 = ui->eCuervoMinuto1->text().toInt();
    int minuto21 = ui->eCuervoMinuto2->text().toInt();
    int fruto1 = ui->eCuervoCome1->text().toInt();
    int tiempoFruto1 = ui->eCuervoCome2->text().toInt();
    this->lDatos->insertarAlInicioPlaga("Cuervo",probabilidad1,minuto11,minuto21,fruto1,tiempoFruto1);

    int posibilidad = ui->eGusanosProbabilidad->text().toInt();
    int destruye = ui->eGusanosDestruye->text().toInt();
    this->lDatos->insertarAlInicioGusano("Gusano",destruye,posibilidad);

    this->lDatos->imprimir();
}

void MainWindow::on_bAceptar_clicked()
{
    agarrarDatos();
    Juego* windowGame = new Juego();
    windowGame->lDatos = this->lDatos;//Pasar los datos a la ventana Juego;
    windowGame->Granja->lDatos = this->lDatos;
    windowGame->setTiempoCronometro();
    windowGame->ponerNombreDinero();
    windowGame->asignarValues();
    windowGame->show();
    this->close();
}
