#include <iostream>
#include "CEscenario.h"
#include "CControlmapa.h"
#include "CBomberman.h"

int main() {

    RenderWindow window(VideoMode(850,670),"BOMBERMAN 4");
    Music music;
    music.openFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/Audio/ModoSolitario.wav");
    music.play();
    CControlmapa mapa(&window);
    mapa.Crearmapa();
    //CBomberman a(&window,0,0);
    //a.dibujarBomberman();
    //mapa.moverbomber();
    window.display();
    window.setFramerateLimit(60);
/*
    while (window.isOpen()) {

        // Process events
        Event event;

        while (window.pollEvent(event)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                  mapa.moverbomber();
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