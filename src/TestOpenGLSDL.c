#include <SDL.h>
#include <glew.h>
#include <glfw3.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480



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
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);


    // Création du contexte OpenGL
    contexteOpenGL = SDL_GL_CreateContext(fenetre);

    if(contexteOpenGL == 0)
    {
        SDL_DestroyWindow(fenetre);
        SDL_Quit();

        return -1;
    }



    // On initialise GLEW

    GLenum initialisationGLEW = glewInit();

    // Si l'initialisation a échouée :

    if(initialisationGLEW != GLEW_OK)
    {
        // On affiche l'erreur grâce à la fonction : glewGetErrorString(GLenum code)

        printf("Erreur d'initialisation de GLEW : ");
        printf(glewGetErrorString(initialisationGLEW));

        // On quitte la SDL

        SDL_GL_DeleteContext(contexteOpenGL);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();

        return -1;
    }

    //Tableaux des vertices
    GLfloat vertices[] = 
    {
        SCREEN_WIDTH/4, SCREEN_HEIGHT*3/4, 0.0, //Quad debut
        SCREEN_WIDTH*3/4, SCREEN_HEIGHT*3/4, 0.0,
        SCREEN_WIDTH*3/4, SCREEN_HEIGHT/4, 0.0, 
        SCREEN_WIDTH/4, SCREEN_HEIGHT/4, 0.0 //Quad fin
    };

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while(!terminer)
    {
        SDL_WaitEvent(&evenements);

	    if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	        terminer = 1;
            
                    
        // Nettoyage de l'écran
        glClear(GL_COLOR_BUFFER_BIT);

        
        //Rendu OPENGL -> METTRE DU LE CODE OPENGL ICI
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);

        // Actualisation de la fenêtre
        SDL_GL_SwapWindow(fenetre);
    }   


    // On quitte la SDL
	SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
	
    return 0;
}