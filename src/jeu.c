/*************************************************************
 *              JEU (Enfin!) 
 * 
 * 
 * @file jeu.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 22 Mars 2021
 * @brief Fichier du jeu ! le jeu ouiou !
 * @version 2.0
 * 
 * ********************************************************* */

#include <jeu.h>


int droiteGaucheKey = 0;
int avantArriereKey = 0;

int currentObj = 0;
float position;
int gameOver = 0;
static float vitesseAffiche = 0;
/**
 * @fn enterGame 
 * @brief Entrée dans le jeu, load des fonctionnalités de touche
 */


void enterGame(){

    //initialisation son

    gameOver = 0;
    GamePlaying = 2; //Jeu en cours

    //Linkage des fonctions de gestion du clavier
    glutSpecialFunc(jeuSpecialKey);
    glutSpecialUpFunc(jeuSpecialKeyUp);
    glutKeyboardFunc(jeuAsciiKey);

    glutMotionFunc(jeuMouseMove);
    glutMouseWheelFunc(jeuMouseWheel);

    //Linkage de la fonction de rendu
    glutDisplayFunc(jeuRender);


    boucleRoute = 1.0;

    //position caméra
    aziy = 0;
    elex = 21;
    camDist = 20;
    changeCamera(0,0);


    //Init de la voiture du joueur
    if(niveau == 1)
        voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    if(niveau == 2){
        printf("----------------------------- Load Niveau 2 ---------------------------\n");
        loadResourcesNiv2();
        voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    }
    if(niveau==3){
        printf("--------------------------- Load Niveau 3 -------------------------\n");
        loadResourcesNiv3();
        //voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    }

    voitureJoueur.velocite = 0;
    voitureJoueur.acceleration = 0;
    voitureJoueur.x = 0;
    voitureJoueur.y = 0;
    voitureJoueur.rotation = 0;
    voitureJoueur.rotationRoue = 0;
printf("velo : %.4f\naccel : %.4f\nX: %i,Y:%i\n",voitureJoueur.velocite,voitureJoueur.acceleration,voitureJoueur.x,voitureJoueur.y);

    if(niveau == 1){
        initNiveau1();
        nbObjetsNiveauAct = &nbObjetsNiveau1;
        objetsNiveauAct = &objetsNiveau1;
    }
    if(niveau == 2){  
        initNiveau2();
        nbObjetsNiveauAct = &nbObjetsNiveau2;
        objetsNiveauAct = &objetsNiveau2;
    }
    if(niveau==3){
        initNiveau3();
        nbObjetsNiveauAct = &nbObjetsNiveau3;
        objetsNiveauAct = &objetsNiveau3;
    }

    gameLoop();
}

/**
 * @fn restart 
 * @brief redemarre le jeu 
 */

void restart(){
    gameOver = 0;
    GamePlaying = 2; //Jeu en cours

    //position caméra
    aziy = 0;
    elex = 21;
    camDist = 20;
    changeCamera(0,0);

    voitureJoueur.x = 0;
    voitureJoueur.y = 0;
    voitureJoueur.rotation = 0;
    voitureJoueur.rotationRoue = 0;

    if(niveau == 1){
        initNiveau1();
        nbObjetsNiveauAct = &nbObjetsNiveau1;
        objetsNiveauAct = &objetsNiveau1;
    }
    if(niveau == 2){  
        initNiveau2();
        nbObjetsNiveauAct = &nbObjetsNiveau2;
        objetsNiveauAct = &objetsNiveau2;
    }
    if(niveau==3){
        initNiveau3();
        nbObjetsNiveauAct = &nbObjetsNiveau3;
        objetsNiveauAct = &objetsNiveau3;
    }
}

void reloadLevel(){
    //Init de la voiture du joueur
    if(niveau == 1)
        voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    if(niveau == 2){
        printf("----------------------------- Load Niveau 2 ---------------------------\n");
        loadResourcesNiv2();
        voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    }
    if(niveau==3){
        printf("--------------------------- Load Niveau 3 -------------------------\n");
        loadResourcesNiv3();
        //voitureJoueur.textureVoiture = TEXTURE_VOITURE1;
    }


    restart();
}

/**
 * @fn gameLoop 
 * @brief Effectue la boucle de jeu
 */

void gameLoop(){
    if(GamePlaying == 2){
        updateJeu();
        glutPostRedisplay();
        glutTimerFunc(NF, gameLoop, 0);
    }
    else if (GamePlaying == 1){
        
        glutPostRedisplay();
        glutTimerFunc(NF, gameLoop, 0);
    }
}

/**
 * @fn updateJeu 
 * @brief Effectue l'update du jeu, vérifie des conditions d'impact
 */


void updateJeu(){
    temps_last_update = NF;
    temps_total += temps_last_update;

    printf("\n*** Update voiture joueur ***\n");
    updateVoitureJoueur();
    printf("\n*** Fin ***\n");
    printf("*** Update Objets ***\n");
    updateObjets();
    printf("*** Fin ***\n");

    //Gestion Collisions

    int i;
    for(i = 0; i < *nbObjetsNiveauAct; i++){


        if(objetsNiveauAct[i].type != TYPE_FINISH){
            if(objetsNiveauAct[i].texture == TEXTURE_POUBELLE){
                if(fabs(objetsNiveauAct[i].x - voitureJoueur.x) < 1.5)
                    if(fabs(objetsNiveauAct[i].y - voitureJoueur.y) < 3){
                        //PAAAF (le chien) Et là c'est le drâme, la collision fut évidente pour le joueur français. La voiture à touché l'obstacle, et ainsi de suite, c'est la chute. Aïe Aîe Aîe... Ça doit faire mal
                        GamePlaying = 1;
                        gameOver = 1;
                        voitureJoueur.velocite = 0;
                        voitureJoueur.acceleration = 0;
                        break; 
                    }
            }else if(objetsNiveauAct[i].texture == TEXTURE_STAR){
                if(fabs(objetsNiveauAct[i].x - voitureJoueur.x) < 2)
                    if(fabs(objetsNiveauAct[i].y - voitureJoueur.y) < 3){
                        //PAAAF (le chien) Et là c'est le drâme, la collision fut évidente pour le joueur français. La voiture à touché l'obstacle, et ainsi de suite, c'est la chute. Aïe Aîe Aîe... Ça doit faire mal
                        GamePlaying = 1;
                        gameOver = 1;
                        voitureJoueur.velocite = 0;
                        voitureJoueur.acceleration = 0;
                        break; 
                    }
            }
        }
        else if (objetsNiveauAct[i].type == TYPE_FINISH){
            if(objetsNiveauAct[i].y < voitureJoueur.y){
                gameOver = -1;
                break;
            }
        }
        
    }
}


/**
 * @fn compteurRender 
 * @brief Rendu du compteur OpenGL
 */


void compteurRender(){
    


    if(vitesseAffiche == 0)
        vitesseAffiche = voitureJoueur.velocite;
    if(vitesseAffiche > voitureJoueur.velocite)
        vitesseAffiche -= 0.05 * voitureJoueur.velocite;
    else if(vitesseAffiche < voitureJoueur.velocite)
        vitesseAffiche += 0.05 * voitureJoueur.velocite;
    printf("Vitesse : %.3f\n", vitesseAffiche);
    //Rendu compteur
    glPushMatrix();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
    glTranslatef(-4.0,-3.0,0.0);
    glScalef(0.3,0.3,0.3);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_COMPTEUR]);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex3f(-5.0,-5.0,0);
    glTexCoord2d(0.0,1.0);
    glVertex3f(-5.0,5.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex3f(5.0,5.0,0.0);
    glTexCoord2d(1.0,0.0);
    glVertex3f(5.0,-5.0,0.0);
    //glTranslatef(0.0,0.0,a);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //Rendu aiguille
    glPushMatrix();
    glTranslatef(-4.0,-3.0,0.0);
    float deg=-vitesseAffiche*40+135;
    /*if(fabs(deg) > 360)
        deg=0;*/
    glRotatef(deg,0,0,1.0);
    glScalef(0.3,0.3,0.3);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_PTR]);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex3f(-5.0,-5.0,0);
    glTexCoord2d(0.0,1.0);
    glVertex3f(-5.0,5.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex3f(5.0,5.0,0.0);
    glTexCoord2d(1.0,0.0);
    glVertex3f(5.0,-5.0,0.0);
    //glTranslatef(0.0,0.0,a);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
}

