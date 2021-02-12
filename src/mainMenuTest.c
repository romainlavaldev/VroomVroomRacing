
/*******************************************************************************
 *  INCLUDE 
 ******************************************************************************/


#include <stdio.h>
#include <SDL.h> 
#include <SDL_mixer.h>

 
int main(int argc, char** argv)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }


/*******************************************************************************
 *  AUDIO 
 ******************************************************************************/
    
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError()); // ok
   }

    Mix_Music* mainMenuMusic = NULL;
    mainMenuMusic = Mix_LoadMUS("mainMenu.mp3");

        printf("%s\n", Mix_GetError()); //coulnd't open ".mp3"

    if(mainMenuMusic != NULL){
        printf("C BON");
    }

        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        
        pWindow = SDL_CreateWindow("VROOM VROOM RACIIIIIIING !!!!",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1280,
                                                                  720,
                                                                  SDL_WINDOW_SHOWN);
        //SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

        //
        // CREATION DE L'AUDIO
        //
        
        SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, 0);
        SDL_RenderSetLogicalSize(renderer, 1280, 720);


        SDL_Surface* bgtmp = SDL_LoadBMP("img/fond.bmp");
        SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgtmp);
        SDL_Rect positionBg;
        positionBg.x = 0;
        positionBg.y = 0;
        positionBg.w = 1280;
        positionBg.h = 720;
        SDL_RenderCopy(renderer, bgTexture, NULL, &positionBg);
                                                                  
/*******************************************************************************
 *  MENU 
 ******************************************************************************/
        if( pWindow )
        {
            SDL_Event event;
            Mix_PlayMusic(mainMenuMusic, -1);
            int run=1;
            while (run){
                SDL_RenderPresent(renderer);
                while (SDL_PollEvent(&event)){
                    switch (event.type){
                    case SDL_QUIT:
                        SDL_DestroyWindow(pWindow); // fermeture de fenêtre
                        Mix_FreeMusic(mainMenuMusic);
                        Mix_CloseAudio();
                        SDL_Quit(); // fermeture SDL
                        run=0;
                        break;
                    default:
                        break;
                    }
                }
            }
            
            
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError()); // La fenêtre SDL n'a pas pu charger
        }
    

    Mix_CloseAudio();
    SDL_Quit(); // fermeture SDL
    return 0; // Fin correct du programmes
}