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
#include <RawModel.h>
#include <list.h>

t_GLintliste* vaos;
t_GLintliste* vbos;

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
    RawModel rm = {vaoID, len(positions)/3};
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
    GLint vaoID;
    glGenVertexArrays(1, &vaoID);
    ajoutDroit(vaos, vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

/**
 * @fn storeDataInAttributeList 
 * @brief Créer le VAO
 * @param int attributeNumber
 * @param GLfloat data[]
 * @return 
 */

void storeDataInAttributeList(int attributeNumber, GLfloat data[]){
    int vboID;
    glGenBuffers(1, &vboID);
    ajoutDroit(vbos, vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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