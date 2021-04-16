#ifndef OBJETSNIVEAUX_H
#define OBJETSNIVEAUX_H

#include "commun.h"

typedef struct{
    float x,y;
    float moveSpeed;
    GLuint texture;
    GLMmodel* model;
    int type;
    int sens; //1 : droite    -1 : gauche      0 : rien (pour les objets fixes)
} objet;

void objetRender(objet obj);
void initNiveau1();
void initNiveau2();
void initNiveau3();

extern int nbObjetsNiveau1;
extern objet objetsNiveau1[];

extern int nbObjetsNiveau2;
extern objet objetsNiveau2[];

extern int nbObjetsNiveau3;
extern objet objetsNiveau3[];

extern int* nbObjetsNiveauAct;
extern objet* objetsNiveauAct;

#endif