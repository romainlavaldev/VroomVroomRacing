/*************************************************************
 *              Fichier Commun 
 * 
 * 
 * @file commun.h
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 22 Mars 2021
 * @brief Fichier commun aux programmes du jeu
 * @version 2.0
 * 
 * ********************************************************* */
#ifndef COMMUN_H
#define COMMUN_H

#include <stdio.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <glm.h>

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

#define FPS 30
#define NF 1000/FPS

int GamePlaying; //0 : off, 1 : pause, 2 : running,
int niveau; //1 : Retrowave, 2 : Rainbow

//text
GLuint TexArray[20]; //tab des textures

//models
GLuint tex_app;
GLMmodel* voitureModel1;
GLMmodel* roueModel1;
GLMmodel* poubelleModel;
GLMmodel* finishModel;
GLMmodel* panneauModel;
GLMmodel* ovniModel;
GLMmodel* starModel;

/**
 * @struct Textures
 * 
 *
 * @brief Load les textures du jeu
 */

enum Textures{
    TEXTURE_VOITURE1=0,
    TEXTURE_ROUTE,
    TEXTURE_ROUE,
    TEXTURE_MENUBACK,
    TEXTURE_MENU1,
    TEXTURE_MENU2,
    TEXTURE_INTRO,
    TEXTURE_SURR,
    TEXTURE_CIEL,
    TEXTURE_TREE,
    TEXTURE_COMPTEUR,
    TEXTURE_PTR,
    TEXTURE_GAMEOVER,
    TEXTURE_POUBELLE,
    TEXTURE_NONE,
    TEXTURE_FINISH,
    TEXTURE_SAND,
    TEXTURE_STAR
};

enum TypesObjet{
    TYPE_OBSTACLE_FIXE,
    TYPE_OBSTACLE_MOUV,
    TYPE_FINISH
};

extern long highscore;
extern int windowHeight,windowWidth;
void printText(int x,int y,float r, float g, float b, void* police, char* texte);
void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );

#endif