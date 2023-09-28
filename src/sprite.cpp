#include <SDL2/SDL.h>
#include <stdio.h>

#include "sprite.h"
/*class Sprite{
public:
	Sprite(SDL_Renderer* renderer, const char *pathfile, int w, int l);
    SDL_Rect getRect();
    SDL_Texture* getTexture();

private:
	SDL_Texture* texture = NULL;
	int width;
	int length; 
};*/

Sprite::Sprite(SDL_Renderer* renderer, const char *pathfile, int w, int l): width(w), length(l)//constructeur
{
	SDL_Surface *surface = SDL_LoadBMP(pathfile);
    if(!surface)
    {
        printf("SDL_LoadBMP failed");
    }
	
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

SDL_Rect Sprite::getRect()//Renvoi la taille du Sprite
{
    return {0,0,width,length};
}

SDL_Texture* Sprite::getTexture()//Renvoi la texture du Sprite
{
    return texture;
}

void Sprite::displayText(SDL_Renderer* renderer, SDL_Rect dst)
{
    SDL_Rect src = this->getRect();
    SDL_RenderCopy(renderer,this->getTexture(),&src,&dst);
}
