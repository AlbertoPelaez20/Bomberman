//
// Created by Zero on 28/06/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
#define PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H

#include "CEscenario.h"
#include <iostream>



class CBomberman {

private:
    RenderWindow *mapa;
    Texture Bomber;
    Sprite sprite;
    void   eventos();
    int x=0;
    int y=0;
    int dx;
    int dy;
    int alto;
    int ancho;
    int indicex;
    int indicey;



public:
  CBomberman( RenderWindow *_mapa, int x, int y);//posicion inicial;
 ~CBomberman(){};
  void dibujarBomberman();
  void moverBomberman( );
  //void mandosmanuales (Keyboard::Key key);

};


#endif //PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