/**
 * @fn gameOverRender 
 * @brief Rendu du game over OpenGL
 */


void gameOverRender(){

    static float pqr=1.0;
    if(pqr>=0.2){
        pqr-=0.1;

    }

    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_GAMEOVER]);

        glScalef(pqr,pqr,1.0);

        glBegin(GL_QUADS);
            glTexCoord2d(0.0,0.0);glVertex3f(-20.0,-5.0,3.0);
            glTexCoord2d(0.0,1.0);glVertex3f(-20.0,5.0,3.0);
            glTexCoord2d(1.0,1.0);glVertex3f(20.0,5.0,3.0);
            glTexCoord2d(1.0,0.0);glVertex3f(20.0,-5.0,3.0);


        glEnd();


        glDisable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);

    glPopMatrix();

}

/**
 * @fn victoireRender 
 * @brief Rendu du victoire OpenGL
 */

void victoireRender(){

    static float pqr=1.0;
    if(pqr>=0.2){
        pqr-=0.1;

    }

    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_FINISH]);

        glScalef(pqr,pqr,1.0);

        glBegin(GL_QUADS);
            glTexCoord2d(0.0,0.0);glVertex3f(-20.0,-5.0,3.0);
            glTexCoord2d(0.0,1.0);glVertex3f(-20.0,5.0,3.0);
            glTexCoord2d(1.0,1.0);glVertex3f(20.0,5.0,3.0);
            glTexCoord2d(1.0,0.0);glVertex3f(20.0,-5.0,3.0);


        glEnd();


        glDisable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);

    glPopMatrix();

}
/*
void EnterEvents(){
    if(gameOver==1){
        enterGame();
    }
}
*/


