//
// Created by Zero on 10/07/2020.
//

#include "CBomba.h"

CBomba ::CBomba(RenderWindow *_mapa, int x, int y,int **&matriz)
{
    mapa=_mapa;
    this->x=x;
    this->y=y;
    mapabomba=matriz;
    dx=0;

}
bool CBomba ::validaposicion() {
    if (mapabomba[x/42][y/50] == 0 || mapabomba[x / 50][y / 50] == 2) return true;
    else return false;
}


void CBomba::dibujarbomba()

{
     Bomba.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/bomba.png");
     Sprite sprite(Bomba);
     sprite.move(x, y+20);
     sprite.setTextureRect(IntRect(0, 0, 20, 25));
     sprite.scale(2.5,2.5);

    this->sprite=sprite;
    //mapa->draw(sprite);
    RectangleShape rectangle(Vector2f(0, 50));
    rectangle.setSize(Vector2f(38, 25));
    //RectangleShape shape;
    rectangle.setPosition(52, 95);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(Color(250, 250, 250));
    rectangle.setFillColor(Color( 255, 255, 255, 0));
    this->rectanguloexplosion=rectangle;
    mapa->draw(rectanguloexplosion);

    Explosion.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/explosion.png");
    Sprite explosion(Explosion);
    explosion.move(x, y+40);
    explosion.scale(2.5,2.5);
    explosion.setTextureRect(IntRect(0, 0, 20, 20));
    this->explosion=explosion;


}

void CBomba ::estado_normal()
{
}
void CBomba ::estado_desaparicion()
{





}