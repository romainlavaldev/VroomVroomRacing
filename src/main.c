/*************************************************************
 *              Main 
 * 
 * 
 * @file main.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 22 Mars 2021
 * @brief Fichier principal de compilation du jeu
 * @version 2.0
 * 
 * ********************************************************* */

#include <stdio.h>
#include <init.h>
#include <jeu.h>
//#include <SDL/VVR.h>

int main(int argc, char *argv[]){
    //VVR_SDL();
    //printf("*** Init de la fenetre ***\n\n");
    initWindow(argc, argv); //Window + Resources + Setup GL

    niveau = 1;
    printf("\nNiveau : %d\n", niveau);
    
    enterGame();
    glutMainLoop();
    return 0;
}