/**
 * @fn jeuSpecialKey 
 */
 
void jeuSpecialKey(int key, int x, int y){
    switch (key)
    {
    case GLUT_KEY_UP:
        //voitureJoueur.velocite += 1.5;
        avantArriereKey = 1;
        break;
    case GLUT_KEY_DOWN:
        //voitureJoueur.velocite -= 0.5;
        avantArriereKey = -1;
        break;
    case GLUT_KEY_LEFT:
        droiteGaucheKey = -1;
        break;
    case GLUT_KEY_RIGHT:
        droiteGaucheKey = 1;
        break;
    }
}

/**
 * @fn jeuSpecialKeyUp 
 */

void jeuSpecialKeyUp(int key, int x, int y){
    switch (key)
    {
    case GLUT_KEY_UP:
        //voitureJoueur.velocite -= 1.5;
        voitureJoueur.acceleration = 0;
        avantArriereKey = 0;
        break;
    case GLUT_KEY_DOWN:
        //voitureJoueur.velocite += 0.5;
        voitureJoueur.acceleration = 0;
        avantArriereKey = 0;   
        break;
    case GLUT_KEY_LEFT:
        droiteGaucheKey = 0;
        break;
    case GLUT_KEY_RIGHT:
        droiteGaucheKey = 0;
        break;
    }
}


/**
 * @fn jeuAsciiKey 
 * @brief Recupere les touches pour fin de jeu et pause
 */

void jeuAsciiKey(int key, int x, int y){
    if (gameOver==1){
        if (key == 13){ //Quitter le jeu
            //quitterjeu();
            restart();
        }
        return;
    }else if(gameOver==-1){
        if (key == 13){ //Quitter le jeu
            //quitterjeu();
            niveau++;
            reloadLevel();
        }
        return;
    }

    switch (key)
    {
    case 'p': //pause
    
        break;
    default:
        break;
    }
}

/**
 * @fn JeuMouseMove 
 * @brief Bouger la souris change la perspective
 */

