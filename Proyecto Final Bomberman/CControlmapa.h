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
    CEscenario *Nuevo;
    CBomberman *Bomberman;
    CEscenario const mapa1;
    int **mapalocal;
    RectangleShape   C;
    //IntRect r1;
    //IntRect r2;



public:
    bool val;
    CControlmapa(RenderWindow *_mapa);
    ~CControlmapa(){};
    void Crearmapa();
    void Mostrarmapa();
    void   mando(Keyboard::Key key, bool isPressed);
    void moverbomberDerecha();
    void moverbomberIzquierda();
    void moverbomberArriba();
    void moverbomberAbajo();
    int getPosx(){return Bomberman->getPosx();}
    int getPosy(){return Bomberman->getPosy();}
    void setPosx();
    void timer();
    void validarmovimientohorizontal();
    void validarmovimientovertical();
    bool intersects (const RectangleShape & rect1,const RectangleShape & rect2);
};


#endif //PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
