#include <SDL2/SDL.h>
#include <stdio.h>

#include "monster.h"
#include "sprite.h"
#include "vector2.h"

Monster::Monster(double xpos, double ypos,SDL_Renderer* renderer, const char *pathfile, int w, int l)
{
	pos.Set(xpos,ypos);
	sprite.setSprite(renderer,pathfile,w,l);
}