void jeuMouseMove(int x, int y){
    changeCamera(x,y);
}


void jeuMouseWheel(int button, int dir, int x, int y){

    if(dir > 0){
        camDist--;
        changeCamera(0,0);
    }
    else{
        camDist++;
        changeCamera(0,0);
    }
}


/**
 * @fn jeuRender 
 * @brief charge les textures du jeu
 */

void jeuRender(){
    glLoadIdentity();
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glPushMatrix();

    glTranslated(0.0, 0.0, -camDist);//dist
    glRotated(elex, 1.0, 0.0, 0.0);//elivation angle from x axis yz plane
    glRotated(aziy, 0.0, 1.0, 0.0);//azimuth angle from y axis xy plane

    glMatrixMode(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glColor3f(1,1,1);

    //Rendu Ciel
    GLUquadricObj *qObj = gluNewQuadric();
    gluQuadricNormals(qObj, GLU_SMOOTH);
    gluQuadricTexture(qObj, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_CIEL]);
    glPushMatrix();
    glRotatef(180.0,1.0,0,0);
    gluSphere(qObj, 80.0f, 24, 24);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //Fin rendu ciel
    
    //Rendu route
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    glTranslatef(0, boucleRoute, 0);
    glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_ROUTE]);

    glBegin(GL_QUADS);
    
    glColor3f(1,1,1);

    glTexCoord2f(0.0, 0.0);
    glVertex3d(4,0,-200);

    glTexCoord2f(1.0, 0.0);
    glVertex3d(-4,0,-200);

    glTexCoord2f(1.0, 4.0);
    glVertex3d(-4,0,200);

    glTexCoord2f(0.0, 4.0);
    glVertex3d(4,0,200);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    if(niveau != 3){
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, TexArray[TEXTURE_SAND]);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0);
        glVertex3f(-100.0,-0.3,-1000.0);
        glTexCoord2d(0.0,50.0);
        glVertex3f(-100.0,-0.3,1000.0);
        glTexCoord2d(10.0,50.0);
        glVertex3f(100.0,-0.3,1000.0);
        glTexCoord2d(10.0,0.0);
        glVertex3f(100.0,-0.3,-1000.0);
        //glTranslatef(0.0,0.0,a);

        glEnd();
        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }
    glPopMatrix();
    //Fin rendu route
    

    glMatrixMode(GL_MODELVIEW);
    printf("\n*** Rendu de la voiture du joueur ***\n");
    voitureRender(voitureJoueur);
    printf("*** Fin ***\n");

    printf("\n*** Rendu des objets ***\n");
    for(i = 0; i < *nbObjetsNiveauAct; i++){
        if(objetsNiveauAct[i].y <= 100 && objetsNiveauAct[i].y >= -50)
            objetRender(objetsNiveauAct[i]);
    }

    printf("\n*** Fin ***\n");

    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 0.0, -9.0);//dist
    glRotated(21.0, 1.0, 0.0, 0.0);//elivation angle from x axis yz plane
    glRotated(0, 0.0, 1.0, 0.0);


    compteurRender();

    if (gameOver == 1)
        gameOverRender();
    else if(gameOver == -1)
        victoireRender();

    glPopMatrix();

    glutSwapBuffers();

}
// // UpdateVoiture

/**
 * @fn updateVoitureJoueur
 * @brief Modifie la voiture sur le terrain 3D
 * 
 */
