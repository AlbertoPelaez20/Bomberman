//
// Created by Zero on 28/06/2020.
//

#include "CControlmapa.h"


 CControlmapa :: CControlmapa (RenderWindow *_mapa)  {
     mapa=_mapa;
     Nuevo =  new CEscenario(mapa);
     Bomberman = new CBomberman(mapa,0,0,Nuevo->matriz);
     Enemigo= new CEnemigos(mapa,Nuevo->matriz,0,0);
     Crearmapa();
     mapalocal=Nuevo->matriz;
     Bomberman->dibujarBomberman();
     C.setSize(Vector2f(50, 40));
     Enemigo->dibujarBomberman();

    }


void CControlmapa ::setPosx()
{
    Bomberman->setPosx(0);
}
void CControlmapa ::  Crearmapa()
{
 Nuevo->generarmapa();
 Nuevo->PintarMapa();
 Nuevo->Pintarpiso();
 Nuevo->Pintarobstaculo();
 }
 void CControlmapa ::moverbomberDerecha()
{
     Nuevo->mostrar();
     mapa->draw(Enemigo->sprite);
     mapa->draw(Bomberman->Bomba);
     Bomberman->moverBombermanDerecha();
     //cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
    }
void CControlmapa :: moverbomberArriba() {
    Nuevo->mostrar();
    mapa->draw(Enemigo->sprite);
    mapa->draw(Bomberman->Bomba);
    Bomberman->moverBombermaArriba();
    //cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
}
void CControlmapa ::moverbomberIzquierda()
{
    Nuevo->mostrar();
    mapa->draw(Enemigo->sprite);
    mapa->draw(Bomberman->Bomba);
    //mapa->draw(Enemigo->sprite);
    Bomberman->moverBombermanIzquierda();

   // cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
}
void CControlmapa :: moverbomberAbajo()
{
    Nuevo->mostrar();
    mapa->draw(Enemigo->sprite);
    mapa->draw(Bomberman->Bomba);
         Bomberman->moverBombermanAbajo();
    //cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
}
void CControlmapa ::timer()
{

}
void CControlmapa :: tiempobomba1()
{   Nuevo->mostrar();
    mapa->draw(Bomberman->sprite);
    Bomberman->tiempo1();
    //mapa->draw(Bomberman->Bomba);
}
void CControlmapa :: crearbomba()
{
    Nuevo->mostrar();

    mapa->draw(Bomberman->sprite);
    Bomberman->ponerbomba();
}

void CControlmapa :: muestra_enemigos()
{
    Nuevo->mostrar();
    mapa->draw(Enemigo->sprite);
}

CControlmapa:: ~CControlmapa()
{
    delete Nuevo;
    delete Bomberman;
    delete Enemigo;
    delete mapalocal;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++)
        {
            delete mapalocal[i];
        }
    }


}