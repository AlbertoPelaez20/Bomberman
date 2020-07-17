#include <iostream>
#include "CEscenario.h"
#include "CControlmapa.h"
#include "CBomberman.h"
#include "CBomba.h"
#include "CEnemigos.h"


int main() {

    Clock tiempo;
    Clock proceso;
    Clock enemigo;
    int numerobomba = 0;
    int d=0;
    Time t1;
    Time t2;
    Time t3;
    Time t4;
    t1 = seconds(0.01f);
    t2 = seconds(0.01f);
    t3 = seconds(0.01f);
    RenderWindow window(VideoMode(850, 645), "BOMBERMAN 4");
    

    Music music;
    music.openFromFile("C:/Users/Zero/CLionProjects/Proyecto Final Bomberman/Audio/ModoSolitario.wav");
    music.play();



    CControlmapa mapa(&window);
    window.setFramerateLimit(60);

   // mapa.Nuevo->imprimir();
    CEscenario map;
    window.display();
    //t2=tiempo.restart();
    //window.setFramerateLimit(60);
    bool bombaactiva = false;
    bool explosionactiva = false;
    int t = 0;
    int t5=0;
    int a = 0;
    int posicionx;
    int posiciony;
    int bomb = 0;
    int direccion=0;
    while (window.isOpen()) {
        t1 = tiempo.getElapsedTime();
        t2 = proceso.getElapsedTime();
        t3 = proceso.getElapsedTime();
        t4 =enemigo.getElapsedTime();
        //cout << t2.asSeconds() << std::endl;
        //cout<<"posicion x : "<<mapa.Bomberman->getPosx()<<" posicion y : "<<mapa.Bomberman->getPosy()<<endl;


        if (numerobomba ==0)

        {
            t5 = t4.asSeconds();
            mapa.Nuevo->mostrar();
            if (mapa.Enemigo->sprite.getPosition().y == 550) d=1;
            if (d==1)mapa.Enemigo->sprite.move(0,-t5);
            if (  mapa.Enemigo->sprite.getPosition().y<=500 ) d=0;
               cout<<mapa.Enemigo->sprite.getPosition().y<<endl;
            window.draw(mapa.Bomberman->sprite);
            window.draw(mapa.Enemigo->sprite);
            window.display();

       /*   mapa.Enemigo->validarmovimientohorizontal();
          if(mapa.Enemigo->validar) mapa.Enemigo->sprite.move(++t5,0);
          if (  mapa.Enemigo->sprite.getPosition().y < 600)  mapa.Enemigo->sprite.move(0,--t5);
          if ( mapa.Enemigo->validarmovimientovertical())mapa.Enemigo->sprite.move(0,++t5);*/

        }


        if (numerobomba==1)
        {
            t5 = t4.asSeconds();
            if (t5 < 10) {
                t5 = t * 2;
            } else {
                t5 = 0;
                enemigo.restart();
            }
            mapa.Nuevo->mostrar();

            mapa.Enemigo->sprite.setTextureRect(IntRect(t5, 0, 20, 25));
            window.draw(mapa.Enemigo->sprite);



            window.draw(mapa.Enemigo->sprite);
            window.draw(mapa.Bomberman->sprite);
            //window.display();

        }





        if (bombaactiva) {
            numerobomba = 1;
            t = t1.asSeconds();
            if (t < 2) {
                t = t * 23;
            } else {
                t = 0;
               tiempo.restart();
            }

            mapa.Nuevo->mostrar();
            window.draw(mapa.Bomberman->sprite);
            mapa.Bomberman->Bomba.setTextureRect(IntRect(t, 0, 20, 25));
            window.draw(mapa.Enemigo->sprite);

            window.draw(mapa.Bomberman->Bomba);
            window.display();


        }

        if (explosionactiva) {


            t = t1.asSeconds();
            t = t * 40;

            mapa.Bomberman->bomba1->explosion.setTextureRect(IntRect(t, 0, 20, 20));
            window.draw(mapa.Bomberman->bomba1->explosion);
            mapa.Nuevo->mostrar();
            window.draw(mapa.Enemigo->sprite);
            window.draw(mapa.Bomberman->bomba1->explosion);
            window.draw(mapa.Bomberman->sprite);
            window.display();


            if (60 <= t) {
                t1 = tiempo.restart();
                explosionactiva = false;
                mapa.Nuevo->mostrar();
                mapa.Bomberman->bomba1->explosion.setTextureRect(IntRect(0, 0, 0, 0));

                window.draw(mapa.Bomberman->bomba1->explosion);
                mapa.Nuevo->actualizarpantalla(posicionx,posiciony);
                //mapa.Nuevo->imprimir();

                mapa.Nuevo->mostrar();
                window.draw(mapa.Enemigo->sprite);
                window.draw(mapa.Bomberman->sprite);
                window.display();
                numerobomba = 0;


            }
        }

        if (6 <= t3.asSeconds() && bombaactiva) {
            bombaactiva = false;
            mapa.Nuevo->mostrar();
            window.draw(mapa.Bomberman->sprite);
            mapa.Bomberman->Bomba.setTextureRect(IntRect(0, 50, 20, 25));
            window.draw(mapa.Bomberman->Bomba);


            explosionactiva = true;
            t1 = tiempo.restart();
            /*
    mapa.Bomberman->bomba1->explosion.setTextureRect(IntRect(0, 0, 20, 25));
    window.draw(mapa.Bomberman->bomba1->explosion);
    mapa.Bomberman->bomba1->explosion;*/

            window.display();
            //delete mapa.Bomberman->bomba1;


        }


        // Process events
        Event event;
        while (window.pollEvent(event)) {
            window.clear();

            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                mapa.moverbomberDerecha();

                window.display();
                //cout<<"posicion x ="<<mapa.getPosx()<<endl;
            }
            if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
                mapa.moverbomberIzquierda();

                window.display();

            }


            if (sf::Keyboard::isKeyPressed(Keyboard::A))

                if (numerobomba == 0) {


                   // cout<<"posicion x : "<<mapa.Bomberman->getPosx()<<" posicion y : "<<mapa.Bomberman->getPosy()<<endl;
                    posicionx = mapa.Bomberman->getPosx();
                    posiciony = mapa.Bomberman->getPosy() ;
                    mapa.crearbomba();
                    window.draw(mapa.Bomberman->bomba1->rectanguloexplosion);
                    window.draw(mapa.Enemigo->sprite);
                    bombaactiva = true;
                    tiempo.restart();
                    a = 1;
                    t3 = proceso.restart();

                     window.display();
                    //cout<<"posicion x = "<<mapa.getPosx()<<endl;}
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    mapa.moverbomberArriba();
                    //map.mostrar();
                    window.display();

                    //cout<<"posicion y : "<<mapa.getPosy()<<endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    mapa.moverbomberAbajo();
                    //map.mostrar();
                    window.display();

                    // cout<<"posicion y : "<<mapa.getPosy()<<endl;
                }



                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();

                }

            }
        }

        // sleep(milliseconds(5000));


    }
