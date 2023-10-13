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
	void SetVitesse(double vitX, double vitY);//On modifie la vitesse nous même
	void SetVitesse(double mult);//On modifie la vitesse en multipliant les deux composants par un facteur
	
	Sprite sprite;
	Vector2 pos;
	Vector2 vit;
private:
	
	
};

#endif