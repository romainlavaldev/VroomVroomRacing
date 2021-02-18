
/*************************************************************
 *                  Faciliter les fonctions SDL
 * 
 * 
 * @file easySDL.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 25 Janvier 2021
 * @brief fonction visant la facilité de la doc SDL2
 * @version 1.0
 * 
 * ********************************************************* */




#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>


/*************************************************************
 *                         INITIALISATION SDL VIDEO
 * 
 * @fn void initSDL
 * @brief Si le SDL n'est pas pris en charge, renvoie -1 et affiche un code erreur.
 * ********************************************************* */

int initSDL(){
    printf("Début de l'initialisation du SDL\n"); // Debug initSDL
    
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }
    printf("Fin de l'initialisation du SDL\n");
}


/*************************************************************
 *                         INITIALISATION SON SYSTEME  
 * 
 * @fn void initSoundSystem
 * @brief Si le SDL mixer audio n'est pas pris en charge, renvoie -1 et affiche un code erreur.          
 * ********************************************************* */

int initSoundSystem(){
    printf("Début de l'initialisation du system audio\n"); // Debug InitSoundSystem

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
        return -1;
    }
    printf("Fin de l'initialisation du system audio\n"); 
}
