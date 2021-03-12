#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

int main(int argc, char** argv)
{
    SDL_Window *window = NULL;
    SDL_Renderer * renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        SDL_Log("ERROR : Could not init SDL > %s \n",SDL_GetError());
        return -1;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800 , 600 , SDL_WINDOW_SHOWN);
    if(window == NULL){
        SDL_Log("ERROR : Could not init window > %s \n",SDL_GetError());
        return -1;
    } 
    renderer = SDL_CreateRenderer(window, -1 , 0);
    if(renderer == NULL){
        SDL_Log("ERROR : Could not init renderer > %s \n",SDL_GetError());
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0,16,255, SDL_ALPHA_OPAQUE);
    SDL_Rect rectangle;
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 100; 

    int terminer = 0;
    SDL_Event evenements;
    while (!terminer){
        SDL_WaitEvent(&evenements);

	    if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	        terminer = 1;
            

    SDL_RenderFillRect(renderer, &rectangle);

    SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}