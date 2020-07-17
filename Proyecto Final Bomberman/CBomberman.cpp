#include "CBomberman.h"

//
// Created by Zero on 28/06/2020.
//



CBomberman ::CBomberman(RenderWindow *_mapa, int x, int y,int **&matriz )

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
     this->mapabomberman=matriz;
    C.setSize(Vector2f(50, 40));
}
void CBomberman :: hacermatriz() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) { cout << mapabomberman[i][j]<<" "; }
        cout << endl;
    }
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
    rectangleA.setPosition(60, 95);
    rectangleA.setOutlineThickness(2.f);
    rectangleA.setOutlineColor(Color(250, 250, 100));
    rectangleA.setFillColor(Color( 255, 255, 255, 0));
    this->rectangleA=rectangleA;
    x=52;
    y=44;
    Bomber.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/Jugador.png");
    Sprite sprite(Bomber);
    sprite.scale(3,3);
    sprite.move(52, 44);
    sprite.setTextureRect(IntRect(0, 52, 17, 26));
    sprite.setOrigin(0,0);
    this->sprite=sprite;
    mapa->draw(sprite);
}
void  CBomberman ::validarmovimientohorizontal() {
    int X = 0;
    int Y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;
            if (mapabomberman[i][j] == 1 || mapabomberman[i][j] == 3) {
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
bool CBomberman :: validarmovimientovertical()
{    int X = 0;
    int Y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;
            if (mapabomberman[i][j] == 1 || mapabomberman[i][j] == 3) {
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
    void CBomberman::moverBombermanDerecha()
    {   validar=true;
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
void CBomberman ::  moverBombermanIzquierda(  ) {
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
void CBomberman ::moverBombermaArriba() {
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

void CBomberman :: setcerodx() {
    this->dx = 0;
}
void CBomberman ::moverBombermanAbajo() {
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

void CBomberman ::ponerbomba()
{
    bomba1 = new CBomba(mapa,x,y,mapabomberman);
    bomba1->dibujarbomba();
    this->Bomba=bomba1->sprite;
    //mapa->draw(bomba1->sprite);
    mapa->draw(Bomba);
    mapa->draw(bomba1->rectanguloexplosion);

}

void CBomberman ::validarpared()
{
    int X = 0;
    int Y = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;
            if ( mapabomberman[i][j] == 3) {
                 C.setPosition(X - 50, Y);
                mapa->draw(C);
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

void CBomberman :: tiempo1()
        {


            bomba1->estado_normal();
            this->Bomba=bomba1->sprite;
            mapa->draw(Bomba);

        }

void CBomberman :: destruirBomba()
{


}