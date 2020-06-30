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

public:
    CControlmapa(RenderWindow *_mapa);
    ~CControlmapa(){};
    void Crearmapa();
    void Mostrarmapa();
    void moverbomber();

    void timer();
};


#endif //PROYECTO_FINAL_BOMBERMAN_CCONTROLMAPA_H
