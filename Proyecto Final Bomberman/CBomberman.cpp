#include "CBomberman.h"
//
// Created by Zero on 28/06/2020.
//

#include "CBomberman.h"

CBomberman ::CBomberman(RenderWindow *_mapa, int x, int y)
{
    mapa=_mapa;
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
    RectangleShape rectangle(Vector2f(0, 50));
    rectangle.setSize(Vector2f(38, 25));
    //RectangleShape shape;
    rectangle.setPosition(52, 95);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(Color(250, 250, 250));
    rectangle.setFillColor(Color( 255, 255, 255, 0));

    this->rectangle=rectangle;    //CircleShape shape(50);

    RectangleShape rectangleA(Vector2f(0, 50));
    rectangleA.setSize(Vector2f(38, 25));
    //RectangleShape shape;
    rectangleA.setPosition(52, 95);
    rectangleA.setOutlineThickness(2.f);
    rectangleA.setOutlineColor(Color(250, 250, 100));
    rectangleA.setFillColor(Color( 255, 255, 255, 0));

    this->rectangleA=rectangleA;    //CircleShape shape(50);
    //mapa->draw(rectangleA);
   // mapa->draw(rectangle);

    x=52;
    y=44;
    Bomber.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/Jugador.png");
    Sprite sprite(Bomber);
    sprite.scale(3,3);
    //this->sprite=sprite;
    sprite.move(52, 44);
    sprite.setTextureRect(IntRect(0, 52, 17, 26));
    sprite.setOrigin(0,0);


    this->sprite=sprite;
    mapa->draw(sprite);
}



void CBomberman ::  moverBombermanDerecha(  ) {

    if ( 42 <= x && x < 752 ) {


            x += 10;


            if (dx <= 34) {
                dx += 19;

            } else
                dx = 17;
            sprite.move(+10, 0);
            sprite.setTextureRect(IntRect(dx, 25, 17, 26));
            rectangle.setPosition(x+5,y+52);
            //rectangleA.setPosition(x+5,y+25);
            rectangleA.setPosition(x,y+50);
            //mapa->draw(rectangleA);
           // mapa->draw(rectangle);
            mapa->draw(sprite);

    }
    else

    sprite.setTextureRect(IntRect(17, 25, 17, 26));
    mapa->draw(sprite);

    //cout<<""<<endl;

}



void CBomberman ::  moverBombermanIzquierda(  ) {

    if ( 52 <= x && x <= 752 ) {
        x -= 10;


        if (dx < 34) {
            dx += 19;

        } else dx =0;
        sprite.move(-10, 0);
        //rectangle.setPosition(x-6,y+52);
        rectangle.setPosition(x+5,y+52);
        //mapa->draw(rectangle);
        rectangleA.setPosition(x+10,y+45);
       // mapa->draw(rectangleA);
        sprite.setTextureRect(IntRect(17 + dx, 77, 17, 26));
        mapa->draw(sprite);
    }
    else
        sprite.setTextureRect(IntRect(17, 77, 17, 26));
        mapa->draw(sprite);


}



void CBomberman ::moverBombermaArriba() {

    if ( 4 < y && y <= 524 ) {
        y -= 10;


        if (dx <= 34) {
            dx += 17;

        } else dx = 0;
        sprite.move(0, -10);
        sprite.setTextureRect(IntRect(dx, 0, 17, 26));
        mapa->draw(sprite);
        rectangle.setPosition(x+5,y+52);
        rectangleA.setPosition(x,y+45);
       // mapa->draw(rectangleA);
       // mapa->draw(rectangle);
    }
        else
                sprite.setTextureRect(IntRect(0, 0, 17, 26));
                mapa->draw(sprite);


}

void CBomberman :: setcerodx()
{
    this->dx=0;


}



void CBomberman ::moverBombermanAbajo() {

    if ( 4 <= y && y < 524 ) {
    y += 10;


    if (dy <= 34) {
        dy += 25;

    } else dy = 25;
    sprite.move(0, +10);
    sprite.setTextureRect(IntRect(0, 28 + dy, 17, 26));
       // rectangle.setPosition(x+5,y+52);
        rectangle.setPosition(x+5,y+52);
       rectangleA.setPosition(x+5,y+55);
      // mapa->draw(rectangleA);
     //   mapa->draw(rectangle);
    mapa->draw(sprite);
    }
    else
        sprite.setTextureRect(IntRect(0, 52, 17, 26));
        mapa->draw(sprite);


}


