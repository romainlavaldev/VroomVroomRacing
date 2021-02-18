
/*******************************************************************************
 *  INCLUDE 
 ******************************************************************************/


#include <stdio.h>
#include <SDL.h> 
#include <SDL_mixer.h>

 
int main(int argc, char** argv)
{
/*******************************************************************************
 *  AUDIO 
 ******************************************************************************/

    Mix_Chunk* mainMenuMusic = NULL;
    mainMenuMusic = Mix_LoadWAV("sound/music/mainMenu.mp3");

    Mix_Chunk* ButtonHoverSFX = NULL;
    ButtonHoverSFX = Mix_LoadWAV("sound/SFX/buttonHover.mp3");

    Mix_Chunk* ButtonClickedSFX = NULL;
    ButtonClickedSFX = Mix_LoadWAV("sound/SFX/ButtonBlocked.mp3");

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
                                                                  SDL_WINDOW_FULLSCREEN_DESKTOP);
        //SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

        //
        // CREATION DE L'AUDIO
        //
        
        SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, 0);
        SDL_RenderSetLogicalSize(renderer, 1920, 1080);


        /*******************************************************************************
         *  IMAGE ET BOUTTONS 
         ******************************************************************************/

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

        //Boutton SoloHover
        SDL_Surface* soloHoverButtonTmp = SDL_LoadBMP("img/solo_h.bmp");
        SDL_Texture* soloHoverButtonTexture = SDL_CreateTextureFromSurface(renderer, soloHoverButtonTmp);
        SDL_FreeSurface(soloHoverButtonTmp);
        SDL_Rect soloHoverButtonPosition;
        soloHoverButtonPosition.x = 586;
        soloHoverButtonPosition.y = 319;
        soloHoverButtonPosition.w = 1334;
        soloHoverButtonPosition.h = 150;

        //Boutton SoloClick
        SDL_Surface* soloClickButtonTmp = SDL_LoadBMP("img/solo_c.bmp");
        SDL_Texture* soloClickButtonTexture = SDL_CreateTextureFromSurface(renderer, soloClickButtonTmp);
        SDL_FreeSurface(soloClickButtonTmp);
        SDL_Rect soloClickButtonPosition;
        soloClickButtonPosition.x = 586;
        soloClickButtonPosition.y = 319;
        soloClickButtonPosition.w = 1334;
        soloClickButtonPosition.h = 150;

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

        //Boutton MultijoueurHover
        SDL_Surface* multiHoverButtonTmp = SDL_LoadBMP("img/multi_h.bmp");
        SDL_Texture* multiHoverButtonTexture = SDL_CreateTextureFromSurface(renderer, multiHoverButtonTmp);
        SDL_FreeSurface(multiHoverButtonTmp);
        SDL_Rect multiHoverButtonPosition;
        multiHoverButtonPosition.x = 586;
        multiHoverButtonPosition.y = 504;
        multiHoverButtonPosition.w = 1334;
        multiHoverButtonPosition.h = 150;
        SDL_RenderCopy(renderer, multiHoverButtonTexture, NULL, &multiHoverButtonPosition);

        //Boutton MultijoueurClick
        SDL_Surface* multiClickButtonTmp = SDL_LoadBMP("img/multi_c.bmp");
        SDL_Texture* multiClickButtonTexture = SDL_CreateTextureFromSurface(renderer, multiClickButtonTmp);
        SDL_FreeSurface(multiClickButtonTmp);
        SDL_Rect multiClickButtonPosition;
        multiClickButtonPosition.x = 586;
        multiClickButtonPosition.y = 504;
        multiClickButtonPosition.w = 1334;
        multiClickButtonPosition.h = 150;
        SDL_RenderCopy(renderer, multiClickButtonTexture, NULL, &multiClickButtonPosition);

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
        SDL_Surface* quitHoverButtonTmp = SDL_LoadBMP("img/quitter_h.bmp");
        SDL_Texture* quitHoverButtonTexture = SDL_CreateTextureFromSurface(renderer, quitHoverButtonTmp);
        SDL_FreeSurface(quitHoverButtonTmp);
        SDL_Rect quitHoverButtonPosition;
        quitHoverButtonPosition.x = 1030;
        quitHoverButtonPosition.y = 901;
        quitHoverButtonPosition.w = 890;
        quitHoverButtonPosition.h = 100;

        //Boutton QuitterClick
        SDL_Surface* quitClickButtonTmp = SDL_LoadBMP("img/quitter_c.bmp");
        SDL_Texture* quitClickButtonTexture = SDL_CreateTextureFromSurface(renderer, quitClickButtonTmp);
        SDL_FreeSurface(quitClickButtonTmp);
        SDL_Rect quitClickButtonPosition;
        quitClickButtonPosition.x = 1030;
        quitClickButtonPosition.y = 901;
        quitClickButtonPosition.w = 890;
        quitClickButtonPosition.h = 100;

                                                                  
