/*************************************************************
 *              ObjetsNiveaux 
 * 
 * 
 * @file objetsNiveaux.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @date 29 Mars 2021
 * @brief Les obstacles de fou
 * @version 1.0
 * 
 * ********************************************************* */

#include <stdio.h>
#include <objetsNiveaux.h>

/***Niveau1 -- RETROWAVE -- ****/

int* nbObjetsNiveauAct;
objet* objetsNiveauAct;

int posObjetsNiveau1[11][11] = {{2,100},{-1,200},{3,250},{2,350},{-3,420},{-2,480},{0,520},{3,700},{0,790},{-1,850},{0,1000}};

objet objetsNiveau1[11] = {
    {2, 100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 850, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0,1000,0,TEXTURE_NONE,NULL, TYPE_FINISH}
    };
int nbObjetsNiveau1 = 11;

/**
 * @fn initNiveau1 
 * @brief Load les obstacles du niveau 1
 */

void initNiveau1(){
    int i;
    for (i = 0; i < nbObjetsNiveau1; i++)
    {
        objetsNiveau1[i].x = posObjetsNiveau1[i][0];
        objetsNiveau1[i].y = posObjetsNiveau1[i][1];
    }

    objetsNiveau1[0].model = panneauModel;
    objetsNiveau1[1].model = panneauModel;
    objetsNiveau1[2].model = panneauModel;
    objetsNiveau1[3].model = panneauModel;
    objetsNiveau1[4].model = panneauModel;
    objetsNiveau1[5].model = panneauModel;
    objetsNiveau1[6].model = panneauModel;
    objetsNiveau1[7].model = panneauModel;
    objetsNiveau1[8].model = panneauModel;
    objetsNiveau1[9].model = panneauModel;
    objetsNiveau1[10].model = finishModel;
}


/***Niveau2 -- DESERT --****/

int posObjetsNiveau2[21][21] = {{2,100},{1,200},{-1,250},{2,350},{-1,420},{2,480},{1,520},{-3,700},{1,790},{2,850},{-2,1100},{0,1200},
{2,1250},{-1,1350},{-2,1420},{1,1480},{3,1520},{0,1700},{-3,1790},{-1,1850},{0,2000}};

objet objetsNiveau2[21] = {
    {2, 100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_MOUV, -1},//1
    {1, 200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},//5
    {2, 480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_MOUV, -1},
    {-3, 700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 850, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, -1},//10
    {-2, 1100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_MOUV, -1},
    {0, 1200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 1250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 1420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, -1},//15
    {1, 1480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_MOUV, -1},
    {3, 1520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 1700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 1790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1850, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},//20
    {0,2000,0,TEXTURE_NONE,NULL, TYPE_FINISH}
    };

int nbObjetsNiveau2 = 21;


/**
 * @fn initNiveau2
 * @brief Load les obstacles du niveau 2
 */
void initNiveau2(){

    int i;
    for (i = 0; i < nbObjetsNiveau2; i++)
    {
        objetsNiveau2[i].x = posObjetsNiveau2[i][0];
        objetsNiveau2[i].y = posObjetsNiveau2[i][1];
    }

    objetsNiveau2[0].model = ovniModel;
    objetsNiveau2[1].model = poubelleModel;
    objetsNiveau2[2].model = poubelleModel;
    objetsNiveau2[3].model = poubelleModel;
    objetsNiveau2[4].model = poubelleModel;
    objetsNiveau2[5].model = poubelleModel;
    objetsNiveau2[6].model = ovniModel;
    objetsNiveau2[7].model = poubelleModel;
    objetsNiveau2[8].model = poubelleModel;
    objetsNiveau2[9].model = poubelleModel;
    objetsNiveau2[10].model = ovniModel;
    objetsNiveau2[11].model = poubelleModel;
    objetsNiveau2[12].model = poubelleModel;
    objetsNiveau2[13].model = poubelleModel;
    objetsNiveau2[14].model = poubelleModel;
    objetsNiveau2[15].model = ovniModel;
    objetsNiveau2[16].model = poubelleModel;
    objetsNiveau2[17].model = poubelleModel;
    objetsNiveau2[18].model = poubelleModel;
    objetsNiveau2[19].model = poubelleModel;
    objetsNiveau2[20].model = finishModel;
}


