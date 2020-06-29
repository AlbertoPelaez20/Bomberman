#include "CBomberman.h"
//
// Created by Zero on 28/06/2020.
//

#include "CBomberman.h"

CBomberman ::CBomberman(RenderWindow *_mapa, int x, int y)
{    mapa=_mapa;
     this->x=x;
     this->y=y;
     dx=0;
     dy=0;
     ancho=18;
     alto=16;
     indicex=0;
     indicey=0;

   /*
    Sprite sprite(Bomber);
    sprite.scale(2.8,2.8);
    sprite.move(52, 44);
    sprite.setTextureRect(IntRect(0, 52, 17, 26));
    sprite.setOrigin(0,0);
    mapa->draw(sprite);
*/
}

void CBomberman ::  dibujarBomberman(   )
{
    Bomber.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/Jugador.png");
    Sprite sprite(Bomber);
    this->sprite=sprite;
    sprite.scale(2.8,2.8);
    sprite.move(52, 44);
    sprite.setTextureRect(IntRect(0, 52, 17, 26));
    sprite.setOrigin(0,0);
    mapa->draw(sprite);
    x += dx;
    y += dy;
}

void CBomberman ::  moverBomberman(  ) {


    sprite.scale(2.8,2.8);
    sprite.move(80, 50);
    mapa->draw(sprite);



}











