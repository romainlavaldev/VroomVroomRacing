

// INCLUDE 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>

// Fonction initiation SDL



// Chargement de la vidéo et de l'audio
//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


// Chargement de la vidéo only
//SDL_Init(SDL_INIT_VIDEO);

// Chargement de tout wolah
//SDL_Init(SDL_INIT_EVERYTHING);



//SDL_Quit();


 
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL;

    SDL_version vers;
    SDL_VERSION(&vers);

    printf("La version : %d.%d.%d", vers.major, vers.minor, vers.patch);

     if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }




     SDL_Init(SDL_INIT_VIDEO); // Démarrage de la SDL (ici : chargement du système vidéo)
 
    /*
    La SDL est chargée.
    Vous pouvez mettre ici le contenu de votre programme
    */
 



    // Affichage fenêtre
    //SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    




    // Title
    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
 


    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).
 
    return 0;
}