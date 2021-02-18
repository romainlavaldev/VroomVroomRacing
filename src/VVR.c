/*************************************************************
 *              Main Window 
 * 
 * 
 * @file VVR.c
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
#include <SDL.h>
#include <easySDL.h>
#include <VVR.h>
#include <commun.h>
#include <MainMenu.h>

char fullscreen = 'n';
SDL_Renderer* renderer;

SDL_Event event;

int running = true;
int leftMouseDown = false;
 
int main(int argc, char *argv[])
{

    printf("Démarrage du jeu trop bien de ouf\n"); // Debug main step 1

    initSDL();
    initSoundSystem();

    printf("Fullscreen ? (y : yes) : ");
    scanf("%c", &fullscreen);

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

        //updateMainMenuFrame(event);


        while(running){
            while (SDL_PollEvent(&event)){

                switch (event.type)
                {
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button = SDL_BUTTON_LEFT)
                        leftMouseDown = true;
                    break;

                case SDL_MOUSEBUTTONUP:
                    if(event.button.button = SDL_BUTTON_LEFT)
                        leftMouseDown = false;
                        break;

                case SDL_QUIT:
                    quitter();
                    break;

                default:
                    break;
                }
                //printf("Event !\n"); // debug main step 3

                updateMainMenuFrame(event);
            }
            
            SDL_RenderPresent(renderer);
        }
    }
    else
        printf("Erreur de création de la fenêtre: %s\n",SDL_GetError()); // La fenêtre SDL n'a pas pu charger

    return 0;
}


void quitter(){
    running = false;
    Mix_CloseAudio();
    SDL_Quit(); // fermeture SDL
}