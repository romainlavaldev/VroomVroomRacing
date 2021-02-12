
/*******************************************************************************
 *  INCLUDE 
 ******************************************************************************/


#include <stdio.h>
#include <SDL.h> 
#include <SDL_mixer.h>

 
void load_button(SDL_Window * pWindow){ // à tester

    // Declaration des boutons
    SDL_Surface *button_solo = NULL;
    SDL_Surface *button_multi = NULL;
    SDL_Surface *button_option = NULL;

    // Affectation de type Rect
    SDL_Rect position, positionButton_solo, positionButton_multi, positionButton_option;

    //Position Button

    // Solo
    positionButton_solo.x = 100;
    positionButton_solo.y = 100;

    // multi
    positionButton_multi.x = 200;
    positionButton_multi.y = 100;

    // option
    positionButton_option.x = 300;
    positionButton_option.y = 100;


    // Boutons = Image
    button_solo = IMG_Load('IMG_PATH');
    button_multi = IMG_Load('IMG_PATH');
    button_option = IMG_Load('IMG_PATH');

    // Positionnement Image / bouton

    SDL_BlitSurface (button_solo, NULL, pWindow, &positionButton_solo);
    SDL_BlitSurface (button_multi, NULL, pWindow, &positionButton_multi);
    SDL_BlitSurface (button_option, NULL, pWindow, &positionButton_option);


    // Si les images n'ont pas load, get code erreur
    if(!button_solo || !button_multi || !button_option){
        printf("IMG_LOAD : %s\n", IMG_GetError());
    }
}



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
  /*  
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

*/
    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1280,
                                                                  720,
                                                                  SDL_WINDOW_SHOWN);


        //
        // CREATION DE L'AUDIO
        //
        

                                                                  
/*******************************************************************************
 *  MENU 
 ******************************************************************************/
        if( pWindow )
        {
            SDL_Event event;
            //Mix_PlayMusic(mainMenuMusic, -1);
            int run=1;
            while (run){


                load_button(pWindow);



                while (SDL_PollEvent(&event)){
                    switch (event.type){
                    case SDL_QUIT:
                        SDL_DestroyWindow(pWindow); // fermeture de fenêtre
                        //Mix_FreeMusic(mainMenuMusic);
                        //Mix_CloseAudio();
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
    }

    Mix_CloseAudio();
    SDL_Quit(); // fermeture SDL
    return 0; // Fin correct du programmes
}