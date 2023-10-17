#include <SDL2/SDL.h>
#include <stdio.h>
#include <cmath>

#include "bille.h"
#include "sprite.h"
#include "vector2.h"

#define hauteur_bille 17
#define largeur_bille 17

#define HEIGHT_SCREEN 500
#define LENGTH_SCREEN 720





Bille::Bille(double xpos, double ypos,SDL_Renderer* renderer)
{
	pos.Set(xpos,ypos);
	this->SetVitesse(4,3);
	sprite.setSprite(renderer,"../res/bille.bmp",hauteur_bille,largeur_bille,0);
}

Bille::~Bille()
{

}

void Bille::Update()
{

	pos.Set(pos.plus(pos,vit));
	CollisionBord();

}

void Bille::CollisionBord()
{
	int circleradius = hauteur_bille/2;
	//test de collision avec le bord droite
	if(circleradius+pos.getx()+sprite.GetRectCenter().x >= LENGTH_SCREEN)
	{
		this->SetVitesse(vit.getx() * -1,vit.gety());
	}
	//test de collision avec le bord gauche
	if(pos.getx()<=0)
	{
		this->SetVitesse(vit.getx() * -1,vit.gety());
	}
	//test de collision avec le bord haut
	if(pos.gety() <= 0)
	{
		this->SetVitesse(vit.getx(),vit.gety()* -1);
	}
	//test de collision avec le bord bas
	if(pos.gety()+hauteur_bille >= HEIGHT_SCREEN)
	{
		ReinitialisationBille();
	}

}

//ReinitialisiationBille suite à une défaire, une perte de vie
void Bille::ReinitialisationBille()
{
	pos.Set(LENGTH_SCREEN/2,HEIGHT_SCREEN/2);
	SetVitesse(0,3);
}

void Bille::SetVitesse(double vitX,double vitY)
{
	vit.Set(vitX,vitY);
}

void Bille::SetVitesse(double mult)
{
	vit.time(mult);
}
