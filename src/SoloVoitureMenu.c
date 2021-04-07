
/*************************************************************
 *              Fenêtre d'ouverture 
 * 
 * 
 * @file SoloVoitureMenu.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 11 Mars 2021
 * @brief Menu des voitures
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
#include <SoloVoitureMenu.h>


#include<windows.h>


/**
 * @fn loadSoloVoitureMenuSounds 
 * @brief Load les sons du Menu Voiture
 */

void loadSoloVoitureMenuSounds(){

    ButtonHoverSFX = NULL;
    ButtonHoverSFX = Mix_LoadWAV("sound/SFX/buttonHover.mp3");

    ButtonClickedSFX = NULL;
    ButtonClickedSFX = Mix_LoadWAV("sound/SFX/ButtonClicked.mp3");

    ButtonBackSFX = NULL;
    ButtonBackSFX = Mix_LoadWAV("sound/SFX/ButtonBack.mp3");
}

/// Définition des boutons de la main window

    image_t SoloVoitureBG;
    image_t btnVoiture;
    image_t btnVoitureH;
    image_t btnVoitureC;
    image_t btnVoitureRetour;
    image_t btnVoitureRetourH;
    image_t btnVoitureRetourC;


/**
 * @fn loadSoloVoitureMenuImages 
 * @brief Load les images du Menu Voiture
 */

void loadSoloVoitureMenuImages(){
        //Fond
        SDL_Surface* SoloVoitureBGTmp = SDL_LoadBMP("img/SoloVoitureMenu/fond.bmp");
        SoloVoitureBG.texture = SDL_CreateTextureFromSurface(renderer, SoloVoitureBGTmp);
        SDL_FreeSurface(SoloVoitureBGTmp);
        SoloVoitureBG.position.x = 0;
        SoloVoitureBG.position.y = 0;
        SoloVoitureBG.position.w = 1920;
        SoloVoitureBG.position.h = 1080;
        //SDL_RenderCopy(renderer, SoloVoitureBG.texture, NULL, &(SoloVoitureBG.position));

        //Boutton Voiture
        SDL_Surface* VoitureButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/vroom_1.bmp");
        btnVoiture.texture = SDL_CreateTextureFromSurface(renderer, VoitureButtonTmp);
        SDL_FreeSurface(VoitureButtonTmp);
        btnVoiture.position.x = 270;
        btnVoiture.position.y = 470;
        btnVoiture.position.w = 1650;
        btnVoiture.position.h = 440;

        //Boutton VoitureHover
        SDL_Surface* VoitureHoverButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/Hover/vroom_1_h.bmp");
        btnVoitureH.texture = SDL_CreateTextureFromSurface(renderer, VoitureHoverButtonTmp);
        SDL_FreeSurface(VoitureHoverButtonTmp);
        btnVoitureH.position.x = 270;
        btnVoitureH.position.y = 470;
        btnVoitureH.position.w = 1650;
        btnVoitureH.position.h = 440;

        //Boutton VoitureClick
        SDL_Surface* VoitureClickButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/Click/vroom_1_c.bmp");
        btnVoitureC.texture = SDL_CreateTextureFromSurface(renderer, VoitureClickButtonTmp);
        SDL_FreeSurface(VoitureClickButtonTmp);
        btnVoitureC.position.x = 270;
        btnVoitureC.position.y = 470;
        btnVoitureC.position.w = 1650;
        btnVoitureC.position.h = 440;


        //Boutton VoitureRetour
        SDL_Surface* VoitureRetourButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/retour.bmp");
        btnVoitureRetour.texture = SDL_CreateTextureFromSurface(renderer, VoitureRetourButtonTmp);
        SDL_FreeSurface(VoitureRetourButtonTmp);
        btnVoitureRetour.position.x = 0;
        btnVoitureRetour.position.y = 327;
        btnVoitureRetour.position.w = 340;
        btnVoitureRetour.position.h = 89;


        //Boutton VoitureRetourHover
        SDL_Surface* VoitureRetourHoverButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/Hover/retour_h.bmp");
        btnVoitureRetourH.texture = SDL_CreateTextureFromSurface(renderer, VoitureRetourHoverButtonTmp);
        SDL_FreeSurface(VoitureRetourHoverButtonTmp);
        btnVoitureRetourH.position.x = 0;
        btnVoitureRetourH.position.y = 327;
        btnVoitureRetourH.position.w = 340;
        btnVoitureRetourH.position.h = 89;

        //Boutton VoitureRetourClick
        SDL_Surface* VoitureRetourClickButtonTmp = SDL_LoadBMP("img/SoloVoitureMenu/Click/retour_c.bmp");
        btnVoitureRetourC.texture = SDL_CreateTextureFromSurface(renderer, VoitureRetourClickButtonTmp);
        SDL_FreeSurface(VoitureRetourClickButtonTmp);
        btnVoitureRetourC.position.x = 0;
        btnVoitureRetourC.position.y = 327;
        btnVoitureRetourC.position.w = 340;
        btnVoitureRetourC.position.h = 89;
}


