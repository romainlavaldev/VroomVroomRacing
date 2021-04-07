#include <stdio.h>
#include <stdlib.h>
#include <SDL.h> 
#include <SDL_mixer.h>


#define true 1
#define false 0

/**
 * @struct image_s
 * 
 * @brief Structure représentant une image
 * 
 * Recupère une texture et une position pour utiliser une image
 */

typedef struct image_s
{
    SDL_Texture* texture;
    SDL_Rect position;
}image_t;