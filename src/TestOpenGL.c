#include <SDL.h>

int main(int argc, char **argv)
{
	
    SDL_Window* fenetre;
    SDL_GLContext contexteOpenGL;

    SDL_Event evenements;
    int terminer = 0;
    
	
    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Quit();
        return -1;
    }
	
    // Version d'OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	


    // Création de la fenêtre
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	

    // Création du contexte OpenGL
    contexteOpenGL = SDL_GL_CreateContext(fenetre);

    if(contexteOpenGL == 0)
    {
        SDL_DestroyWindow(fenetre);
        SDL_Quit();

        return -1;
    }


    while(!terminer)
    {
	    SDL_WaitEvent(&evenements);
		
	    if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	        terminer = 1;
    }


    // On quitte la SDL
	SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
	
    return 0;
}