/**
 * @fn loadSoloVoitureMenu 
 * @brief Load les les fonctiones du main menu (Images,sons, et demarrage)
 */

void loadSoloVoitureMenu(){
    loadSoloVoitureMenuSounds();
    loadSoloVoitureMenuImages();
    printf("Solo Voiture Menu Loaded\n"); //Debug LoadVoitureMenu
}

/**
 * @fn destroyVoitureMenu 
 * @brief Destruction de la fenêtre 
 */

void destroyVoitureMenu();

int onButtonVoiture = false;
int onButtonVoitureRetour = false;


/**
 * @fn updateSoloVoitureMenuFrame 
 * @param SDL_Event event
 * @brief actualise la fenêtre celon le déplacement de la souris, hover.
 */

void updateSoloVoitureMenuFrame(SDL_Event event){

    int cursorX = event.button.x;
    int cursosY = event.button.y;

    
    SDL_RenderCopy(renderer, SoloVoitureBG.texture, NULL, &(SoloVoitureBG.position));

    if((cursorX > btnVoiture.position.x) && (cursorX < btnVoiture.position.x + btnVoiture.position.w) && (cursosY > btnVoiture.position.y) && (cursosY < btnVoiture.position.y + btnVoiture.position.h)){
        if (!onButtonVoiture){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonVoiture = 1;
        }

        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnVoitureC.texture, NULL, &(btnVoitureC.position));
        else
            SDL_RenderCopy(renderer, btnVoitureH.texture, NULL, &(btnVoitureH.position));

        if (event.type == SDL_MOUSEBUTTONUP){
                //play sound
                Mix_PlayChannel(-1, ButtonClickedSFX, 0);
                ShellExecute(NULL, "open", "C:\\Users\\Romain\\Documents\\VroomVroomRacing\\VVR2.0\\bin\\jeu.exe", "1", NULL, SW_SHOWNORMAL);
                quitter();
            }
    }else{
        SDL_RenderCopy(renderer, btnVoiture.texture, NULL, &(btnVoiture.position));

        if (onButtonVoiture) onButtonVoiture = false;
    }
    
    if((cursorX > btnVoitureRetour.position.x) && (cursorX < btnVoitureRetour.position.x + btnVoitureRetour.position.w) && (cursosY > btnVoitureRetour.position.y) && (cursosY < btnVoitureRetour.position.y + btnVoitureRetour.position.h)){
        if (!onButtonVoitureRetour){
            //play sound
            Mix_PlayChannel(-1, ButtonHoverSFX, 0);
            onButtonVoitureRetour = 1;
        }

        if(event.type == SDL_MOUSEBUTTONUP){
            //play sound
            Mix_PlayChannel(-1, ButtonBackSFX, 0);
            ActiveMenu = 2;
        }
            
        if(leftMouseDown)
            SDL_RenderCopy(renderer, btnVoitureRetourC.texture, NULL, &(btnVoitureRetourC.position));
        else
            SDL_RenderCopy(renderer, btnVoitureRetourH.texture, NULL, &(btnVoitureRetourH.position));
    }else{
        SDL_RenderCopy(renderer, btnVoitureRetour.texture, NULL, &(btnVoitureRetour.position));

        if (onButtonVoitureRetour) onButtonVoitureRetour = false;
    }

    printf("Updated Frame with Solo Voiture Menu\n"); //Debug updateSoloVoitureMenuFrame

}
