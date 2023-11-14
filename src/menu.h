#ifndef MENU_H
#define MENU_H

#define HEIGHT_SCREEN 500
#define LENGTH_SCREEN 720

#include <SDL2/SDL.h>
#include "sprite.h"
#include "bille.h"
#include "vector2.h"
#include "platform.h"
#include "gameManager.h"


struct Menu{

	Sprite spriteBoutonJouer;
	SDL_Renderer* renderer;

	Menu(SDL_Renderer* renderer) : renderer(renderer)
	{

		genererBoutonJouer();
	}

	void Update()
	{
		SDL_Rect dstBoutonJouer = spriteBoutonJouer.getRectPos(LENGTH_SCREEN/2 - 394/2, 200);
		spriteBoutonJouer.displayText(renderer,dstBoutonJouer);
	}

	void genererBoutonJouer()
	{
		spriteBoutonJouer.setSprite(renderer,"../res/jouer1.png",394,90,1);
	}

	void boutonJouerUpdate(int etat)
	{
		if(etat == 0)
		{
			spriteBoutonJouer.setSprite(renderer,"../res/jouer1.png",394,90,1);
		}else
		{
			spriteBoutonJouer.setSprite(renderer,"../res/jouer2.png",394,90,1);
		}
	}



};

#endif