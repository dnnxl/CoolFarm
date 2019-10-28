#ifndef PUNTAJES_H
#define PUNTAJES_H

#include <QWidget>
#include <QFontDatabase>
#include "estructuras.h"

namespace Ui
{
class Puntajes;
}

class Puntajes : public QWidget
{
    Q_OBJECT

public:
    explicit Puntajes(QWidget *parent = 0);
    ~Puntajes();
    ListScores* listScore; // Los puntajes
    void insertScores(); // Inserta los puntajes

private slots:

private:
    Ui::Puntajes *ui;
};

#endif // PUNTAJES_H
