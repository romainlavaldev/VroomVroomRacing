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

void initListe(t_GLintliste* l){
    l->drapeau = malloc(sizeof(t_GLintElem));
    l->drapeau->pred = l->drapeau;
    l->drapeau->succ = l->drapeau;
    l->ec = l->drapeau;
}

int listeVide(t_GLintliste* l){
    return l->drapeau->succ == l->drapeau;
}

void enFin(t_GLintliste* l){
    l->ec = l->drapeau->pred;
}

void enDebut(t_GLintliste* l){
    l->ec = l->drapeau->succ;
}

void precedent(t_GLintliste* l){
    if (!listeVide(l)){
        if (l->ec->pred != l->drapeau)
            l->ec = l->ec->pred;
        else
            l->ec = l->drapeau->pred;
    }
}

void suivant(t_GLintliste* l){
    if (!listeVide(l)){
        if (l->ec->succ != l->drapeau)
            l->ec = l->ec->succ;
        else
            l->ec = l->drapeau->succ;
    }
}

GLint valeurElt(t_GLintliste* l){
    if (!listeVide(l))
        return l->ec->valeur;
}

void modifElt(t_GLintliste* l, GLint v){
    if (!listeVide(l))
        l->ec->valeur = v;
}

void oterElt(t_GLintliste* l){
    if (!listeVide(l)){
        t_GLintElem* elemSupp = l->ec;
        l->ec->pred->succ = l->ec->succ;
        l->ec->succ->pred = l->ec->pred;
        l->ec = l->ec->pred;
        free(elemSupp);
    }
}

void ajoutDroit(t_GLintliste* l, GLint v){
    
        t_GLintElem* elemAjout;
        elemAjout->pred = l->ec;
        elemAjout->succ = l->ec->succ;
        l->ec->succ->pred = elemAjout;
        l->ec->succ = elemAjout;
    
}

void ajoutGauche(t_GLintliste* l, GLint v){
    
        t_GLintElem* elemAjout;
        elemAjout->succ = l->ec;
        elemAjout->pred = l->ec->pred;
        l->ec->pred->succ = elemAjout;
        l->ec->pred = elemAjout;
        
    
}
