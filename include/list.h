#include <glfw3.h>

typedef struct GLuintElem {
    GLuint valeur ;
    struct GLuintElem* pred ;
    struct GLuintElem* succ ;
} t_GLuintElem;

typedef struct{
    t_GLuintElem* drapeau;
    t_GLuintElem* ec;
}t_GLuintliste;

void initListe(t_GLuintliste* l);

int listeVide(t_GLuintliste* l);

int horsListe(t_GLuintliste *l);

void enFin(t_GLuintliste* l);

void enDebut(t_GLuintliste* l);

void precedent(t_GLuintliste* l);

void suivant(t_GLuintliste* l);

GLuint valeurElt(t_GLuintliste* l);

void modifElt(t_GLuintliste* l, GLuint v);

void oterElt(t_GLuintliste* l);

void ajoutDroit(t_GLuintliste* l, GLuint v);

void ajoutGauche(t_GLuintliste* l, GLuint v);
