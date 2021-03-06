#include <SDL.h>
#include <glew.h>
#include <glfw3.h>
#include <stdio.h>

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

    static const GLfloat vertices[] = {
    -0.8f,-0.8f,-0.8f, // triangle 1 : begin
    -0.8f,-0.8f, 0.8f,
    -0.8f, 0.8f, 0.8f, // triangle 1 : end
    0.8f, 0.8f,-0.8f, // triangle 2 : begin
    -0.8f,-0.8f,-0.8f,
    -0.8f, 0.8f,-0.8f, // triangle 2 : end
    0.8f,-0.8f, 0.8f,
    -0.8f,-0.8f,-0.8f,
    0.8f,-0.8f,-0.8f,
    0.8f, 0.8f,-0.8f,
    0.8f,-0.8f,-0.8f,
    -0.8f,-0.8f,-0.8f,
    -0.8f,-0.8f,-0.8f,
    -0.8f, 0.8f, 0.8f,
    -0.8f, 0.8f,-0.8f,
    0.8f,-0.8f, 0.8f,
    -0.8f,-0.8f, 0.8f,
    -0.8f,-0.8f,-0.8f,
    -0.8f, 0.8f, 0.8f,
    -0.8f,-0.8f, 0.8f,
    0.8f,-0.8f, 0.8f,
    0.8f, 0.8f, 0.8f,
    0.8f,-0.8f,-0.8f,
    0.8f, 0.8f,-0.8f,
    0.8f,-0.8f,-0.8f,
    0.8f, 0.8f, 0.8f,
    0.8f,-0.8f, 0.8f,
    0.8f, 0.8f, 0.8f,
    0.8f, 0.8f,-0.8f,
    -0.8f, 0.8f,-0.8f,
    0.8f, 0.8f, 0.8f,
    -0.8f, 0.8f,-0.8f,
    -0.8f, 0.8f, 0.8f,
    0.8f, 0.8f, 0.8f,
    -0.8f, 0.8f, 0.8f,
    0.8f,-0.8f, 0.8f
};

    while(!terminer)
    {
        SDL_WaitEvent(&evenements);

	    if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	        terminer = 1;
            

        
        // Nettoyage de l'écran
        glClear(GL_COLOR_BUFFER_BIT);

        
        //Affichage d'un triange
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLES, 0, 12*3);
        
        glDisableVertexAttribArray(0);


        // Actualisation de la fenêtre
        SDL_GL_SwapWindow(fenetre);
    }   


    // On quitte la SDL
	SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
	
    return 0;
}