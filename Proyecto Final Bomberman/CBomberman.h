//
// Created by Zero on 28/06/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
#define PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H

#include "CEscenario.h"
#include"funciones.h"
#include"CBomba.h"
#include "CPersonajes.h"



class CBomberman : public CPersonajes   {
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
    CBomberman(){};
    CBomberman( RenderWindow *_mapa, int x, int y,int **&matriz);



    virtual ~CBomberman(){};



   void dibujarBomberman()override ;
  void moverBombermanDerecha( )override ;
   void moverBombermanIzquierda( )override ;
   void moverBombermaArriba()override ;
 void moverBombermanAbajo()override ;
  void setPosx(int x){ this->x=x;}
  int getPosx(){return x;}
  int getPosy(){return y;}
   bool validarmovimientovertical()override ;
  void validarmovimientohorizontal()override ;
  void setcerodx();
  void hacermatriz();
  void ponerbomba();
  void validarpared();
  void  tiempo1();
  void destruirBomba();



};


#endif //PROYECTO_FINAL_BOMBERMAN_CBOMBERMAN_H
