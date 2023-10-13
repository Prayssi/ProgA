#include <SDL2/SDL.h>
#include <stdio.h>

#include "bille.h"
#include "sprite.h"
#include "vector2.h"

Bille::Bille(double xpos, double ypos,SDL_Renderer* renderer)
{
	pos.Set(xpos,ypos);
	this->SetVitesse(3,3);
	sprite.setSprite(renderer,"../res/bille.bmp",17,17);
}

Bille::~Bille()
{

}

void Bille::Update()
{
	pos.Set(pos.plus(pos,vit));
	
}

void Bille::SetVitesse(double vitX,double vitY)
{
	vit.Set(vitX,vitY);
}

void Bille::SetVitesse(double mult)
{
	vit.time(mult);
}