void updateVoitureJoueur(){
printf("TEmps last update : %i---------------------------------------------------------------------------------\n",temps_last_update);
    printf("Velocité : %.4f, accel : %.4f ", voitureJoueur.velocite, voitureJoueur.acceleration);

    if(avantArriereKey == 1){
        if(voitureJoueur.velocite < 1.1){
            voitureJoueur.acceleration = 1;
            /*switch(niveau){
                case 1:
                    voitureJoueur.acceleration = 1;
                    break;
                case 2:
                    voitureJoueur.acceleration = 0.5;
                    break;
                default:
                    voitureJoueur.acceleration = 0.5;
            }
            */
        }else
            voitureJoueur.acceleration = 2 / (log10f(voitureJoueur.velocite)*16);
    }
    else if (avantArriereKey == -1)
    {
        voitureJoueur.acceleration = -1.5;
    }
    else if (avantArriereKey == 0 && voitureJoueur.velocite > 1.1)
    {
        voitureJoueur.acceleration = -(voitureJoueur.velocite/3);
    }
    else
        voitureJoueur.acceleration = -.5;



    if(voitureJoueur.velocite + voitureJoueur.acceleration * temps_last_update / 1000 < 0)
        voitureJoueur.velocite = 0;
    else
        voitureJoueur.velocite += voitureJoueur.acceleration * temps_last_update/1000;

    float distance = voitureJoueur.velocite * temps_last_update/1000;

    //Rotation des roues
    voitureJoueur.rotationRoue += (distance/(2.0*3.1415*0.1)) * 360.0;
    if (voitureJoueur.rotationRoue > 360.0){
        voitureJoueur.rotationRoue -= 360;
    }

    boucleRoute -= distance;
    if (boucleRoute < 0.0) boucleRoute += 1;

    //Gestion tourner
    if((droiteGaucheKey) && (fabs(voitureJoueur.x)) < POSITION_MAX_X){ 

        voitureJoueur.x += droiteGaucheKey * VITESSE_DEPLACEMENT;
        voitureJoueur.rotation += droiteGaucheKey * VITESSE_ROTATION;

        if(fabs(voitureJoueur.rotation) > ROTATION_MAX)
            voitureJoueur.rotation = ((voitureJoueur.rotation < 0)?-1:1) * ROTATION_MAX;
        if(fabs(voitureJoueur.x) > POSITION_MAX_X) 
            voitureJoueur.x = ((voitureJoueur.x < 0)?-1:1) * (POSITION_MAX_X-0.01);
    }

    //Retour automatique de la rotation
    if((!droiteGaucheKey) && (fabs(voitureJoueur.rotation) > 0.1)){

        voitureJoueur.rotation += ((voitureJoueur.rotation > 0)?-1:1) * VITESSE_ROTATION;
        if(fabs(voitureJoueur.rotation) < VITESSE_ROTATION+1 ) voitureJoueur.rotation = 0;
    }
}

/**
 * @fn updateObjects
 * @brief Change la position des objets à la suite de la liste objetsNiveaux
 */


void updateObjets(){
    int i;

    for(i = 0; i < *nbObjetsNiveauAct; i++){
        float dist=0;
        dist=voitureJoueur.velocite*temps_last_update/15.0;
        objetsNiveauAct[i].y -= fabs(dist);

        if (objetsNiveauAct[i].type == TYPE_OBSTACLE_MOUV){
            objetsNiveauAct[i].x += objetsNiveauAct[i].sens * .2;
            if (fabs(objetsNiveauAct[i].x) > 3){
                objetsNiveauAct[i].sens *= -1;
            }
        }
    }
}



/**
 * @fn ChangeCamera
 * @brief Change la perspective du jeu
 */


void changeCamera(int x, int y){

    static int prevx, prevy;
    int difx = x - prevx;
    int diffy = y - prevy;
    
    prevx = x;
    prevy = y;

    if(difx > 0){
        aziy++; 
    }
    else if (difx < 0){
        aziy--;        
    }

    if(diffy > 0){
        elex++;
    }
    else if(diffy < 0){
        elex--;
    }

    if(elex > 90) elex = 90;
    if(elex < 10) elex = 10;
    if(camDist < 5) camDist = 5;
    if(camDist > 20) camDist = 20;
}

/**
 * @fn quitterjeu 
 * @brief quitte le jeu OpenGL
 */

void quitterjeu(){
    GamePlaying = 0;
    glutSpecialFunc(NULL);
    glutSpecialUpFunc(NULL);
    glutKeyboardFunc(NULL);

    glutMouseFunc(NULL);
    glutMouseWheelFunc(NULL);
    glutMotionFunc(NULL);

   free(&(*objetsNiveauAct));

}