/*******************************************************************************
 *  MENU 
 ******************************************************************************/
        if( pWindow )
        {
            
            SDL_Event event;

            Mix_PlayChannel(5, mainMenuMusic, -1);
            Mix_Volume(5, 30);

            int mouseDown = 0;

            int onButtonQuit = 0;
            int onButtonSolo = 0;
            int onButtonMulti = 0;

            int run=1;
            while (run){
       
                int cursorX = event.button.x;
                int cursosY = event.button.y;

                
                //UPDATE DU BOUTTON QUITTER
                if( (cursorX > quitButtonPosition.x) && (cursorX < quitButtonPosition.x + quitButtonPosition.w) && (cursosY > quitButtonPosition.y) && (cursosY < quitButtonPosition.y + quitButtonPosition.h) ){
                    if (!onButtonQuit){
                        //play sound
                        Mix_PlayChannel(-1, ButtonHoverSFX, 0);
                        onButtonQuit = 1;
                    }
                    SDL_RenderCopy(renderer, quitHoverButtonTexture, NULL, &quitHoverButtonPosition);
                }else{
                    SDL_RenderCopy(renderer, quitButtonTexture, NULL, &quitButtonPosition);
                    if(onButtonQuit = 1) onButtonQuit = 0;
                }
                if (mouseDown){
                    //Zone du boutton quitter
                    if( (cursorX > quitButtonPosition.x) && (cursorX < quitButtonPosition.x + quitButtonPosition.w) && (cursosY > quitButtonPosition.y) && (cursosY < quitButtonPosition.y + quitButtonPosition.h) ){
                        SDL_RenderCopy(renderer, quitClickButtonTexture, NULL, &quitClickButtonPosition);
                    }
                }

                //UPDATE DU BOUTTON SOLO
                if( (cursorX > soloButtonPosition.x) && (cursorX < soloButtonPosition.x + soloButtonPosition.w) && (cursosY > soloButtonPosition.y) && (cursosY < soloButtonPosition.y + soloButtonPosition.h) ){
                    if (!onButtonSolo){
                        //play sound
                        Mix_PlayChannel(-1, ButtonHoverSFX, 0);
                        onButtonSolo = 1;
                    }
                    SDL_RenderCopy(renderer, soloHoverButtonTexture, NULL, &soloHoverButtonPosition);
                }else{
                    SDL_RenderCopy(renderer, soloButtonTexture, NULL, &soloButtonPosition);
                    if(onButtonSolo = 1) onButtonSolo = 0;
                }
                if (mouseDown){
                    //Zone du boutton solo
                    if( (cursorX > soloButtonPosition.x) && (cursorX < soloButtonPosition.x + soloButtonPosition.w) && (cursosY > soloButtonPosition.y) && (cursosY < soloButtonPosition.y + soloButtonPosition.h) ){
                        SDL_RenderCopy(renderer, soloClickButtonTexture, NULL, &soloClickButtonPosition);
                    }
                }

                //UPDATE DU BOUTTON MULTI
                if( (cursorX > multiButtonPosition.x) && (cursorX < multiButtonPosition.x + multiButtonPosition.w) && (cursosY > multiButtonPosition.y) && (cursosY < multiButtonPosition.y + multiButtonPosition.h) ){
                    if (!onButtonMulti){
                        //play sound
                        Mix_PlayChannel(-1, ButtonHoverSFX, 0);
                        onButtonMulti = 1;
                    }
                    SDL_RenderCopy(renderer, multiHoverButtonTexture, NULL, &multiHoverButtonPosition);
                }else{
                    SDL_RenderCopy(renderer, multiButtonTexture, NULL, &multiButtonPosition);
                    if(onButtonMulti = 1) onButtonMulti = 0;
                }
                if (mouseDown){
                    //Zone du boutton solo
                    if( (cursorX > multiButtonPosition.x) && (cursorX < multiButtonPosition.x + multiButtonPosition.w) && (cursosY > multiButtonPosition.y) && (cursosY < multiButtonPosition.y + multiButtonPosition.h) ){
                        SDL_RenderCopy(renderer, multiClickButtonTexture, NULL, &multiClickButtonPosition);
                    }
                }



                while (SDL_PollEvent(&event)){
                    switch (event.type){
                    case SDL_QUIT:
                        SDL_DestroyWindow(pWindow); // fermeture de fenêtre
                        //Mix_FreeMusic(mainMenuMusic);
                        Mix_FreeChunk(mainMenuMusic);
                        Mix_CloseAudio();
                        SDL_Quit(); // fermeture SDL
                        run=0;
                        break;

                    case SDL_MOUSEBUTTONUP:
                        mouseDown = 0;
                        if (event.button.button == SDL_BUTTON_LEFT){
                            printf("\nCursorX : %d   CursorY : %d\n", cursorX, cursosY);

                            //Zone du boutton quitter
                            if( (cursorX > quitButtonPosition.x) && (cursorX < quitButtonPosition.x + quitButtonPosition.w) && (cursosY > quitButtonPosition.y) && (cursosY < quitButtonPosition.y + quitButtonPosition.h) ){
                                printf("c'est tchao");
                                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
                                SDL_DestroyWindow(pWindow); // fermeture de fenêtre
                                //Mix_FreeMusic(mainMenuMusic);
                                Mix_FreeChunk(mainMenuMusic);
                                Mix_CloseAudio();
                                SDL_Quit(); // fermeture SDL
                                run=0;
                            }
                            if( (cursorX > soloButtonPosition.x) && (cursorX < soloButtonPosition.x + soloButtonPosition.w) && (cursosY > soloButtonPosition.y) && (cursosY < soloButtonPosition.y + soloButtonPosition.h) ){
                                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
                            }
                            if( (cursorX > multiButtonPosition.x) && (cursorX < multiButtonPosition.x + multiButtonPosition.w) && (cursosY > multiButtonPosition.y) && (cursosY < multiButtonPosition.y + multiButtonPosition.h) ){
                                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
                            }

                        }
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        
                        if (event.button.button == SDL_BUTTON_LEFT){
                            mouseDown = 1;
                        }
                        break;

                    default:
                        break;
                    }
                }
                SDL_RenderPresent(renderer);
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