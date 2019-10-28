#include "puntajes.h"
#include "ui_puntajes.h"

Puntajes::Puntajes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Puntajes)
{
    ui->setupUi(this);
}

Puntajes::~Puntajes()
{
    delete ui;
}

void Puntajes::insertScores()
{
    nodoPts* tmp = this->listScore->primerPts;
    int x = 20;
    int h = 30;
    while(tmp != NULL)//->siguientePts
    {
        QFrame* viejo = new QFrame(ui->bbTop10); // Crea un frame.
        QLabel* nuevo = new QLabel(viejo); // Crea un label.
        nuevo->setSizePolicy(QSizePolicy::QSizePolicy::Maximum,QSizePolicy::Maximum);
        string n = tmp->nombrePuntos; // El nombre del nodo Botella.
        nuevo->setText(n.c_str()); // Coloca el texto en el label.
        nuevo->setVisible(true); // Visibilidad verdadera.
        nuevo->setGeometry(40 ,0,100,20); // Tamaño.
        QFont f( "Kristen ITC", 10);//, QFont::Bold);
        nuevo->setFont(f);
        viejo->setGeometry(11,x,300,100); // Tamaño.
        viejo->setVisible(true); // Es visible.
        viejo->show(); // Enseña.
        h = h+30; // Aumenta la altura.
        x = x+23; // Aumenta el eje x.
        nuevo->show(); // Enseña.
        QLabel* pnuevo = new QLabel(viejo); // Crea un label.
        pnuevo->setSizePolicy(QSizePolicy::QSizePolicy::Maximum,QSizePolicy::Maximum);
        pnuevo->setText(QString::number(tmp->dineroPuntos)); // Coloca la cantidad.
        pnuevo->setObjectName(n.c_str()); // Coloca un nombre al objecto, identificador importante.
        pnuevo->setVisible(true); // Visibilidad verdadera.
        pnuevo->setGeometry(210 ,0,80,15); // Tamaño.
        pnuevo->show(); // Enseña el label.
        pnuevo->setFont(f);
        tmp = tmp->siguientePts; // Apunta a
    }
}
