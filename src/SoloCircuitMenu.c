
/*************************************************************
 *              Fenêtre d'ouverture 
 * 
 * 
 * @file SoloCircuitMenu.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @brief Menu Circuit de jeu
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
 * @fn loadSoloCircuitMenuSounds 
 * @brief Load les sons du Menu
 */

void loadSoloCircuitMenuSounds(){

    ButtonHoverSFX = NULL;
    ButtonHoverSFX = Mix_LoadWAV("sound/SFX/buttonHover.mp3");

    ButtonClickedSFX = NULL;
    ButtonClickedSFX = Mix_LoadWAV("sound/SFX/ButtonClicked.mp3");

    ButtonBackSFX = NULL;
    ButtonBackSFX = Mix_LoadWAV("sound/SFX/ButtonBack.mp3");

}

/// Définition des boutons de la main window

    image_t SoloCircuitBG;
    image_t btnCircuit;
    image_t btnCircuitH;
    image_t btnCircuitC;
    image_t btnCircuitRetour;
    image_t btnCircuitRetourH;
    image_t btnCircuitRetourC;


/**
 * @fn loadSoloCircuitMenuImages 
 * @brief Load les images du Menu
 */

void loadSoloCircuitMenuImages(){
        //Fond
        SDL_Surface* SoloCircuitBGTmp = SDL_LoadBMP("img/SoloCircuitMenu/fond.bmp");
        SoloCircuitBG.texture = SDL_CreateTextureFromSurface(renderer, SoloCircuitBGTmp);
        SDL_FreeSurface(SoloCircuitBGTmp);
        SoloCircuitBG.position.x = 0;
        SoloCircuitBG.position.y = 0;
        SoloCircuitBG.position.w = 1920;
        SoloCircuitBG.position.h = 1080;
        //SDL_RenderCopy(renderer, SoloCircuitBG.texture, NULL, &(SoloCircuitBG.position));

        //Boutton Circuit
        SDL_Surface* CircuitButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/circuit_1.bmp");
        btnCircuit.texture = SDL_CreateTextureFromSurface(renderer, CircuitButtonTmp);
        SDL_FreeSurface(CircuitButtonTmp);
        btnCircuit.position.x = 270;
        btnCircuit.position.y = 470;
        btnCircuit.position.w = 1650;
        btnCircuit.position.h = 440;

        //Boutton CircuitHover
        SDL_Surface* CircuitHoverButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/circuit_1_h.bmp");
        btnCircuitH.texture = SDL_CreateTextureFromSurface(renderer, CircuitHoverButtonTmp);
        SDL_FreeSurface(CircuitHoverButtonTmp);
        btnCircuitH.position.x = 270;
        btnCircuitH.position.y = 470;
        btnCircuitH.position.w = 1650;
        btnCircuitH.position.h = 440;

        //Boutton CircuitClick
        SDL_Surface* CircuitClickButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Click/circuit_1_c.bmp");
        btnCircuitC.texture = SDL_CreateTextureFromSurface(renderer, CircuitClickButtonTmp);
        SDL_FreeSurface(CircuitClickButtonTmp);
        btnCircuitC.position.x = 270;
        btnCircuitC.position.y = 470;
        btnCircuitC.position.w = 1650;
        btnCircuitC.position.h = 440;


        //Boutton CircuitRetour
        SDL_Surface* CircuitRetourButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/retour.bmp");
        btnCircuitRetour.texture = SDL_CreateTextureFromSurface(renderer, CircuitRetourButtonTmp);
        SDL_FreeSurface(CircuitRetourButtonTmp);
        btnCircuitRetour.position.x = 0;
        btnCircuitRetour.position.y = 327;
        btnCircuitRetour.position.w = 340;
        btnCircuitRetour.position.h = 89;


        //Boutton CircuitRetourHover
        SDL_Surface* CircuitRetourHoverButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Hover/retour_h.bmp");
        btnCircuitRetourH.texture = SDL_CreateTextureFromSurface(renderer, CircuitRetourHoverButtonTmp);
        SDL_FreeSurface(CircuitRetourHoverButtonTmp);
        btnCircuitRetourH.position.x = 0;
        btnCircuitRetourH.position.y = 327;
        btnCircuitRetourH.position.w = 340;
        btnCircuitRetourH.position.h = 89;

        //Boutton CircuitRetourClick
        SDL_Surface* CircuitRetourClickButtonTmp = SDL_LoadBMP("img/SoloCircuitMenu/Click/retour_c.bmp");
        btnCircuitRetourC.texture = SDL_CreateTextureFromSurface(renderer, CircuitRetourClickButtonTmp);
        SDL_FreeSurface(CircuitRetourClickButtonTmp);
        btnCircuitRetourC.position.x = 0;
        btnCircuitRetourC.position.y = 327;
        btnCircuitRetourC.position.w = 340;
        btnCircuitRetourC.position.h = 89;
}


/**
 * @fn loadSoloCircuitMenu 
 * @brief Load les les fonctiones du main menu (Images,sons, et demarrage)
 */

void loadSoloCircuitMenu(){
    loadSoloCircuitMenuSounds();
    loadSoloCircuitMenuImages();
    printf("Solo Circuit Menu Loaded\n"); //Debug LoadMainMenu
}

/**
 * @fn destroySoloMenu 
 * @brief Destruction de la fenêtre m
 */

void destroySoloMenu();

int onButtonCircuit = false;
int onButtonCircuitRetour = false;


/**
 * @fn updateSoloCircuitMenuFrame
 * @param SDL_Event event
 * @brief actualise la fenêtre celon le déplacement de la souris, hover.
 */

void updateSoloCircuitMenuFrame(SDL_Event event){

    int cursorX = event.button.x;
    int cursosY = event.button.y;

    
    SDL_RenderCopy(renderer, SoloCircuitBG.texture, NULL, &(SoloCircuitBG.position));

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
                ActiveMenu = 3;
            }
    }else{
        SDL_RenderCopy(renderer, btnCircuit.texture, NULL, &(btnCircuit.position));

        if (onButtonCircuit) onButtonCircuit = false;
    }
    
    if((cursorX > btnCircuitRetour.position.x) && (cursorX < btnCircuitRetour.position.x + btnCircuitRetour.position.w) && (cursosY > btnCircuitRetour.position.y) && (cursosY < btnCircuitRetour.position.y + btnCircuitRetour.position.h)){
        if (!onButtonCircuitRetour){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonCircuitRetour = 1;
        }

        if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT){
            //play sound
            Mix_PlayChannel(-1, ButtonBackSFX, 0);
            ActiveMenu = 1; //Retour Menu 
        }
           
        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnCircuitRetourC.texture, NULL, &(btnCircuitRetourC.position));
        else
            SDL_RenderCopy(renderer, btnCircuitRetourH.texture, NULL, &(btnCircuitRetourH.position));
    }else{
        SDL_RenderCopy(renderer, btnCircuitRetour.texture, NULL, &(btnCircuitRetour.position));

        if (onButtonCircuitRetour) onButtonCircuitRetour = false;
    }

    printf("Updated Frame with Solo Circuit Menu\n"); //Debug updateMainMenuFrame

}
