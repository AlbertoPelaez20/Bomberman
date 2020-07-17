//
// Created by Zero on 28/06/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
#define PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H

#include "CEscenario.h"
#include "CBomberman.h"
#include "CEnemigos.h"


class CControlmapa  {

private:
    RenderWindow *mapa;
    int **mapalocal;

public:
    CEscenario *Nuevo;
    CEnemigos *Enemigo;
    CBomberman *Bomberman;
    RectangleShape   C;
    bool val;
    CControlmapa(RenderWindow *_mapa);
    ~CControlmapa();
    void Crearmapa();
    void moverbomberDerecha();
    void moverbomberIzquierda();
    void moverbomberArriba();
    void moverbomberAbajo();
    int getPosx(){return Bomberman->getPosx();}
    int getPosy(){return Bomberman->getPosy();}
    void setPosx();
    void timer();
    void crearbomba();
    void tiempobomba1();
    void muestra_enemigos();

};


#endif //PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
