#ifndef SPRITE_H
#define SPRITE_H


#include <SDL2/SDL.h>
#include <stdio.h>

/*
*   Ce component gère l'affichage d'un sprite
*/

class Sprite{
public:
	Sprite(SDL_Renderer* renderer, const char *pathfile, int w, int l);
	Sprite();
	void setSprite(SDL_Renderer* renderer, const char *pathfile, int w, int l);
    SDL_Rect getRect();
    SDL_Rect getRectPos(int x, int y);
    SDL_Texture* getTexture();
    void displayText(SDL_Renderer* renderer, SDL_Rect dst);

private:
	SDL_Texture* texture = NULL;
	int width;
	int length; 
};

#endif