//
// Created by Zero on 28/06/2020.
//

#include "CControlmapa.h"

 CControlmapa :: CControlmapa (RenderWindow *_mapa)  {
    mapa=_mapa;
   Nuevo = new CEscenario(mapa);
   Bomberman =new CBomberman(mapa,0,0);
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
 //Bomberman->dibujarBomberman();

}


bool CControlmapa ::intersects (const RectangleShape & rect1,const RectangleShape & rect2)
{
   //FloatRect r1=rect1.getGlobalBounds();
  //  FloatRect r2=rect2.getGlobalBounds();
   // return r1.intersects (r2);
}


void CControlmapa :: Mostrarmapa()
{


}
void  CControlmapa :: validarmovimientovertical()
{

    int X=0 , Y=0 ;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;

            if ( mapalocal[i][j] == 1 || mapalocal[i][j]== 3  ) {
                //C.setPosition(X-50, Y);
                //mapa->draw(C);
                IntRect r1(X-50, Y, 50, 40);
                //IntRect r2 (Bomberman->rectangle.getPosition().x, Bomberman->rectangle.getPosition().y,40,25);
                IntRect r3 (Bomberman->rectangleA.getPosition().x,Bomberman->rectangleA.getPosition().y,40,25);
                IntRect result;
                IntRect result2;

              //  bool a = r1.intersects(r2,result);
                bool b= r1.intersects(r3,result2);
                if( b== true && val==true ){
                    //cout<<"Choca  x de r2 "<<r2.left<<" y "<< "posicion  es" << r2.top<<endl;
                   // cout<<"Choca"<<endl;
                    val=false;


                }




            }
        } X=0;
        Y += 43;
    }


}

void CControlmapa ::validarmovimientohorizontal()  {


    int X=0 , Y=0 ;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 17; j++) {
            X += 50;


            if ( mapalocal[i][j] == 1 || mapalocal[i][j]== 3 ) {
                //C.setPosition(X-50, Y);
               // mapa->draw(C);
                IntRect r1(X-50, Y, 50, 40);
                IntRect r2 (Bomberman->rectangle.getPosition().x, Bomberman->rectangle.getPosition().y,40,25);
                //IntRect r3 (Bomberman->rectangleA.getPosition().x,Bomberman->rectangleA.getPosition().y,40,25);
                IntRect result;
                IntRect result2;

               bool a = r1.intersects(r2,result);
              // bool b= r1.intersects(r3,result2);
                if( a== true ){
                    //cout<<"Choca  x de r2 "<<r2.left<<" y "<< "posicion  es" << r2.top<<endl;
                    //cout<<"Choca"<<endl;
                    val=false;


               }




            }
        } X=0;
        Y += 43;
    }
}


void CControlmapa ::moverbomberDerecha()
{
     if (val==false)
     {
         Bomberman->rectangle.setPosition(Bomberman->x+15,Bomberman->y+42);

         val=true;
     }
     Nuevo->mostrar();

     validarmovimientohorizontal();
   if ( val || (Bomberman->x == 52) ) Bomberman->moverBombermanDerecha();



      mapa->draw(Bomberman->sprite);
    //mapa->draw(Bomberman->rectangle);
   // mapa->draw(Bomberman->rectangleA);



}
void CControlmapa :: moverbomberArriba() {

    if (val==false)
    {


        Bomberman->rectangleA.setPosition(Bomberman->x+5,Bomberman->y+45);

        val=true;
    }

    Nuevo->mostrar();

    validarmovimientovertical();
    if ( val || 4 <= Bomberman->x )  Bomberman->moverBombermaArriba();
    mapa->draw(Bomberman->sprite);
   // mapa->draw(Bomberman->rectangleA);
}


void CControlmapa ::moverbomberIzquierda()
{


    if (val==false)
    {
        Bomberman->rectangle.setPosition(Bomberman->x-10,Bomberman->y+42);
        val=true;

    }

    Nuevo->mostrar();

    validarmovimientohorizontal();
    if ( val || Bomberman->x == 752)  Bomberman->moverBombermanIzquierda();
    mapa->draw(Bomberman->sprite);
   // mapa->draw(Bomberman->rectangle);
    //mapa->draw(Bomberman->rectangle);


}

void CControlmapa :: moverbomberAbajo()
{
    if (val==false)
    {


        Bomberman->rectangleA.setPosition(Bomberman->x+12,Bomberman->y+65);

        val=true;
    }

    Nuevo->mostrar();

    validarmovimientovertical();

    if ( val || 4 == Bomberman->x ) Bomberman->moverBombermanAbajo();
    mapa->draw(Bomberman->sprite);

   // mapa->draw(Bomberman->rectangleA);


}

void CControlmapa ::timer()
{


}

void   CControlmapa :: mando(Keyboard::Key key, bool isPressed)

{


}
