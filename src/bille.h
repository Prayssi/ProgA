#ifndef BILLE_H
#define BILLE_H

#include <SDL2/SDL.h>
#include <stdio.h>


#include "sprite.h"
#include "vector2.h"

class Bille
{
public:
	Bille(double xpos, double ypos,SDL_Renderer* renderer);
	~Bille();//Destructeur
	void Update();
	
	Sprite sprite;
	Vector2 pos;
	Vector2 vit;
private:
	
	
};

#endif