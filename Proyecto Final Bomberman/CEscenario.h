//
// Created by Zero on 27/06/2020.
//
#ifndef PROYECTO_FINAL_BOMBERMAN_CESCENARIO_H
#define PROYECTO_FINAL_BOMBERMAN_CESCENARIO_H
#include "funciones.h"
using namespace std;
class CEscenario {
private :
    RenderWindow *mapa;
    int filas = 15;
    int columnas = 17;
    Texture bloque;
    Texture piso;
    Texture obstaculo;

public :
    int xocupado;
    int yocupado;
    int **matriz;
    CEscenario();
    CEscenario(RenderWindow *_mapa);
    ~CEscenario();
    void setMapa(RenderWindow * mapa1);
    void mostrar();
    void generarmapa();
    void imprimir();
    void PintarMapa();
    void Pintarpiso();
    void Pintarobstaculo();
    void actualizarpantalla(int a, int b );

};
#endif //PROYECTO_FINAL_BOMBERMAN_CESCENARIO_H
