//
// Created by Zero on 28/06/2020.
//

#include "CControlmapa.h"

 CControlmapa :: CControlmapa (RenderWindow *_mapa)  {
    mapa=_mapa;
   Nuevo = new CEscenario(mapa);
   Bomberman =new CBomberman(mapa,0,0);
     Crearmapa();

     Bomberman->dibujarBomberman();

}

void CControlmapa ::  Crearmapa()
{
 Nuevo->generarmapa();
 Nuevo->PintarMapa();
 Nuevo->Pintarpiso();
 Nuevo->Pintarobstaculo();
 //Bomberman->dibujarBomberman();

}

void CControlmapa :: Mostrarmapa()
{

}



void CControlmapa ::moverbomber()
{


     //Bomberman->dibujarBomberman();

    Nuevo->mostrar();
    Bomberman->moverBomberman();

}

void CControlmapa ::timer()
{


}