/***Niveau3 -- ARC EN CIEL -- ****/

int posObjetsNiveau3[41][41] = {{2,100},{1,200},{-1,250},{2,350},{-1,420},{2,480},{1,520},{-3,700},{1,790},{2,850},{-2,1100},{0, 1200},{2, 1250},{-1, 135},{-2, 1420},{1, 1480},{3, 1520},{0, 1700},{-3, 1790},{-1, 1850},{-1, 2100},{3, 2200},{2, 2250},{0, 2350},{-1, 2390},{-1, 2480},{0, 2520},{2, 2780},{0, 2820},{-3, 2980},{2, 3100},{0, 3200},{-1, 3250},{3, 3350},{2, 3420},{-3, 3480},{0, 3520},{-1, 3700},{0, 3790},{2, 3920},{0,4000}};

objet objetsNiveau3[41] = {
    {2, 100, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 200, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 250, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 350, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 420, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 480, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 520, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 700, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 790, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 850, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 1100, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 1200, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 1250, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1350, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 1420, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 1480, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 1520, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 1700, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 1790, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1850, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2100, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 2200, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 2250, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2350, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2390, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2480, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2520, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 2780, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2820, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 2980, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3100, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3200, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 3250, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 3350, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3420, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 3480, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3520, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 3700, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3790, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3920, 0, TEXTURE_STAR, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0,4000,0,TEXTURE_NONE,NULL, TYPE_FINISH}
    };


/*
objet objetsNiveau3[41] = {
    {2, 100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 850, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 1100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 1200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 1250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-2, 1420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {1, 1480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 1520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 1700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 1790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 1850, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 2200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 2250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2390, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 2480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 2780, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 2820, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 2980, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3100, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3200, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 3250, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {3, 3350, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3420, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-3, 3480, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3520, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {-1, 3700, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0, 3790, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {2, 3920, 0, TEXTURE_POUBELLE, NULL, TYPE_OBSTACLE_FIXE, 0},
    {0,4000,0,TEXTURE_NONE,NULL, TYPE_FINISH}
    };

    */
int nbObjetsNiveau3 = 41;


/**
 * @fn initNiveau3 
 * @brief Load les obstacles du niveau 3
 */

