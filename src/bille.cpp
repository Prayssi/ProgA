#include <SDL2/SDL.h>
#include <stdio.h>

#include "bille.h"
#include "sprite.h"
#include "vector2.h"

Bille::Bille(double xpos, double ypos,SDL_Renderer* renderer)
{
	pos.Set(xpos,ypos);
	vit.Set(0,0);
	sprite.setSprite(renderer,"../res/bille.bmp",17,17);
}

Bille::~Bille()
{

}

void Bille::Update()
{
	vit.Set(1,1);
	pos.Set(pos.plus(pos,vit));
}
