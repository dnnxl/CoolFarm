#ifndef PRINCIPALWINDOW_H
#define PRINCIPALWINDOW_H

#include <QWidget>
#include "info.h" // Para acceder a la ventana de información
#include "mainwindow.h"
#include "estructuras.h"

namespace Ui
{
class principalWindow;
}

class principalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit principalWindow(QWidget *parent = 0);
    ~principalWindow();
    finca* readFileFinca();
    ListaDatos* readFileConfiguracion();


private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_Play_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::principalWindow *ui;
};

#endif // PRINCIPALWINDOW_H
