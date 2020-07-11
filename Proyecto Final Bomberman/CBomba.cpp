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
}

void CBomba ::estado_normal()

{

        sprite.setTextureRect(IntRect(0, 40, 20, 25));
         this->sprite=sprite;


}