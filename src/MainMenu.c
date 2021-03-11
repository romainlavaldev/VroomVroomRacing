
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
#include <MainMenu.h>

int MainMenuIsActive = false;

Mix_Chunk* mainMenuMusic;


/**
 * @fn loadMainMenuSounds 
 * @brief Load les sons du Menu
 */

void loadMainMenuSounds(){
    
    mainMenuMusic = NULL;
    mainMenuMusic = Mix_LoadWAV("sound/music/mainMenu.mp3");

    ButtonHoverSFX = NULL;
    ButtonHoverSFX = Mix_LoadWAV("sound/SFX/buttonHover.mp3");

    ButtonClickedSFX = NULL;
    ButtonClickedSFX = Mix_LoadWAV("sound/SFX/ButtonClicked.mp3");

}

/**
 * @fn startMainMenuSounds 
 * @brief Demarre les sons du Menu
 */

void startMainMenuSounds(){
    if (!MainMenuIsActive){
        Mix_PlayChannel(5, mainMenuMusic, -1);
        Mix_Volume(5, 30);
    }else{

    }
}

/// Définition des boutons de la main window

    image_t MainMenuBG;
    image_t btnSolo;
    image_t btnSoloH;
    image_t btnSoloC;
    image_t btnMulti;
    image_t btnMultiH;
    image_t btnMultiC;
    image_t btnQuitter;
    image_t btnQuitterH;
    image_t btnQuitterC;


/**
 * @fn loadMainMenuImages 
 * @brief Load les images du Menu
 */

void loadMainMenuImages(){
        //Fond
        SDL_Surface* MainMenuBGTmp = SDL_LoadBMP("img/MainMenu/fond.bmp");
        MainMenuBG.texture = SDL_CreateTextureFromSurface(renderer, MainMenuBGTmp);
        SDL_FreeSurface(MainMenuBGTmp);
        MainMenuBG.position.x = 0;
        MainMenuBG.position.y = 0;
        MainMenuBG.position.w = 1920;
        MainMenuBG.position.h = 1080;
        //SDL_RenderCopy(renderer, MainMenuBG.texture, NULL, &(MainMenuBG.position));

        //Boutton Solo
        SDL_Surface* soloButtonTmp = SDL_LoadBMP("img/MainMenu/solo.bmp");
        btnSolo.texture = SDL_CreateTextureFromSurface(renderer, soloButtonTmp);
        SDL_FreeSurface(soloButtonTmp);
        btnSolo.position.x = 586;
        btnSolo.position.y = 319;
        btnSolo.position.w = 1334;
        btnSolo.position.h = 150;

        //Boutton SoloHover
        SDL_Surface* soloHoverButtonTmp = SDL_LoadBMP("img/MainMenu/solo_h.bmp");
        btnSoloH.texture = SDL_CreateTextureFromSurface(renderer, soloHoverButtonTmp);
        SDL_FreeSurface(soloHoverButtonTmp);
        btnSoloH.position.x = 586;
        btnSoloH.position.y = 319;
        btnSoloH.position.w = 1334;
        btnSoloH.position.h = 150;

        //Boutton SoloClick
        SDL_Surface* soloClickButtonTmp = SDL_LoadBMP("img/MainMenu/solo_c.bmp");
        btnSoloC.texture = SDL_CreateTextureFromSurface(renderer, soloClickButtonTmp);
        SDL_FreeSurface(soloClickButtonTmp);
        btnSoloC.position.x = 586;
        btnSoloC.position.y = 319;
        btnSoloC.position.w = 1334;
        btnSoloC.position.h = 150;

        //Boutton Multijoueur
        SDL_Surface* multiButtonTmp = SDL_LoadBMP("img/MainMenu/multi.bmp");
        btnMulti.texture = SDL_CreateTextureFromSurface(renderer, multiButtonTmp);
        SDL_FreeSurface(multiButtonTmp);
        btnMulti.position.x = 586;
        btnMulti.position.y = 504;
        btnMulti.position.w = 1334;
        btnMulti.position.h = 150;

        //Boutton MultijoueurHover
        SDL_Surface* multiHoverButtonTmp = SDL_LoadBMP("img/MainMenu/multi_h.bmp");
        btnMultiH.texture = SDL_CreateTextureFromSurface(renderer, multiHoverButtonTmp);
        SDL_FreeSurface(multiHoverButtonTmp);
        btnMultiH.position.x = 586;
        btnMultiH.position.y = 504;
        btnMultiH.position.w = 1334;
        btnMultiH.position.h = 150;


        //Boutton MultijoueurClick
        SDL_Surface* multiClickButtonTmp = SDL_LoadBMP("img/MainMenu/multi_c.bmp");
        btnMultiC.texture = SDL_CreateTextureFromSurface(renderer, multiClickButtonTmp);
        SDL_FreeSurface(multiClickButtonTmp);
        btnMultiC.position.x = 586;
        btnMultiC.position.y = 504;
        btnMultiC.position.w = 1334;
        btnMultiC.position.h = 150;


        //Boutton Quitter
        SDL_Surface* quitButtonTmp = SDL_LoadBMP("img/MainMenu/quitter.bmp");
        btnQuitter.texture = SDL_CreateTextureFromSurface(renderer, quitButtonTmp);
        SDL_FreeSurface(quitButtonTmp);
        btnQuitter.position.x = 1030;
        btnQuitter.position.y = 901;
        btnQuitter.position.w = 890;
        btnQuitter.position.h = 100;


        //Boutton QuitterHover
        SDL_Surface* quitHoverButtonTmp = SDL_LoadBMP("img/MainMenu/quitter_h.bmp");
        btnQuitterH.texture = SDL_CreateTextureFromSurface(renderer, quitHoverButtonTmp);
        SDL_FreeSurface(quitHoverButtonTmp);
        btnQuitterH.position.x = 1030;
        btnQuitterH.position.y = 901;
        btnQuitterH.position.w = 890;
        btnQuitterH.position.h = 100;

        //Boutton QuitterClick
        SDL_Surface* quitClickButtonTmp = SDL_LoadBMP("img/MainMenu/quitter_c.bmp");
        btnQuitterC.texture = SDL_CreateTextureFromSurface(renderer, quitClickButtonTmp);
        SDL_FreeSurface(quitClickButtonTmp);
        btnQuitterC.position.x = 1030;
        btnQuitterC.position.y = 901;
        btnQuitterC.position.w = 890;
        btnQuitterC.position.h = 100;
}


