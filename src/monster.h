#ifndef MONSTER_H
#define MONSTER_H

#include <SDL2/SDL.h>
#include <stdio.h>


#include "sprite.h"
#include "vector2.h"

class Monster
{
public:
	Monster(double xpos, double ypos,SDL_Renderer* renderer, const char *pathfile, int w, int l);

	Sprite sprite;
	Vector2 pos;
private:
	
	double vie = 100; //PA
	
};

#endif
