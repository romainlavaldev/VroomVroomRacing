//
// Created by romain on 1/26/

#include <stdio.h>
#include <stdlib.h>


int renvoie (void)
{
    int entier;
    printf("Entrer un entier : ");
    scanf("%i", &entier);


    return entier;
}



int main(){
    printf("Salut à tous les amis, le chiffre c'est : %i", renvoie());
    return 1;
}

