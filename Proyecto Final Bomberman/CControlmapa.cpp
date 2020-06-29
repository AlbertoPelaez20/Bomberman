//
// Created by Zero on 28/06/2020.
//

#include "CControlmapa.h"

 CControlmapa :: CControlmapa (RenderWindow *_mapa)  {
    mapa=_mapa;
   Nuevo = new CEscenario(mapa);
   Bomberman =new CBomberman(mapa,0,0);

}

void CControlmapa ::  Crearmapa()
{
 Nuevo->generarmapa();
 Nuevo->PintarMapa();
 Nuevo->Pintarpiso();
 Nuevo->Pintarobstaculo();
 Bomberman->dibujarBomberman();

}


void CControlmapa ::moverbomber()
{
   Bomberman->moverBomberman();

}

void CControlmapa ::timer()
{


}