//
// Created by Zero on 28/06/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
#define PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H

#include "CEscenario.h"
#include"funciones.h"
#include"CBomba.h"
class CBomberman {
private:
    RenderWindow *mapa;
    Texture Bomber;
    int alto;
    int ancho;
    int indicex;
    int indicey;
    RectangleShape C;


public:
    CBomba *bomba1;
    bool validar;
    int dx;
    int dy;
    int **mapabomberman;
    int x;
    int y;
    Sprite sprite;
    RectangleShape rectangle;
    RectangleShape rectangleA;
    Sprite Bomba;
  CBomberman( RenderWindow *_mapa, int x, int y,int **&matriz);//posicion inicial;
  ~CBomberman(){};
  void dibujarBomberman();
  void moverBombermanDerecha( );
    void moverBombermanIzquierda( );
    void moverBombermaArriba();
    void moverBombermanAbajo();
  void setPosx(int x){ this->x=x;}
  int getPosx(){return x;}
  int getPosy(){return y;}
  bool validarmovimientovertical();
   void validarmovimientohorizontal();
   void setcerodx();
   void hacermatriz();
   void ponerbomba();
   void validarpared();
    void  tiempo1();
    void destruirBomba();



};


#endif //PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
