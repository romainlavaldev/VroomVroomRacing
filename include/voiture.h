#ifndef VOITURE_H
#define VOITURE_H

#include <commun.h>

#define ROTATION_MAX 20
#define POSITION_MAX_X 3
#define VITESSE_ROTATION 5
#define VITESSE_DEPLACEMENT 0.3
/**
 * \struct Voiture
 * \brief Déclare une vroom
 */

typedef struct
{
    float x, y;
    int textureVoiture;
    float velocite, acceleration;
    float rotation;
    float rotationRoue;
    int state1, state2, state3;

}Voiture;

/**
 * @fn voitureRender 
 * @brief Render d'une voiture
 */

void voitureRender(Voiture voiture);


#endif