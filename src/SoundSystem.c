/*************************************************************
 *              Creation du Systeme de son 
 * 
 * 
 * @file SoundSystem.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 12 Mars 2021
 * @brief Creation du systeme de sonorites du jeu
 * @version 1.0
 * 
 * ********************************************************* */


#if defined(WIN32)
  #include <conio.h>
#else
  #include "../common/conio.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <SoundSystem.h>
#include <irrKlang.h>
using namespace irrklang;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll



//Preparation Fonction musique



/**
 * @fn initMusicEngine 
 * @brief Initialise l'engine de son
 */

void initMusicEngine(){
    ISoundEngine* engine = createIrrKlangDevice();
}

/**
 * @fn isMusicInit 
 * @brief Initialise l'engine de son
 * @param ISoundEngine* engine
 * @return 1/0
 */
int isMusicInit(ISoundEngine* engine){
    if (!engine) return 1; // error starting up the engine
    else return 0;
}

/**
 * @fn playBackMusic 
 * @brief Joue la musique de fond
 * @param ISoundEngine* engine
 */

void playBackMusic(ISoundEngine* engine){
        // play some sound stream, not looped
    ISound* music = engine->play2D("../bin/sound/SFX/Background_Music.mp3", true); //true or false après la musique symbolise la loop
}


// fonctions pour tout les sons
/*
Loop avancer
lacher avancer
reprise avancer
recul
loop recul
lacher recul
Freiner
*/

// AVANCER


/**
 * @fn playDemarrageAvancer 
 * @brief SFX Démarrage Avancer
 */
void playDemarrageAvancer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Forwards_Debut.mp3", false); 
}

/**
 * @fn playLoopAvancer 
 * @brief SFX Loop Avancer
 */
void playLoopAvancer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Forwards_Boucle.mp3", true); //true or false après la musique symbolise la loop
}

/**
 * @fn playLacherAvancer 
 * @brief SFX Lacher bouton Avancer
 */
void playLacherAvancer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Forwards_Fin.mp3", false); 
}

/**
 * @fn playRepriseAvancer 
 * @brief SFX reprise après lacher bouton avancer
 */
void playRepriseAvancer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Forwards_Reprise.mp3", false); 
}


// RECULER 


/**
 * @fn playReculer 
 * @brief SFX Reculer
 */
void playReculer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Backwards_Debut.mp3", false); 
}
/**
 * @fn playLoopReculer 
 * @brief SFX loop recul
 */
void playLoopReculer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Backwards_Boucle.mp3", true); 
}
/**
 * @fn playLacherReculer 
 * @brief SFX reprise après lacher bouton reculer
 */
void playLacherReculer(){
    ISound* music = engine->play2D("../bin/sound/SFX/Backwards_Fin.mp3", false); 
}


// FREINER 

/**
 * @fn playFreiner 
 * @brief SFX Frein
 */
void playFreiner(){
    ISound* music = engine->play2D("../bin/sound/SFX/Frein.mp3", false); 
}

/**
 * @fn DropMusicEngine 
 * @brief Drop l'engine de musique OpenGL
 */
void DropMusicEngine(ISoundEngine* engine){
    engine->drop();
}



int main(int argc, const char** argv)
{
    // start the sound engine with default parameters
    ISoundEngine* engine = createIrrKlangDevice();

    if (!engine)
        return 0; // error starting up the engine
 

    // play some sound stream, not looped
    ISound* music = engine->play2D("../bin/sound/SFX/Forwards_Debut.mp3", false);


    while(true) // endless loop until user exits
    {
        int key = getch(); //getch est le input key
    
        if (key == 27)
            break; // user pressed ESCAPE key
        else{
            ISoundEffectControl* fx = 0;
            if (music)
                fx = music->getSoundEffectControl();

            if (!fx){
                // some sound devices do not support sound effects.
                printf("This device or sound does not support sound effects.\n");
                continue;
            }
            switch(tolower(key)){

                case 'z':
                    if (fx->isDistortionSoundEffectEnabled()) //check if avancer actif
                        fx->disableDistortionSoundEffect();
                    else
                        fx->enableDistortionSoundEffect(); // active le son avancer
                    break;


// Son spécifique gauche/droite
                case 'q':
                    if (fx->isEchoSoundEffectEnabled()) //check if gauche actif
                        fx->disableEchoSoundEffect();
                    else
                        fx->enableEchoSoundEffect(); // active le son gauche
                    break;

                case 'd':
                    if (fx->isWavesReverbSoundEffectEnabled()) //check if droite actif
                        fx->disableWavesReverbSoundEffect();
                    else
                        fx->enableWavesReverbSoundEffect(); // active le droite gauche
                    break;

// recul
                case 's':
                    if (fx->isWavesReverbSoundEffectEnabled()) //check if reculer actif
                        fx->disableWavesReverbSoundEffect();
                    else
                        fx->enableWavesReverbSoundEffect(); // active le reculer gauche
                    break;

            }
        }
    }


    engine->drop(); // delete engine
    return 0;
}