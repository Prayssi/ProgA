#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "sprite.h"
#include "bille.h"
#include "vector2.h"
#include "platform.h"
#include "gameManager.h"
#include "menu.h"

#define HEIGHT_SCREEN 500
#define LENGTH_SCREEN 720



int main()
{
	const int FPS = 30;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer(LENGTH_SCREEN,HEIGHT_SCREEN,SDL_WINDOW_SHOWN,&window,&renderer); 
	SDL_SetWindowTitle(window,"jRPG demo");

	SDL_Event event;

	// GameManager jeu(renderer);
	Menu menuScreen(renderer);
	
	bool gameRunning = true;

	while(gameRunning)
	{
		int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

		
        while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				gameRunning=false;
			}


			if (event.type == SDL_MOUSEMOTION) {
                    if (  mouseY > 200
                  && mouseY <= 200+90
                  && mouseX > 163
                  && mouseX <= 163+394 
              		)
                    {
              menuScreen.boutonJouerUpdate(1);
          }else{ 
          		menuScreen.boutonJouerUpdate(0);
                }
            }
            }

			

			//On efface tout...
			SDL_SetRenderDrawColor(renderer,255,255,255,255);//Définit la couleur de fond
			SDL_RenderClear(renderer);
			// jeu.Update();
			menuScreen.Update();

    		//Et on actualise
    		SDL_RenderPresent(renderer);

    		//On impose une latence pour éviter d'être à 200000 FPS wtf
			SDL_Delay(17);//16ms environ 60 FPS    		

		
	}

	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

