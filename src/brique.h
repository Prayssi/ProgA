#ifndef BRIQUE_H
#define BRIQUE_H

#include <SDL2/SDL.h>
#include <stdio.h>

#include "bille.h"
#include "sprite.h"
#include "vector2.h"
#include "platform.h"

#define BRIQUE_LARGEUR 50
#define BRIQUE_HAUTEUR 20



class Brique {
public:
    Brique(int x, int y, int type, SDL_Renderer* renderer);
    void Afficher(SDL_Renderer* renderer);
    bool EstEliminee() ;
    void Eliminer();
    bool CollisionBille(Bille& bille);
    void ReduireResistance();
    
    int GetType() ;
    int getX() ;
    int getY() ;
    int getLargeur() ;
    int getHauteur() ;

private:
    int x;
    int y;
    int type;
    bool eliminee;
    int resistance;
    Sprite sprite;
};

#endif
