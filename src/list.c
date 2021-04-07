/*************************************************************
 *              Liste 
 * 
 * 
 * @file list.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 12 Mars 2021
 * @brief Creation d'une liste
 * @version 1.0
 * 
 * ********************************************************* */

#include <list.h>
#include <stdlib.h>
#include <stdio.h>

void initListe(t_GLuintliste* l){
    printf("\nDebut init d'une liste\n");
    l = (t_GLuintliste*)malloc(sizeof(t_GLuintliste));
    printf("malloc de la liste\n");
    l->drapeau = (t_GLuintElem*)malloc(sizeof(t_GLuintElem));
    printf("malloc drapeau\n");
    l->drapeau->pred = l->drapeau;
    l->drapeau->succ = l->drapeau;
    l->ec = l->drapeau;
    printf("Liste initialisée\n\n");
}

int listeVide(t_GLuintliste* l){
    return ((l->drapeau->pred == l->drapeau) && (l->drapeau->succ == l->drapeau));
}

int horsListe(t_GLuintliste *l) {
	return (l->ec == l->drapeau);
}

void enFin(t_GLuintliste* l){
    if(!listeVide(l))
		l->ec = l->drapeau->succ;
}

void enDebut(t_GLuintliste* l){
    if(!listeVide(l))
		l->ec = l->drapeau->pred;
}

void precedent(t_GLuintliste* l){
    if(!horsListe(l))
		l->ec = l->ec->pred;
}

void suivant(t_GLuintliste* l){
    if(!horsListe(l))
		l->ec = l->ec->succ;
}

GLuint valeurElt(t_GLuintliste* l){
    if(!horsListe(l))
        return l->ec->valeur;
}

void modifElt(t_GLuintliste* l, GLuint v){
    if(!horsListe(l))
        l->ec->valeur = v;
}

void oterElt(t_GLuintliste* l){
    if(!horsListe(l)){
        t_GLuintElem* elemSupp;
        
        (l->ec->pred)->succ = l->ec->succ;
        (l->ec->succ)->pred = l->ec->pred;
        elemSupp = l->ec;
        precedent(l);
        free(elemSupp);
    }
}

void ajoutDroit(t_GLuintliste* l, GLuint v){
    if(listeVide(l) || !horsListe(l)) {

        printf("\n--- Ajout d'un element à une liste ---\n");
        t_GLuintElem* elemAjout = (t_GLuintElem*)malloc(sizeof(t_GLuintElem));
        printf("Création elemAjout (init + malloc)\n");

        elemAjout->valeur = v;
        elemAjout->pred = l->ec;
        elemAjout->succ = l->ec->succ;
        printf("Pred + Succ de l'elem ajout\n");

        (l->ec->succ)->pred = elemAjout;
        l->ec->succ = elemAjout;
        printf("Pred + Succ de l'elem courant\n");
        l->ec = elemAjout;
        printf("Positionnement sur le nouvel elem\n");
        printf("--- Fin ajout d'element ---\n");
    }
}

void ajoutGauche(t_GLuintliste* l, GLuint v){
    
        if(listeVide(l) || !horsListe(l)) {

        printf("\n--- Ajout d'un element à une liste ---\n");
        t_GLuintElem* elemAjout = malloc(sizeof(t_GLuintElem));
        printf("Création elemAjout (init + malloc)\n");

        elemAjout->valeur = v;
        elemAjout->pred = l->ec->pred;
        elemAjout->succ = l->ec;
        printf("Pred + Succ de l'elem ajout\n");

        (l->ec->pred)->succ = elemAjout;
        l->ec->pred = elemAjout;
        printf("Pred + Succ de l'elem courant\n");
        l->ec = elemAjout;
        printf("Positionnement sur le nouvel elem\n");
        printf("--- Fin ajout d'element ---\n");
    }
}
