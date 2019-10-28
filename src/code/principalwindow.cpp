#include "principalwindow.h"
#include "ui_principalwindow.h"

principalWindow::principalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principalWindow)
{
    ui->setupUi(this);
    ui->Play->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
}

principalWindow::~principalWindow()
{
    delete ui;
}

void principalWindow::on_pushButton_5_clicked()
{
    ui->Play->setDisabled(false); // Pone el botón play desbloqueado.
    MainWindow* windowConfiguration = new MainWindow();
    windowConfiguration->show();
    this->close();
}

void principalWindow::on_pushButton_6_clicked()
{
    info* windowInformation = new info(); // Información
    windowInformation->show();
}

void principalWindow::on_pushButton_4_clicked()
{
    Puntajes*windowPuntaje = new Puntajes(); // Ventana Puntajes.
    windowPuntaje->show(); // Enseña la ventana.
    FileReader*leer = new FileReader(); // Crea un objecto FileReader para leer.
    ListScores*n = new ListScores(); //Lista de puntuaciones.
   /* leer->writerFile(n); //*/
    windowPuntaje->listScore = leer->readFile(); // Leer el ReaderFile
    if(windowPuntaje->listScore  == NULL)
    {
        windowPuntaje->listScore = n;
        windowPuntaje->insertScores(); // Inserta las puntuaciones.
    }
    else
        windowPuntaje->insertScores(); // Inserta las puntuaciones.
}

void principalWindow::on_Play_clicked()
{
    Juego* windowJuego = new Juego(); // Jugar núevo juego
    windowJuego->Granja =  readFileFinca();
    windowJuego->lDatos = readFileConfiguracion();
    windowJuego->colocarGuardado();
    windowJuego->setTiempoCronometro();
    windowJuego->ponerNombreDinero();
    windowJuego->asignarValues();
    windowJuego->show();
}

finca* principalWindow::readFileFinca() //lee el archivo
{
    finca*tmp;
    ifstream fentrada("C:/Users/dnnxl/Desktop/JuegoFinca.dat",ios::in | ios::binary);
    fentrada.read(reinterpret_cast<char *>(&tmp), sizeof(finca));
    fentrada.close();
    if(tmp==NULL)
    {
        tmp = new finca();
        return tmp;
    }
    else
        return tmp;
}

ListaDatos* principalWindow::readFileConfiguracion() //lee el archivo
{
    ListaDatos*tmp;
    ifstream fentrada("C:/Users/dnnxl/Desktop/ConfiguracionFinca.dat",ios::in | ios::binary);
    fentrada.read(reinterpret_cast<char *>(&tmp), sizeof(ListaDatos));
    fentrada.close();
    if(tmp==NULL)
    {
        tmp = new ListaDatos();
        return tmp;
    }
    else
        return tmp;
}

void principalWindow::on_pushButton_3_clicked()
{
    Juego* windowJuego = new Juego(); // Jugar núevo juego
    windowJuego->Granja =  readFileFinca();
    windowJuego->lDatos = readFileConfiguracion();
    windowJuego->colocarGuardado();
    windowJuego->setTiempoCronometro();
    windowJuego->ponerNombreDinero();
    windowJuego->asignarValues();
    windowJuego->show();
}
