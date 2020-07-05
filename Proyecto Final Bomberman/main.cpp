#include <iostream>
#include "CEscenario.h"
#include "CControlmapa.h"
#include "CBomberman.h"

int main() {

    RenderWindow window(VideoMode(850,645),"BOMBERMAN 4");
    Music music;
    music.openFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/Audio/ModoSolitario.wav");
    music.play();
    CControlmapa mapa(&window);
    CEscenario map;
    window.display();
    //window.setFramerateLimit(60);

    while (window.isOpen()) {

        // Process events
        Event event;

        while (window.pollEvent(event)) {
           window.clear();

            if (Keyboard::isKeyPressed(Keyboard::Right))
            {

                 mapa.moverbomberDerecha();


                window.display();

               // cout<<"posicion x ="<<mapa.getPosx()<<endl;


            }

            if (sf::Keyboard::isKeyPressed(Keyboard::Left))
            {

                mapa.moverbomberIzquierda();
                //map.mostrar();
                 window.display();

                //cout<<"posicion x = "<<mapa.getPosx()<<endl;


            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

                mapa.moverbomberArriba();
                //map.mostrar();
                window.display();
                //cout<<"posicion y : "<<mapa.getPosy()<<endl;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {

                mapa.moverbomberAbajo();
                //map.mostrar();
                window.display();

               // cout<<"posicion y : "<<mapa.getPosy()<<endl;
            }

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }


    }
    //a.moverBomberman();*/
    /*
    CEscenario map(&window);
    map.generarmapa();
    map.imprimir();
    map.PintarMapa();
    map.Pintarpiso();
    map.Pintarobstaculo();*/
    //window.display();
    sleep(milliseconds(5000));


}