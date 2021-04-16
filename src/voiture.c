/*************************************************************
 * @file voiture.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 22 Mars 2021
 * @brief Fonctions des vrooms
 * @version 2.0
 * ********************************************************* */

#include <voiture.h>

/**
 * @fn createVoiture 
 * @brief Alloue et crée une vroom
 */

Voiture* createVoiture(GLuint* textureVoiture){

    Voiture* v = malloc(sizeof(Voiture));
    return v;
}

/**
 * @fn jeuRenvoitureRenderr 
 * @brief charge une vroom
 */

void voitureRender(Voiture voiture){
    glEnable(GL_TEXTURE_2D);
    glPushMatrix(); //Matrice de la voiture

    //Chassis
    glRotatef(0.0,1.0,0,0);
    glTranslatef(voiture.x, 0.6, -voiture.y);
    glRotatef(-voiture.rotation, 0.0, 1, 0.0);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_VOITURE1]);
    glmDraw(voitureModel1, GLM_SMOOTH | GLM_TEXTURE);

    //Roues
    glRotated(-90, 0, 1, 0);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_ROUE]);

    //Avant Gauche
    glPushMatrix();
    glTranslatef(-1.205,-0.277,0.733);
    glRotatef(-(voiture.rotation*2)+90,0,1,0);
    glRotatef(voiture.rotationRoue,-1,0,0);
    glmDraw(roueModel1,GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    //Avant Droit
    glPushMatrix();
    glTranslatef(-1.206,-0.277,-0.731);
    glRotatef(-(voiture.rotation*2)+270,0,1,0);
    glRotatef(voiture.rotationRoue,1,0,0);
    glmDraw(roueModel1,GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    //Arriere Gauche
    glPushMatrix();
    glTranslatef(1.155,-0.277,0.731);
    glRotatef(90,0,1,0);
    glRotatef(voiture.rotationRoue,-1,0,0);
    glmDraw(roueModel1,GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    //Arriere Droit
    glPushMatrix();
    glTranslatef(1.154,-0.277,-0.733);
    glRotatef(270,0,1,0);
    glRotatef(voiture.rotationRoue,1,0,0);
    glmDraw(roueModel1,GLM_SMOOTH | GLM_TEXTURE);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}