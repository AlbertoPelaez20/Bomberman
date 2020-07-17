//
// Created by Zero on 17/07/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CENEMIGOS_H
#define PROYECTO_FINAL_BOMBERMAN_CENEMIGOS_H

#include "CPersonajes.h"

class CEnemigos : public CPersonajes {

private:

    RenderWindow *mapa;
    Texture Enemigo;
    RectangleShape C;
public:

    bool validar;
    int dx;
    int dy;
    int **mapenemigo;
    int x;
    int y;
    Sprite sprite;
    RectangleShape rectangle;
    RectangleShape rectangleA;

    CEnemigos(){};
    CEnemigos(RenderWindow *mapa, int **mapenemigo, int x, int y) : mapa(mapa), mapenemigo(mapenemigo), x(x), y(y) {}

    virtual ~CEnemigos(){};

    void dibujarBomberman() override ;
    void moverBombermanDerecha( )override ;
    void moverBombermanIzquierda( )override ;
    void moverBombermaArriba()override ;
    void moverBombermanAbajo()override ;
    void setPosx(int x){ this->x=x;}
    int getPosx(){return x;}
    int getPosy(){return y;}
    bool validarmovimientovertical()override ;
    void validarmovimientohorizontal()override ;
    void mostrarenemigos();
    void movimiento_aleatorio();


};


#endif //PROYECTO_FINAL_BOMBERMAN_CENEMIGOS_H
