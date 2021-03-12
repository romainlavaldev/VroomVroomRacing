#include <glfw3.h>

typedef struct GLintElem {
    GLint valeur ;
    struct GLintElem* pred ;
    struct GLintElem* succ ;
} t_GLintElem;

typedef struct{
    t_GLintElem* drapeau;
    t_GLintElem* ec;
}t_GLintliste;

void initListe(t_GLintliste* l);

int listeVide(t_GLintliste* l);

void enFin(t_GLintliste* l);

void enDebut(t_GLintliste* l);

void precedent(t_GLintliste* l);

void suivant(t_GLintliste* l);

int valeurElt(t_GLintliste* l);

void modifElt(t_GLintliste* l, GLint v);

void oterElt(t_GLintliste* l);

void ajoutDroit(t_GLintliste* l, GLint v);

void ajoutGauche(t_GLintliste* l, GLint v);