/**
 * @fn loadMainMenu 
 * @brief Load les les fonctions du main menu (Images,sons, et demarrage)
 */

void loadMainMenu(){
    loadMainMenuSounds();
    loadMainMenuImages();
    startMainMenuSounds();
    printf("Main Menu Loaded\n"); //Debug LoadMainMenu
}

/**
 * @fn destroyMainMenu 
 * @brief Destruction de la fenêtre Menu
 */

void destroyMainMenu();

int onButtonSolo = false;
int onButtonMulti = false;
int onButtonQuit = false;


/**
 * @fn destroyMainMenu 
 * @param SDL_Event event
 * @brief actualise la fenêtre celon le déplacement de la souris, hover.
 */

void updateMainMenuFrame(SDL_Event event){

    int cursorX = event.button.x;
    int cursosY = event.button.y;

    
    SDL_RenderCopy(renderer, MainMenuBG.texture, NULL, &(MainMenuBG.position));

    if((cursorX > btnSolo.position.x) && (cursorX < btnSolo.position.x + btnSolo.position.w) && (cursosY > btnSolo.position.y) && (cursosY < btnSolo.position.y + btnSolo.position.h)){
        if (!onButtonSolo){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonSolo = 1;
        }

        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnSoloC.texture, NULL, &(btnSoloC.position));
        else
            SDL_RenderCopy(renderer, btnSoloH.texture, NULL, &(btnSoloH.position));

        if (event.type == SDL_MOUSEBUTTONUP){
                //play sound
                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
                ActiveMenu = 2; // Passage Menu SoloCircuit
            }
    }else{
        SDL_RenderCopy(renderer, btnSolo.texture, NULL, &(btnSolo.position));

        if (onButtonSolo) onButtonSolo = false;
    }

    if((cursorX > btnMulti.position.x) && (cursorX < btnMulti.position.x + btnMulti.position.w) && (cursosY > btnMulti.position.y) && (cursosY < btnMulti.position.y + btnMulti.position.h)){
        if (!onButtonMulti){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonMulti = 1;
        }

        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnMultiC.texture, NULL, &(btnMultiC.position));
        else
            SDL_RenderCopy(renderer, btnMultiH.texture, NULL, &(btnMultiH.position));

        if (event.type == SDL_MOUSEBUTTONUP){
                //play sound
                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
            }
    }else{
        SDL_RenderCopy(renderer, btnMulti.texture, NULL, &(btnMulti.position));
        
        if (onButtonMulti) onButtonMulti = false;
    }

    
    if((cursorX > btnQuitter.position.x) && (cursorX < btnQuitter.position.x + btnQuitter.position.w) && (cursosY > btnQuitter.position.y) && (cursosY < btnQuitter.position.y + btnQuitter.position.h)){
        if (!onButtonQuit){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonQuit = 1;
        }

        if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
            quitter();
        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnQuitterC.texture, NULL, &(btnQuitterC.position));
        else
            SDL_RenderCopy(renderer, btnQuitterH.texture, NULL, &(btnQuitterH.position));
    }else{
        SDL_RenderCopy(renderer, btnQuitter.texture, NULL, &(btnQuitter.position));

        if (onButtonQuit) onButtonQuit = false;
    }

    printf("Updated Frame with Main Menu\n"); //Debug updateMainMenuFrame

}
