/*************************************************************
 *              Game Window 
 * 
 * @file TestOpenGLGLFW.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 12 Mars 2021
 * @brief Programme render 3D de test du jeu
 * @version 1.0
 * 
 * ********************************************************* */

#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <TestOpenGLGLFW.h>
#include <Renderer.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

int main (){
    GLFWwindow* window; //déclaration fenêtre

    //Init de GLFW
    if (!glfwInit()){
        return -1;
    }

    //Creation d'une fenetre en fenetré avec context openGL
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test", NULL, NULL); //création fenêtre

    //Setup de la fonction keyCallback (elle sera appellé des qu'une touche est appuyé)
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    if (!window){
        glfwTerminate();
        return -1;
    }

    //Creation du contexte de la fenetre
    glfwMakeContextCurrent(window);


    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    //Tableaux des vertices
    GLfloat vertices[] = 
    {
        SCREEN_WIDTH/4, SCREEN_HEIGHT*3/4, 0.0, //Quad debut
        SCREEN_WIDTH*3/4, SCREEN_HEIGHT*3/4, 0.0,
        SCREEN_WIDTH*3/4, SCREEN_HEIGHT/4, 0.0, 
        SCREEN_WIDTH/4, SCREEN_HEIGHT/4, 0.0 //Quad fin
    };

    RawModel squareModel = loadToVAO(vertices);

    double Xpos = 0, yPos = 0;

    double seconds = 0;
    glfwSetTime(0);

    //Loop jusqu'a fermeture par l'user
    while (!glfwWindowShouldClose(window))
    {
        //glClear(GL_COLOR_BUFFER_BIT);
        prepare();
        render(squareModel);
        //Rendu OPENGL -> METTRE DU LE CODE OPENGL ICI
        glfwGetCursorPos(window, &Xpos, &yPos);

        seconds = glfwGetTime();
        printf("Secondes : %f\n", seconds);

        /*glPushMatrix();
        glTranslatef(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -500);  //FAIRE UN CUBE
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        glTranslatef(-SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, 500);

        drawCube(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -500, 200);


        glPopMatrix();*/





        /*glEnableClientState(GL_VERTEX_ARRAY);    //FAIRE UN CARRE (wahou)
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);*/

        //Echanger les buffer front et backs
        glfwSwapBuffers(window);

        //Events
        glfwPollEvents();
    }

    cleanUp();
    glfwTerminate();
    return 0;
}


/**
 * @fn drawCube 
 * @brief Creation d'un cube
 * @param GLfloat centerPoX
 * @param GLfloat centerPosY
 * @param GLfloat centerPosZ
 * @param GLfloat edgeLength
 */


void drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){

    GLfloat halfSideLength = edgeLength / 2;
    GLfloat vertices[] = 
    {
        //Front Face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top Left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top Right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Left
        //Back Face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Left
        //Left Face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top Left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Left
        //Right Face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top Left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Left
        //Top Face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Bottom Right
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Bottom Left
        //Bottom Face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Top Left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Top Right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Left
    };

    GLfloat colour[] = {
        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22,

        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22,

        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22,

        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22,

        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22,

        255, 0, 0,
        0, 255, 0,
        255, 0, 255,
        255, 175, 22
    };

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Mettre en vue "squelette"

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colour);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}

/**
 * @fn keyCallback 
 * @brief Capte les évenements clavier de press key
 * @param GLFWwindow* window
 * @param int key
 * @param int scancode
 * @param int action
 * @param int mods
 */

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){

    //printf("Key : %d\n", key);

    const GLfloat rotationSpeed = 10;

    //Actions : GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT
    if (action = GLFW_PRESS || action == GL_REPEAT){
        switch (key)
        {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;
        
        default:
            break;
        }
    }
}