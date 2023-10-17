#include <SDL2/SDL.h>
#include <stdio.h>

#include "platform.h"
#include "sprite.h"
#include "vector2.h"

#define hauteur_platform 151
#define largeur_platform 16

Platform::Platform(double xpos, double ypos,SDL_Renderer* renderer)
{
	pos.Set(xpos,ypos);
	this->SetVitesse(0,0);
	sprite.setSprite(renderer,"../res/platform.png",hauteur_platform,largeur_platform,1);
}

Platform::~Platform()
{

}

void Platform::Update()
{
	pos.Set(pos.plus(pos,vit));
	this->handle_keyboard();

}

void Platform::handle_keyboard() {
        const Uint8 *kbstate = SDL_GetKeyboardState(NULL);
        if (!kbstate[SDL_SCANCODE_RIGHT] && !kbstate[SDL_SCANCODE_LEFT])
            this->SetVitesse(0,0);

            if (kbstate[SDL_SCANCODE_LEFT]) 
            {
            	this->SetVitesse(-3,0);
            }
            if(kbstate[SDL_SCANCODE_RIGHT])
            {
                this->SetVitesse(3,0);
            }
    }

void Platform::SetVitesse(double vitX,double vitY)
{
	vit.Set(vitX,vitY);
}

void Platform::SetVitesse(double mult)
{
	vit.time(mult);
}
