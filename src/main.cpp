#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "sprite.h"
#include "monster.h"
#include "vector2.h"


int main()
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_CreateWindowAndRenderer(1080,720,SDL_WINDOW_SHOWN,&window,&renderer); 
	SDL_SetWindowTitle(window,"jRPG demo");

	//Sprite test(renderer,"../res/test.bmp",301,287);
	Monster m1(10,10,renderer,"../res/test.bmp",301,287);
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

			SDL_Rect dst = m1.sprite.getRectPos(m1.pos.getx(),m1.pos.gety());
			//SDL_Rect src = test.getRect();
    		//SDL_RenderCopy(renderer,test.getTexture(),&src,&dst);
    		m1.sprite.displayText(renderer,dst);
			SDL_RenderPresent(renderer);
		}
	}

}

