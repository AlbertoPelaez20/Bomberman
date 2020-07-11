//
// Created by Zero on 28/06/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
#define PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H

#include "CEscenario.h"
#include "CBomberman.h"

class CControlmapa {

private:
    RenderWindow *mapa;
    int **mapalocal;
    CEscenario *Nuevo;
    CBomberman *Bomberman;
    RectangleShape   C;
public:
    bool val;
    CControlmapa(RenderWindow *_mapa);
    ~CControlmapa(){};
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

};


#endif //PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
