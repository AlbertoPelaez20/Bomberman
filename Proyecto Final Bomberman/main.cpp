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
    /*map.generarmapa();
    map.Pintarpiso();
    map.PintarMapa();
    map.Pintarobstaculo();
    /*map.mostrar();*/
    //window.display();
    //mapa.Crearmapa();
    //window.display();
    //window.display();
    //mapa.moverbomber();
    //CBomberman a(&window,0,0);
    //a.dibujarBomberman();
    //mapa.moverbomber();
    window.display();
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        // Process events
        Event event;

        while (window.pollEvent(event)) {
           window.clear();
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                //mapa;
                mapa.moverbomber();
                //map.mostrar();
                window.display();

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                //mapa;
                mapa.moverbomber();
                //map.mostrar();
                window.display();

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