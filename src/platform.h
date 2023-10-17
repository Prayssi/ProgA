#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>


#include "sprite.h"
#include "vector2.h"

class Platform
{

public:
	Platform(double xpos, double ypos,SDL_Renderer* renderer);
	~Platform();//Destructeur
	void Update();

	void SetVitesse(double vitX, double vitY);//On modifie la vitesse et la direction nous même
	void SetVitesse(double mult);//On modifie la vitesse et la direction en multipliant les deux composants par un facteur
	void handle_keyboard();

	Sprite sprite;
	Vector2 pos;
	Vector2 vit;
private:


};

#endif