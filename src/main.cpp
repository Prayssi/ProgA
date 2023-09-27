#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "sprite.cpp"


int main()
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer(1080,720,SDL_WINDOW_SHOWN,&window,&renderer); 
	SDL_SetWindowTitle(window,"jRPG demo");

	Sprite test(renderer,"../res/test.bmp",48,32);

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

			SDL_Rect dst = {0,0,48,32};
			SDL_Rect src = test.getRect();
			SDL_RenderCopy(renderer,test.getTexture(),&src,&dst);
			SDL_RenderPresent(renderer);
		}
	}

}

