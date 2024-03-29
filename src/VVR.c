/*************************************************************
 *              Main Window 
 * 
 * 
 * @file main.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 25 Janvier 2021
 * @brief Programme principal du jeu
 * @version 1.0
 * 
 * ********************************************************* */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/easySDL.h>
#include <SDL/VVR.h>
//#include <SDL/commun.h>
#include <SDL/MainMenu.h>
#include <SDL/SoloCircuitMenu.h>
#include <SDL/SoloVoitureMenu.h>

char fullscreen = 'n';
SDL_Renderer* renderer;

SDL_Event event;

int running = 1;
int leftMouseDown = 0;

Mix_Chunk* ButtonHoverSFX;
Mix_Chunk* ButtonClickedSFX;
Mix_Chunk* ButtonBackSFX;

int ActiveMenu = 1;  //1 = MainMenu    2 = SoloCircuitMenu    3 = SoloVoitureMenu
 
/**
 * @fn quitter 
 * @brief Bouton quitter le jeu
 */

void quitter(){
    running = 0;
    Mix_CloseAudio();
    SDL_Quit(); // fermeture SDL
}

int main(int argc, char* argv[])
{

    printf("Démarrage du jeu trop bien de ouf\n"); // Debug main step 1
    printf("*** Init de la fenetre ***\n\n");
    //initWindow(argc,argv); //Window + Resources + Setup GL
    initSDL();
    initSoundSystem();

    /*
    printf("Fullscreen ? (y : yes) : ");
    scanf("%c", &fullscreen);
    */
    fullscreen = 'n';

    SDL_Window* mainWindow = NULL;
    if (fullscreen == 'y')
        mainWindow = SDL_CreateWindow("VROOM VROOM RACIIIIIIING !!!!",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1280,
                                                                  720,
                                                                  SDL_WINDOW_FULLSCREEN_DESKTOP);
    else
        mainWindow = SDL_CreateWindow("VROOM VROOM RACIIIIIIING !!!!",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1280,
                                                                  720,
                                                                  SDL_WINDOW_SHOWN);
    

    printf("Creation de la fenêtre\n"); // debug main step 2


    renderer = SDL_CreateRenderer(mainWindow, -1, 0);
    printf("\n\nRENDERER CREATED AT : %ld", (long)renderer);
    SDL_RenderSetLogicalSize(renderer, 1920, 1080);

    


        
    if (mainWindow){
        loadMainMenu();
        loadSoloCircuitMenu();
        loadSoloVoitureMenu();
        updateMainMenuFrame(event);


        while(running){
            while (SDL_PollEvent(&event)){

                switch (event.type)
                {
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button = SDL_BUTTON_LEFT)
                        leftMouseDown = 1;
                    break;

                case SDL_MOUSEBUTTONUP:
                    if(event.button.button = SDL_BUTTON_LEFT)
                        leftMouseDown = 0;

                        break;

                case SDL_QUIT:
                    quitter();
                    break;

                default:
                    break;
                }
                //printf("Event !\n"); // debug main step 3

                switch (ActiveMenu)
                {
                case 1: //MainMenu
                    updateMainMenuFrame(event);
                    break;
                
                case 2: //SoloCircuitMenu
                    updateSoloCircuitMenuFrame(event);
                    break;

                case 3: //SoloVoitureMenu
                    updateSoloVoitureMenuFrame(event);
                    break;
                    
                default:
                    break;
                }
            }
            
            SDL_RenderPresent(renderer);
        }
    }
    else
        printf("Erreur de création de la fenêtre: %s\n",SDL_GetError()); // La fenêtre SDL n'a pas pu charger
return 0;
}

