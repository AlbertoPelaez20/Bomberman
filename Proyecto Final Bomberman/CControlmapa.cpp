//
// Created by Zero on 28/06/2020.
//

#include "CControlmapa.h"

 CControlmapa :: CControlmapa (RenderWindow *_mapa)  {
    mapa=_mapa;
   Nuevo = new CEscenario(mapa);
   Bomberman =new CBomberman(mapa,0,0,Nuevo->matriz);
     Crearmapa();
     mapalocal=Nuevo->matriz;
     Bomberman->dibujarBomberman();
     C.setSize(Vector2f(50, 40));
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
     mapa->draw(Bomberman->Bomba);
     Bomberman->moverBombermanDerecha();
     //cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
    }
void CControlmapa :: moverbomberArriba() {
    Nuevo->mostrar();
    mapa->draw(Bomberman->Bomba);
    Bomberman->moverBombermaArriba();
    //cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
}
void CControlmapa ::moverbomberIzquierda()
{
    Nuevo->mostrar();
    mapa->draw(Bomberman->Bomba);
   Bomberman->moverBombermanIzquierda();
   // cout<<"posicion x : "<<Bomberman->getPosx()<<" posicion y : "<<Bomberman->getPosy()<<endl;
}
void CControlmapa :: moverbomberAbajo()
{
    Nuevo->mostrar();
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
