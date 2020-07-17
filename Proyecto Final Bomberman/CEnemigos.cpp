//
// Created by Zero on 17/07/2020.
//
#include "funciones.h"
#include "CEnemigos.h"


void CEnemigos ::  dibujarBomberman()
{
    RectangleShape rectangle(Vector2f(0, 50));
    rectangle.setSize(Vector2f(42, 45));
    rectangle.setPosition(752, 525);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(Color(250, 250, 250));
    rectangle.setFillColor(Color( 255, 255, 255, 0));
    this->rectangle=rectangle;
    RectangleShape rectangleA(Vector2f(0, 50));
    rectangleA.setSize(Vector2f(38, 25));
    rectangleA.setPosition(780, 550);
    rectangleA.setOutlineThickness(2.f);
    rectangleA.setOutlineColor(Color(250, 250, 100));
    rectangleA.setFillColor(Color( 255, 255, 255, 0));
    this->rectangleA=rectangleA;
    Enemigo.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/bmpEnemigo.png");
    Sprite sprite(Enemigo);
    sprite.scale(2.8,2.8);
    sprite.move(779, 550);
    sprite.setTextureRect(IntRect(80, 0, 16, 16));
    sprite.setOrigin(10,10);
    this->sprite=sprite;
    mapa->draw(sprite);
    mapa->draw(rectangle);
    //mapa->draw(rectangleA);
}
void  CEnemigos :: mostrarenemigos()
{
    mapa->draw(sprite);
    mapa->draw(rectangle);
}

void CEnemigos ::  moverBombermanDerecha( )
{

    validar=true;
    rectangle.setPosition(sprite.getPosition().x+10,sprite.getPosition().y+52);
    if (dx <= 34) dx += 19;
    else dx = 17;
    validarmovimientohorizontal();
    if (validar){
        sprite.move(+10, 0);
        x += 10;
    }
    sprite.setTextureRect(IntRect(dx, 25, 17, 26));
    //mapa->draw(rectangle);
    mapa->draw(sprite);

}


void CEnemigos ::   moverBombermanIzquierda( )
{
    validar=true;
    rectangle.setPosition(sprite.getPosition().x-5,sprite.getPosition().y+52);
    if (dx < 34) {
        dx += 19;
    } else dx =0;
    validarmovimientohorizontal();
    if (validar){
        sprite.move(-10, 0);
        x -= 10;
    }
    sprite.setTextureRect(IntRect(17 + dx, 77, 17, 26));
    mapa->draw(sprite);
}


void  CEnemigos :: moverBombermaArriba()
{
    validar=true;
    rectangleA.setPosition(sprite.getPosition().x+8,sprite.getPosition().y+40);
    if (dx <= 34) {
        dx += 17;
    } else dx = 0;
    validarmovimientovertical();
    if (validar){
        sprite.move(0, -10);
        y -= 10;
    }
    sprite.setTextureRect(IntRect(dx, 0, 17, 26));
    mapa->draw(sprite);
}
void  CEnemigos :: moverBombermanAbajo()
{
    validar=true;
    rectangleA.setPosition(sprite.getPosition().x+8,sprite.getPosition().y+65);
    if (dy <= 34) {
        dy += 25;
    } else dy = 25;
    validarmovimientovertical();
    if (validar){
        sprite.move(0, +10);
        y+=10;
    }
    sprite.setTextureRect(IntRect(0, 28 + dy, 17, 26));
    mapa->draw(sprite);
}

bool CEnemigos :: validarmovimientovertical()
{
    int X = 0;
    int Y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;
            if (mapenemigo[i][j] == 1 || mapenemigo[i][j] == 3) {
                // C.setPosition(X - 50, Y);
                //mapa->draw(C);
                IntRect r1(X-50, Y, 50, 40);
                IntRect r3 (rectangleA.getPosition().x,rectangleA.getPosition().y,40,25);
                IntRect result;
                IntRect result2;
                bool b= r1.intersects(r3,result);
                if (b==true)  validar =false;
            }
        } X = 0;
        Y += 43;
    }
}

void CEnemigos :: movimiento_aleatorio()
{  int a;
    srand(time(nullptr));
   a= rand()%4;

   if (a==0)
   {
       if ( validarmovimientovertical() )moverBombermanAbajo();
   }
    if (a==1)
    {
        if ( validarmovimientovertical() ) moverBombermaArriba();
    }
    if ( a==2 )
    {
        validarmovimientohorizontal();
        if (validar) moverBombermanIzquierda();
    }
    if ( a==3 && validarmovimientovertical())
    {
        validarmovimientohorizontal();
        if (validar) moverBombermanDerecha();
    }
 }



void CEnemigos :: validarmovimientohorizontal()
{
    int X = 0;
    int Y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;
            if (mapenemigo[i][j] == 1 || mapenemigo[i][j] == 3) {
                //C.setPosition(X - 50, Y);
                //mapa->draw(C);
                IntRect r1(X-50, Y, 50, 40);
                IntRect r2 (this->rectangle.getPosition().x, this->rectangle.getPosition().y,40,25);
                IntRect result2;
                bool b= r1.intersects(r2,result2);
                if (b==true) validar =false;
            }
        } X = 0;
        Y += 43;
    }
}