/*************************************************************
 *              Fichier Commun 
 * 
 * 
 * @file commun.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 22 Mars 2021
 * @brief Fichier commun fonctions aux programmes du jeu
 * @version 2.0
 * 
 * ********************************************************* */

#include <commun.h>

long highscore = 0;

int windowHeight=WINDOW_HEIGHT;
int windowWidth=WINDOW_WIDTH;


/**
 * @fn printText 
 * @brief Affiche le texte en gl
 */

void printText(int x,int y,float r, float g, float b, void* police, char* texte){
    glColor3f(r,g,b);
    glRasterPos2f(x,y);
    int len, i;
    len = strlen(texte);
    for(i=0;i<len;i++){
        glutBitmapCharacter(police,texte[i]);
    }
}

/**
 * @fn perspectiveGL 
 * @brief creer la modelisation GL de perspective
 */

void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;

    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}