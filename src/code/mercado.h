#ifndef MERCADO_H
#define MERCADO_H

#include <QWidget>
#include <QCheckBox>
#include "estructuras.h"
#include "juego.h"

class Juego;
class HiloCronometro;

namespace Ui
{
class mercado;
}

class mercado : public QWidget
{
    Q_OBJECT

public:
    explicit mercado(Juego *parent = 0, QWidget* parent2 = 0);
    ~mercado();
    Juego *ventana; //puntero del juego
    void colocarArticulos(); //posicionar el ariculo en la matriz
    void colocarArboles(); //colocar los arboles en el juego
    void insertProductsLabels(); //insetar los productos
    void actualizarFrameArbol(float pPosicion); //actualizar el frame de cada arbol
    void venderTodoLosArboles(); //vender todos los arboles del juego
    void colocarObjectos(); //colocar los objetos
    void setTime(int i); //set de tiempo
    void setIndisponible(); //set en los espacios disponibles
    Ui::mercado *ui;
    listaMercado *mercadoLista; //lista de mercado lista
    int h = 81;
    int x = 15;
    int dinero; //= 5000;
    listaMercado *mercadoListaComprado; //lista de lo que se ha comprado en el mercado
    ListNodoArbolMercado *ListaArbolesVender; //lista de lso arboles para vender
    HiloCronometro *cronometro; //puntero para el hilo cronometro

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_6_clicked();
    void on_bAceptar_clicked();
    void on_pushButton_2_clicked();

private:
};

#endif // MERCADO_H
