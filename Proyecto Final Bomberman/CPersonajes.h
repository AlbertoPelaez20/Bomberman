//
// Created by Zero on 17/07/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CPERSONAJES_H
#define PROYECTO_FINAL_BOMBERMAN_CPERSONAJES_H

#include "funciones.h"

class CPersonajes {

protected:
private:
    int x;
    int y;

public:

    CPersonajes();
    ~CPersonajes(){};

    virtual  void dibujarBomberman()=0;
    virtual  void moverBombermanDerecha()=0;
    virtual  void moverBombermanIzquierda()=0;
    virtual  void moverBombermaArriba()=0;
    virtual  void moverBombermanAbajo()=0;
    virtual  void setPosx(int x){ this->x=x;}
    virtual int getPosx(){return x;}
    virtual int getPosy(){return y;}
    virtual bool validarmovimientovertical()=0;
    virtual void validarmovimientohorizontal()=0;

};


#endif //PROYECTO_FINAL_BOMBERMAN_CPERSONAJES_H
