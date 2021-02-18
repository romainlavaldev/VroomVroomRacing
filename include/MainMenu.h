#include <SDL_mixer.h>

//! Charge son menu principal.
void loadMainMenuSounds();
//! Charge image menu principal.
void loadMainMenuImages();
//! Update les images lors d'actions utilisateurs.
void updateMainMenuFrame();


//! Load main Menu (son,images, et demarrage).
void loadMainMenu();

extern Mix_Chunk* mainMenuMusic;
