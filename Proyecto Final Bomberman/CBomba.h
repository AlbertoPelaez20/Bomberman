//
// Created by Zero on 10/07/2020.
//

#ifndef PROYECTO_FINAL_BOMBERMAN_CBOMBA_H
#define PROYECTO_FINAL_BOMBERMAN_CBOMBA_H
#include"funciones.h"


class CBomba {
private:
    RenderWindow *mapa;
    Texture Bomba;
    int indicex;
    int ancho;
    int tiempoexplosion;
    int x;
    int y;
    int **mapabomba;

public:
    CBomba();
    CBomba(RenderWindow *_mapa, int x, int y,int **&matriz);
    ~CBomba();
    void dibujarbomba();
    void estado_normal();
    void estado_explosion();
    void estado_desaparicion();
    bool validaposicion();
    Sprite sprite;
};


#endif //PROYECTO_FINAL_BOMBERMAN_CBOMBA_H
