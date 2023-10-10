#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <chrono>
#include <thread>

#include "sprite.h"
#include "bille.h"
#include "vector2.h"


int main()
{
	const int FPS = 30;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer(720,1080,SDL_WINDOW_SHOWN,&window,&renderer); 
	SDL_SetWindowTitle(window,"jRPG demo");

	

	Bille bille(360,200,renderer);
	SDL_Event event;
	
	bool gameRunning = true;

	const int frameDelay = 1000/FPS;
	Uint32 frameStart;
	int frameTime;

	while(gameRunning)
	{
		frameStart = SDL_GetTicks();

		while(SDL_PollEvent(&event))
		{
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			if(event.type == SDL_QUIT)
			{
				gameRunning=false;
			}




			SDL_Rect dst = bille.sprite.getRectPos(bille.pos.getx(),bille.pos.gety());
			SDL_RenderClear(renderer);
			bille.Update();
    		bille.sprite.displayText(renderer,dst);
    		SDL_RenderPresent(renderer);

    		//Régule le nombre de FPS
    		frameTime = SDL_GetTicks() - frameStart;
    		if(frameDelay > frameTime) SDL_Delay(frameDelay-frameTime);

		}
	}

}

