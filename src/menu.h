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
	GameManager* gm;

	bool montrerMenu = true;

	Menu(SDL_Renderer* renderer, GameManager* gm) : renderer(renderer), gm(gm)
	{
		montrerMenu = true;
		genererBoutonJouer();
	}

	void Update()
	{	
		if(montrerMenu){SDL_Rect dstBoutonJouer = spriteBoutonJouer.getRectPos(LENGTH_SCREEN/2 - 394/2, 200);
				spriteBoutonJouer.displayText(renderer,dstBoutonJouer);}
	}

	//Generation du bouton jouer
	void genererBoutonJouer()
	{
		spriteBoutonJouer.setSprite(renderer,"../res/jouer1.png",394,90,1);
	}

	//Mise à jour du sprite du bouton
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

	//Gère la position de la souris
	void handle_mouseMoving()
	{
		if(montrerMenu){//Récuperer la position de la souris
				int mouseX, mouseY;
		        SDL_GetMouseState(&mouseX, &mouseY);
		        if (  mouseY > 200
		                  && mouseY <= 200+90
		                  && mouseX > 163
		                  && mouseX <= 163+394 
		              		)
		        {
		       	this->boutonJouerUpdate(1);
		        }else
		        { 
				this->boutonJouerUpdate(0);
		        }   
		    }
	}

	//Gère le clique de la souris
	void handle_mouseClicking()
	{
			if(montrerMenu){int mouseX, mouseY;
			        	SDL_GetMouseState(&mouseX, &mouseY);
			    	    if (  mouseY > 200
			                	  && mouseY <= 200+90
			            	      && mouseX > 163
			        	          && mouseX <= 163+394 
			    	          		)
			 	       {
			        	 	this->CacherMenu();
			        	 	gm->Start();
						}}
	}

	//Cache le menu
	void CacherMenu()
	{
		SDL_RenderClear(renderer);
		montrerMenu = false;

	}
	void MontrerMenu()
	{
		SDL_RenderClear(renderer);
		montrerMenu = true;

	}




};

#endif