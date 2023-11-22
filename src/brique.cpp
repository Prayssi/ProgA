#include <SDL2/SDL.h>
#include <stdio.h>
#include <cmath>

#include "brique.h"
#include "bille.h"
#include "sprite.h"
#include "vector2.h"
#include "platform.h"

#define BRIQUE_LARGEUR 50
#define BRIQUE_HAUTEUR 20

/**
 * La première erreur était dans ton constructeur Brique(), plus précisemment dans le chemin d'accès à l'image et aussi dans le format de cette image, tu avais écrit ../ProgA/res/brique.jpg
 * La deuxième c'est ligne 26, en soi c'était pas une erreur mais j'avais déjà fait une fonction getRectPos dans le sprite qui fonctionne très bien donc j'ai juste mit ça
 * Pour la fonction collision j'ai changé quelques trucs aussi
 */
Brique::Brique(int x, int y, int type, SDL_Renderer* renderer) : x(x), y(y), type(type), eliminee(false), sprite(renderer, "../res/brique.png", BRIQUE_LARGEUR, BRIQUE_HAUTEUR, 1) {
    resistance = (type == 1) ? 1 : 2;
}

void Brique::Afficher(SDL_Renderer* renderer) {
     if (!eliminee) {
        // Dessinez la brique sur le rendu avec les coordonnées x, y, largeur et hauteur
        SDL_Rect dstRect = this->sprite.getRectPos(this->x,this->y);
        sprite.displayText(renderer, dstRect);
     }
}

bool Brique::EstEliminee() {
    return eliminee;
}

void Brique::Eliminer() {
    eliminee = true;
}

bool Brique::CollisionBille(Bille& bille) { 
    
    if (!eliminee) {
        double billeX = bille.getX(); // Obtenir la position X de la bille depuis la classe Bille
        double billeY = bille.getY(); // Obtenir la position Y de la bille depuis la classe Bille
        double billeLargeur = largeur_bille; // Obtenir la largeur de la bille depuis la classe Bille
        double billeHauteur = hauteur_bille; // Obtenir la hauteur de la bille depuis la classe Bille

        if (billeX + billeLargeur >= x && billeX <= x + BRIQUE_LARGEUR && billeY + billeHauteur >= y && billeY <= y + BRIQUE_HAUTEUR) {
            return true;
        }
    }
    return false;
}

void Brique::ReduireResistance() {
    if (type == 2) {
        resistance--; // Réduire la résistance de la brique de type 2
        if (resistance == 0) {
            eliminee = true; // Marquer la brique comme éliminée si la résistance atteint 0
        }
    }
}


int Brique::GetType() {
    return type;
}

int Brique::getX() {
    return x;
}

int Brique::getY() {
    return y;
}

int Brique::getLargeur() {
    return BRIQUE_LARGEUR;
}

int Brique::getHauteur() {
    return BRIQUE_HAUTEUR;
}
