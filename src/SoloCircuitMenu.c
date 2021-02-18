
/*************************************************************
 *              Fenêtre d'ouverture 
 * 
 * 
 * @file MainMenu.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 25 Janvier 2021
 * @brief Menu principal, et d'accès vers les autres fenêtre
 * @version 1.0
 * 
 * ********************************************************* */

#include <stdio.h>
#include <SDL.h> 
#include <SDL_mixer.h>
//! Introduit le dossier principal VVR
#include <VVR.h>
//! récupère dossier commun
#include <commun.h>
#include <SoloCircuitMenu.h>

/**
 * @fn loadMainMenuSounds 
 * @brief Load les sons du Menu
 */

void loadSoloCircuitMenuSounds(){

    ButtonHoverSFX = NULL;
    ButtonHoverSFX = Mix_LoadWAV("sound/SFX/buttonHover.mp3");

    ButtonClickedSFX = NULL;
    ButtonClickedSFX = Mix_LoadWAV("sound/SFX/ButtonClicked.mp3");

}

/// Définition des boutons de la main window

    image_t bg;
    image_t btnCircuit;
    image_t btnCircuitH;
    image_t btnCircuitC;
    image_t btnRetour;
    image_t btnRetourH;
    image_t btnRetourC;


/**
 * @fn loadMainMenuImages 
 * @brief Load les images du Menu
 */

void loadSoloCircuitMenuImages(){
        //Fond
        SDL_Surface* bgTmp = SDL_LoadBMP("img/SoloCircuitmenu/fond.bmp");
        bg.texture = SDL_CreateTextureFromSurface(renderer, bgTmp);
        SDL_FreeSurface(bgTmp);
        bg.position.x = 0;
        bg.position.y = 0;
        bg.position.w = 1920;
        bg.position.h = 1080;
        //SDL_RenderCopy(renderer, bg.texture, NULL, &(bg.position));

        //Boutton Circuit
        SDL_Surface* CircuitButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/circuit_1.bmp");
        btnCircuit.texture = SDL_CreateTextureFromSurface(renderer, CircuitButtonTmp);
        SDL_FreeSurface(CircuitButtonTmp);
        btnCircuit.position.x = 586;
        btnCircuit.position.y = 319;
        btnCircuit.position.w = 1334;
        btnCircuit.position.h = 150;

        //Boutton CircuitHover
        SDL_Surface* CircuitHoverButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/circuit_1_h.bmp");
        btnCircuitH.texture = SDL_CreateTextureFromSurface(renderer, CircuitHoverButtonTmp);
        SDL_FreeSurface(CircuitHoverButtonTmp);
        btnCircuitH.position.x = 586;
        btnCircuitH.position.y = 319;
        btnCircuitH.position.w = 1334;
        btnCircuitH.position.h = 150;

        //Boutton CircuitClick
        SDL_Surface* CircuitClickButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/circuit_1_c.bmp");
        btnCircuitC.texture = SDL_CreateTextureFromSurface(renderer, CircuitClickButtonTmp);
        SDL_FreeSurface(CircuitClickButtonTmp);
        btnCircuitC.position.x = 586;
        btnCircuitC.position.y = 319;
        btnCircuitC.position.w = 1334;
        btnCircuitC.position.h = 150;


        //Boutton Retour
        SDL_Surface* retourButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/retour.bmp");
        btnRetour.texture = SDL_CreateTextureFromSurface(renderer, retourButtonTmp);
        SDL_FreeSurface(retourButtonTmp);
        btnRetour.position.x = 1030;
        btnRetour.position.y = 901;
        btnRetour.position.w = 890;
        btnRetour.position.h = 100;


        //Boutton RetourHover
        SDL_Surface* retourHoverButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/retour_h.bmp");
        btnRetourH.texture = SDL_CreateTextureFromSurface(renderer, retourHoverButtonTmp);
        SDL_FreeSurface(retourHoverButtonTmp);
        btnRetourH.position.x = 1030;
        btnRetourH.position.y = 901;
        btnRetourH.position.w = 890;
        btnRetourH.position.h = 100;

        //Boutton RetourClick
        SDL_Surface* retourClickButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/circuit_1_c.bmp");
        btnRetourC.texture = SDL_CreateTextureFromSurface(renderer, retourClickButtonTmp);
        SDL_FreeSurface(retourClickButtonTmp);
        btnRetourC.position.x = 1030;
        btnRetourC.position.y = 901;
        btnRetourC.position.w = 890;
        btnRetourC.position.h = 100;
}


/**
 * @fn loadMainMenu 
 * @brief Load les les fonctiones du main menu (Images,sons, et demarrage)
 */

void loadSoloCircuitMenu(){
    loadSoloCircuitMenuSounds();
    loadSoloCircuitMenuImages();
    printf("Solo Circuit Menu Loaded\n"); //Debug LoadMainMenu
}

/**
 * @fn destroyMainMenu 
 * @brief Destruction de la fenêtre m
 */

void destroySoloMenu();

int onButtonCircuit = false;
int onButtonRetour = false;


/**
 * @fn destroyMainMenu 
 * @param SDL_Event event
 * @brief actualise la fenêtre celon le déplacement de la souris, hover.
 */

void updateSoloCircuitMenuFrame(SDL_Event event){

    int cursorX = event.button.x;
    int cursosY = event.button.y;

    
    SDL_RenderCopy(renderer, bg.texture, NULL, &(bg.position));

    if((cursorX > btnCircuit.position.x) && (cursorX < btnCircuit.position.x + btnCircuit.position.w) && (cursosY > btnCircuit.position.y) && (cursosY < btnCircuit.position.y + btnCircuit.position.h)){
        if (!onButtonCircuit){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonCircuit = 1;
        }

        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnCircuitC.texture, NULL, &(btnCircuitC.position));
        else
            SDL_RenderCopy(renderer, btnCircuitH.texture, NULL, &(btnCircuitH.position));

        if (event.type == SDL_MOUSEBUTTONUP){
                //play sound
                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
            }
    }else{
        SDL_RenderCopy(renderer, btnCircuit.texture, NULL, &(btnCircuit.position));

        if (onButtonCircuit) onButtonCircuit = false;
    }
    
    if((cursorX > btnRetour.position.x) && (cursorX < btnRetour.position.x + btnRetour.position.w) && (cursosY > btnRetour.position.y) && (cursosY < btnRetour.position.y + btnRetour.position.h)){
        if (!onButtonRetour){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonRetour = 1;
        }

        if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
            quitter();
        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnRetourC.texture, NULL, &(btnRetourC.position));
        else
            SDL_RenderCopy(renderer, btnRetourH.texture, NULL, &(btnRetourH.position));
    }else{
        SDL_RenderCopy(renderer, btnRetour.texture, NULL, &(btnRetour.position));

        if (onButtonRetour) onButtonRetour = false;
    }

    printf("Updated Frame with Solo Circuit Menu\n"); //Debug updateMainMenuFrame

}
