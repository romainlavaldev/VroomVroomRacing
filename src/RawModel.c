/*************************************************************
 *              Creation de Modele 
 * 
 * 
 * @file RawModel.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 12 Mars 2021
 * @brief Creation des modeles raw VAO du jeu
 * @version 1.0
 * 
 * ********************************************************* */

#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <RawModel.h>
#include <list.h>

t_GLuintliste* vaos;
t_GLuintliste* vbos;

void initRawModels(){
    initListe(vaos);
    initListe(vbos);
}

/**
 * @fn loadToVAO 
 * @brief Charge les positions d'un objet VAO (composé de plusieurs VBO)
 * @param GLfloat positions[]
 * @return rm
 */

RawModel loadToVAO(GLfloat positions[]){
    int vaoID = createVAO();
    storeDataInAttributeList(0,positions);
    unbindVAO();
    RawModel rm = {vaoID, sizeof(positions)/sizeof(GLfloat)/3};
    return rm;
}

void cleanUp(){
    while(!listeVide(vaos)){
        glDeleteVertexArrays(1, valeurElt(vaos));
        oterElt(vaos);
    }

    while(!listeVide(vbos)){
        glDeleteBuffers(1, valeurElt(vbos));
        oterElt(vbos);
    }
}

/**
 * @fn createVAO 
 * @brief Créer le VAO
 * @return vaoID
 */

int createVAO(){
    printf("\n---- Création d'un vao ----\n");
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    printf("Vao %i créaiy\n", vaoID);
    printf("Liste VAO vide ? : %i\n", listeVide(vaos));
    ajoutDroit(vaos, vaoID);
    printf("Vao %d ajouté à la liste des vaos\n", vaoID);
    glBindVertexArray(vaoID);
    printf("Vao %d bindé (pret a l'update)\n", vaoID);
    return vaoID;
}

/**
 * @fn unbindVAO 
 * @brief 
 * @param 
 * @param 
 * @return 
 */

void unbindVAO(){
    glBindVertexArray(0);
}