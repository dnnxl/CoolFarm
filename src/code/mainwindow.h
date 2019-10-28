#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "juego.h"
#include "estructuras.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void agarrarDatos();
    ListaDatos* lDatos;

private slots:
    void on_bAceptar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
