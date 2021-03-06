//
// Created by Zero on 27/06/2020.
//
#include "CEscenario.h"

CEscenario :: CEscenario() {

    matriz = new int *[filas];
    for (int i = 0; i < filas; i++) { matriz[i] = new int[columnas];
        void generarmapa();
        void imprimir();
        void PintarMapa();
        void Pintarpiso();
        void Pintarobstaculo();

    }
}

CEscenario :: ~CEscenario()
{
    delete matriz;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
        {
            delete matriz[i];
        }
    }

}


 CEscenario :: CEscenario(RenderWindow *_mapa) {
     mapa=_mapa;
     matriz = new int *[filas];
     for (int i = 0; i < filas; i++) { matriz[i] = new int[columnas]; }
 }

void  CEscenario :: setMapa(RenderWindow * mapa1)
{
    mapa=mapa1;

}

void CEscenario ::generarmapa() {
    srand(time(nullptr));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) matriz[i][j] = 1;  // bordes del mapa
            else {
                if (i % 2 == 0 && j%2 == 0) matriz[i][j] = 1;
                else if ((i == 1 && (j == 1 || j == 2)) || (j == 1 && i == 2) ||
                         (i == filas - 2 && (j == columnas - 3 || j == columnas - 2)) ||
                         (i == filas - 3 && j == columnas - 2))
                    matriz[i][j] = 0; // zona movible
                else matriz[i][j] = rand()%2 + 2; // zonas  con obstaculos destruibles o libres , 2 libre y 3 con obtaculo destruible
            }
        }

    }
}

void  CEscenario :: imprimir() {

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j]<<" ";
        }
        cout<<endl;

    }
}

void CEscenario :: PintarMapa()
{
    bloque.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/bmpSolido.png");
    Sprite sprite(bloque);
    sprite.setOrigin(0,0);
    sprite.scale(0.8,0.81);
   int x=0,y=0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if ( matriz[i][j] == 1 )
            {
                sprite.setPosition(x,y);
                mapa->draw(sprite);

        }
            x += 50;


    }
        x=0;
        y+=43;

}
}

void  CEscenario :: Pintarpiso()
{
    piso.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/bmpSuelo.png");
    Sprite sprite(piso);
    sprite.setOrigin(0,0);
    sprite.scale(0.8,0.8);
    int x=0,y=0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if ( matriz[i][j] == 0 || matriz[i][j]== 2 )
            {
                sprite.setPosition(x,y);
                mapa->draw(sprite);

            }
            x += 50;


        }
        x=0;
        y+=43;

    }

}

void  CEscenario :: mostrar()
{

     PintarMapa();
     Pintarpiso();
     Pintarobstaculo();
}


void CEscenario :: Pintarobstaculo()
{
    obstaculo.loadFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/imagen/bmpDestruible.png");
    Sprite sprite(obstaculo);
    sprite.setOrigin(0,0);
    sprite.scale(0.8,0.81);
    int x=0,y=0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if ( matriz[i][j] == 3 )
            {
                sprite.setPosition(x,y);
                mapa->draw(sprite);

            }
            x += 50;


        }
        x=0;
        y+=43;

    }
}

void CEscenario :: actualizarpantalla(int a, int b)

{ cout<<" a "<<a<< "  b  "<<b<<endl;

   // a= (a/52) +2;
   // b= (b/37)+1;

    a= (a/54)+1;
if ( 594<=b) b= 400;
if (304<=b && b <= 474)    b= (b/38)+2;
else b= (b/38)+1;







    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            if (0 < a && 0 < b) {
                if (a<16 && b < 14) {
                    if ((matriz[b][a + 1] == 3)) {
                        matriz[b][a + 1] = 2;

                    }

                    if ((matriz[b][a - 1] == 3)) {
                        matriz[b][a - 1] = 2;

                    }

                    if ((matriz[b + 1][a] == 3)) {
                        matriz[b + 1][a] = 2;

                    }
                    if ((matriz[b - 1][a] == 3)) {
                        matriz[b - 1][a] = 2;

                    }

                }



            }

        }
    }

    //cout<<"posicion a "<<a<<"posicion b "<<b<<endl;
}