void initNiveau3(){

    int i;
    for (i = 0; i < nbObjetsNiveau3; i++)
    {
        objetsNiveau3[i].x = posObjetsNiveau3[i][0];
        objetsNiveau3[i].y = posObjetsNiveau3[i][1];
    }
    
    objetsNiveau3[0].model = starModel;
    objetsNiveau3[1].model = starModel;
    objetsNiveau3[2].model = starModel;
    objetsNiveau3[3].model = starModel;
    objetsNiveau3[4].model = starModel;
    objetsNiveau3[5].model = starModel;
    objetsNiveau3[6].model = starModel;
    objetsNiveau3[7].model = starModel;
    objetsNiveau3[8].model = starModel;
    objetsNiveau3[9].model = starModel;
    objetsNiveau3[10].model = starModel;
    objetsNiveau3[11].model = starModel;
    objetsNiveau3[12].model = starModel;
    objetsNiveau3[13].model = starModel;
    objetsNiveau3[14].model = starModel;
    objetsNiveau3[15].model = starModel;
    objetsNiveau3[16].model = starModel;
    objetsNiveau3[17].model = starModel;
    objetsNiveau3[18].model = starModel;
    objetsNiveau3[19].model = starModel;
    objetsNiveau3[20].model = starModel;
    objetsNiveau3[21].model = starModel;
    objetsNiveau3[22].model = starModel;
    objetsNiveau3[23].model = starModel;
    objetsNiveau3[24].model = starModel;
    objetsNiveau3[25].model = starModel;
    objetsNiveau3[26].model = starModel;
    objetsNiveau3[27].model = starModel;
    objetsNiveau3[28].model = starModel;
    objetsNiveau3[29].model = starModel;
    objetsNiveau3[30].model = starModel;
    objetsNiveau3[31].model = starModel;
    objetsNiveau3[32].model = starModel;
    objetsNiveau3[33].model = starModel;
    objetsNiveau3[34].model = starModel;
    objetsNiveau3[35].model = starModel;
    objetsNiveau3[36].model = starModel;
    objetsNiveau3[37].model = starModel;
    objetsNiveau3[38].model = starModel;
    objetsNiveau3[39].model = starModel;
    objetsNiveau3[40].model = finishModel;
}
/*
void initNiveau3(){
    objetsNiveau3[0].model = poubelleModel;
    objetsNiveau3[1].model = poubelleModel;
    objetsNiveau3[2].model = poubelleModel;
    objetsNiveau3[3].model = poubelleModel;
    objetsNiveau3[4].model = poubelleModel;
    objetsNiveau3[5].model = poubelleModel;
    objetsNiveau3[6].model = poubelleModel;
    objetsNiveau3[7].model = poubelleModel;
    objetsNiveau3[8].model = poubelleModel;
    objetsNiveau3[9].model = poubelleModel;
    objetsNiveau3[10].model = poubelleModel;
    objetsNiveau3[11].model = poubelleModel;
    objetsNiveau3[12].model = poubelleModel;
    objetsNiveau3[13].model = poubelleModel;
    objetsNiveau3[14].model = poubelleModel;
    objetsNiveau3[15].model = poubelleModel;
    objetsNiveau3[16].model = poubelleModel;
    objetsNiveau3[17].model = poubelleModel;
    objetsNiveau3[18].model = poubelleModel;
    objetsNiveau3[19].model = poubelleModel;
    objetsNiveau3[20].model = poubelleModel;
    objetsNiveau3[21].model = poubelleModel;
    objetsNiveau3[22].model = poubelleModel;
    objetsNiveau3[23].model = poubelleModel;
    objetsNiveau3[24].model = poubelleModel;
    objetsNiveau3[25].model = poubelleModel;
    objetsNiveau3[26].model = poubelleModel;
    objetsNiveau3[27].model = poubelleModel;
    objetsNiveau3[28].model = poubelleModel;
    objetsNiveau3[29].model = poubelleModel;
    objetsNiveau3[30].model = poubelleModel;
    objetsNiveau3[31].model = poubelleModel;
    objetsNiveau3[32].model = poubelleModel;
    objetsNiveau3[33].model = poubelleModel;
    objetsNiveau3[34].model = poubelleModel;
    objetsNiveau3[35].model = poubelleModel;
    objetsNiveau3[36].model = poubelleModel;
    objetsNiveau3[37].model = poubelleModel;
    objetsNiveau3[38].model = poubelleModel;
    objetsNiveau3[39].model = poubelleModel;
    objetsNiveau3[40].model = finishModel;
}
*/

/**
 * @fn ObjetRender
 * @brief Render d'un objet 3D
 */


void objetRender(objet obj){
    printf("*Debut rendu obj*\n");
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    
    if(niveau != 3){
        glRotatef(0.0,1.0,0,0);
        glTranslatef(obj.x, 0, -obj.y);
    }else{
        glTranslatef(obj.x, 1.3, -obj.y);
    }
    printf("Application des textures\n");
    glBindTexture(GL_TEXTURE_2D, TexArray[obj.texture]);
    printf("Fin\n");
    
    printf("Application du model\n");
    glmDraw(obj.model, GLM_SMOOTH | GLM_TEXTURE);
    printf("Fin\n");

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    printf("*Fin*\n");    
}