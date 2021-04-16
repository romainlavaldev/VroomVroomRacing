#ifndef GAME_H
#define GAME_H

#include <commun.h>
#include <voiture.h>
#include <objetsNiveaux.h>

int aziy;
int elex;
float camDist;
int droiteGaucheKey;
int avantArriereKey;
extern int currentObj;
extern int gameOver;

double boucleRoute;

long temps_last_update, temps_total;

Voiture voitureJoueur;
void enterGame();
void gameLoop();
void jeuRender();
void gameOverRender();
void victoireRender();
void updateJeu();
void updateVoitureJoueur();
void updateObjets();
void quitterjeu();

void EnterEvents();
void jeuSpecialKey(int key, int x, int y);
void jeuSpecialKeyUp(int key, int x, int y);
void jeuAsciiKey(int key, int x, int y);
void jeuMouseWheel(int button, int dir, int x, int y);

void jeuMouseMove(int x, int y);

void changeCamera(int x, int y);

#endif