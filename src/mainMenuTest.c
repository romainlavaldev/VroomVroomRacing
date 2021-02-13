
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
    mainMenuMusic = Mix_LoadMUS("sound/music/mainMenu.mp3");

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
        SDL_RenderSetLogicalSize(renderer, 1920, 1080);



        //CREATION DES IMAGES ET BOUTTONS

        //Fond
        SDL_Surface* bgTmp = SDL_LoadBMP("img/fond.bmp");
        SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgTmp);
        SDL_FreeSurface(bgTmp);
        SDL_Rect bgPosition;
        bgPosition.x = 0;
        bgPosition.y = 0;
        bgPosition.w = 1920;
        bgPosition.h = 1080;
        SDL_RenderCopy(renderer, bgTexture, NULL, &bgPosition);

        //Boutton Solo
        SDL_Surface* soloButtonTmp = SDL_LoadBMP("img/solo.bmp");
        SDL_Texture* soloButtonTexture = SDL_CreateTextureFromSurface(renderer, soloButtonTmp);
        SDL_FreeSurface(soloButtonTmp);
        SDL_Rect soloButtonPosition;
        soloButtonPosition.x = 586;
        soloButtonPosition.y = 319;
        soloButtonPosition.w = 1334;
        soloButtonPosition.h = 150;
        SDL_RenderCopy(renderer, soloButtonTexture, NULL, &soloButtonPosition);

        //Boutton Multijoueur
        SDL_Surface* multiButtonTmp = SDL_LoadBMP("img/multi.bmp");
        SDL_Texture* multiButtonTexture = SDL_CreateTextureFromSurface(renderer, multiButtonTmp);
        SDL_FreeSurface(multiButtonTmp);
        SDL_Rect multiButtonPosition;
        multiButtonPosition.x = 586;
        multiButtonPosition.y = 504;
        multiButtonPosition.w = 1334;
        multiButtonPosition.h = 150;
        SDL_RenderCopy(renderer, multiButtonTexture, NULL, &multiButtonPosition);

        //Boutton Quitter
        SDL_Surface* quitButtonTmp = SDL_LoadBMP("img/quitter.bmp");
        SDL_Texture* quitButtonTexture = SDL_CreateTextureFromSurface(renderer, quitButtonTmp);
        SDL_FreeSurface(quitButtonTmp);
        SDL_Rect quitButtonPosition;
        quitButtonPosition.x = 1030;
        quitButtonPosition.y = 901;
        quitButtonPosition.w = 890;
        quitButtonPosition.h = 100;


        //Boutton QuitterHover
        SDL_Surface* quitHoverButtonTmp = SDL_LoadBMP("img/quitterHover.bmp");
        SDL_Texture* quitHoverButtonTexture = SDL_CreateTextureFromSurface(renderer, quitHoverButtonTmp);
        SDL_FreeSurface(quitHoverButtonTmp);
        SDL_Rect quitHoverButtonPosition;
        quitHoverButtonPosition.x = 1030;
        quitHoverButtonPosition.y = 901;
        quitHoverButtonPosition.w = 890;
        quitHoverButtonPosition.h = 100;

                                                                  
/*******************************************************************************
 *  MENU 
 ******************************************************************************/
        if( pWindow )
        {

            SDL_Event event;

            Mix_PlayMusic(mainMenuMusic, -1);

            int run=1;
            while (run){

                int cursorX = event.button.x;
                int cursosY = event.button.y;

                if( (cursorX > quitButtonPosition.x) && (cursorX < quitButtonPosition.x + quitButtonPosition.w) && (cursosY > quitButtonPosition.y) && (cursosY < quitButtonPosition.y + quitButtonPosition.h) ){
                    SDL_RenderCopy(renderer, quitHoverButtonTexture, NULL, &quitHoverButtonPosition);
                }else{
                    SDL_RenderCopy(renderer, quitButtonTexture, NULL, &quitButtonPosition);
                }

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

                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_LEFT){
                            printf("\nCursorX : %d   CursorY : %d\n", cursorX, cursosY);

                            //Zone du boutton quitter
                            if( (cursorX > quitButtonPosition.x) && (cursorX < quitButtonPosition.x + quitButtonPosition.w) && (cursosY > quitButtonPosition.y) && (cursosY < quitButtonPosition.y + quitButtonPosition.h) ){
                                printf("c'est tchao");
                                SDL_DestroyWindow(pWindow); // fermeture de fenêtre
                                Mix_FreeMusic(mainMenuMusic);
                                Mix_CloseAudio();
                                SDL_Quit(); // fermeture SDL
                                run=0;
                            }
                        }
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