#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "sprite.h"
#include "bille.h"
#include "vector2.h"

#define HEIGHT_SCREEN 1080
#define LENGTH_SCREEN 720



int main()
{
	const int FPS = 30;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer(LENGTH_SCREEN,HEIGHT_SCREEN,SDL_WINDOW_SHOWN,&window,&renderer); 
	SDL_SetWindowTitle(window,"jRPG demo");

	

	Bille bille(360,200,renderer);
	SDL_Event event;
	
	bool gameRunning = true;

	while(gameRunning)
	{
		
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				gameRunning=false;
			}


			if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    // Si le bouton gauche de la souris est enfoncé, effectuez une action
                    bille.SetVitesse(-1);
                    printf("%f %f",bille.vit.getx(),bille.vit.gety());
                    fflush(stdout);
                }
            }

		}
			
			bille.Update();
			SDL_Rect dst = bille.sprite.getRectPos(bille.pos.getx(),bille.pos.gety());

			//On efface tout...
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			SDL_RenderClear(renderer);
			

			//...avant de tout réafficher
    		bille.sprite.displayText(renderer,dst);

    		//Et on actualise
    		SDL_RenderPresent(renderer);

    		//On impose une latence pour éviter d'être à 200000 FPS wtf
			SDL_Delay(16);//16ms environ 60 FPS    		

		
	}

	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

