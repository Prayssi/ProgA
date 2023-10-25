#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "sprite.h"


Sprite::Sprite(SDL_Renderer* renderer, const char *pathfile, int w, int l, int format): width(w), length(l)//constructeur
{
    if(format == 0)
    {
    	SDL_Surface *surface = SDL_LoadBMP(pathfile);
        if(!surface)
        {
            printf("SDL_LoadBMP failed");
        }
	
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }else
    {
         SDL_Surface* surface = IMG_Load(pathfile);
        if (surface == NULL) 
        {
            // Gérer l'erreur de chargement de l'image
            fprintf(stderr, "Erreur de chargement de l'image : %s\n", IMG_GetError());
        }
        // Créer une texture à partir de la surface
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);  // Libérer la surface, car la texture la copie
    }
}

Sprite::Sprite()
{
    texture = NULL;
    width = 0; length =0;
}

Sprite::~Sprite()
{
    //Destruction
}

void Sprite::setSprite(SDL_Renderer* renderer, const char *pathfile, int w, int l, int format)
{
    width = w; length = l;
    if(format == 0)
    {
        
        SDL_Surface *surface = SDL_LoadBMP(pathfile);
        if(!surface)
        {
            printf("SDL_LoadBMP failed");
        }
    
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }else
    {
        SDL_Surface* surface = IMG_Load(pathfile);
        if (surface == NULL) 
        {
            fprintf(stderr, "Erreur de chargement de l'image : %s\n", IMG_GetError());
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
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

void Sprite::displayTexture(SDL_Renderer* renderer, SDL_Rect dst)
{
    SDL_Rect src = this->getRect();
    SDL_RenderCopy(renderer,this->getTexture(),&src,&dst);
}

SDL_Point Sprite::GetRectCenter() 
{
    SDL_Point center;
    SDL_Rect rect = this->getRect();
    center.x = rect.x + rect.w / 2;
    center.y = rect.y + rect.h / 2;
    return center;
}
