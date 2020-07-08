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


   //void   eventos();

    int dx;
    int dy;
    int alto;
    int ancho;
    int indicex;
    int indicey;




public:
    int **mapalocal;
    int x;
    int y;
    int avanzeh=0;
    int avanzev=0;
    Sprite sprite;
    RectangleShape rectangle;
    RectangleShape rectangleA;
  CBomberman( RenderWindow *_mapa, int x, int y);//posicion inicial;
 ~CBomberman(){};
  void dibujarBomberman();
  void moverBombermanDerecha( );
    void moverBombermanIzquierda( );
    void moverBombermaArriba();
    void moverBombermanAbajo();
  //void mandosmanuales (Keyboard::Key key);
  void setPosx(int x){ this->x=x;}
  int getPosx(){return x;}
  int getPosy(){return y;}
 bool validarmovimientovertical();
   bool validarmovimientohorizontal();

   void setcerodx();

};


#endif //PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
