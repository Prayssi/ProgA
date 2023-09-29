#include <SDL2/SDL.h>
#include <stdio.h>

#include "sprite.h"


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

Sprite::Sprite()
{
    texture = NULL;
    width = 0; length =0;
}

void Sprite::setSprite(SDL_Renderer* renderer, const char *pathfile, int w, int l)
{
    width = w; length = l;
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
SDL_Rect Sprite::getRectPos(int x,int y)//Renvoi un SDL_Rect de la destination du sprite
{
    return{x,y,width,length};
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
