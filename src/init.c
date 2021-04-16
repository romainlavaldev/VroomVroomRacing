/*************************************************************
 *              Initialisation 
 * 
 * 
 * @file init.c
 * @author {Romain LAVAL, Nathan LABBE, Louis GEORGET}
 * @brief Initialisation de fenêtre et ressources !
 * @version 2.0
 * 
 * ********************************************************* */
#include <init.h>

/**
 * @fn initWindow 
 * @brief initialise la fenêtre de render 3d
 */

void initWindow(int argc, char** argv){
    printf("Debut chargement textures\n");
    glutInit(&argc, argv);
    printf("Glut initialise\n");
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition(100,100);
    printf("Position + taille de la fenetre initialise\n");
    glutCreateWindow("Vroom Vroom Racing !");
    printf("fenetre creee\n");

    printf("\n** Chargement des resources\n");
    loadResources();

    glClearColor(0.0,0.0,0.0,1);

    //Setup du GL
    glShadeModel(GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutReshapeFunc(windowResize);
    //glutIgnoreKeyRepeat(1);
    printf("Fin init window");
}
/**
 * @fn windowResize 
 * @brief Change la taille de la fenêtre
 */

void windowResize(int w, int h){
    windowHeight = h;
    windowWidth = w;

    if(h == 0) h = 1;

    float ratio = 1.0f * w / h;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    perspectiveGL(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    if(GamePlaying > 0);
        changeCamera(0,0);
}

/**
 * @fn loadRessources 
 * @brief charge les textures
 */

void loadResources(){
    
    printf("debut\n");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    //textures
    TexArray[TEXTURE_ROUTE] = SOIL_load_OGL_texture(
        "img/road.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS
    );
    printf("Texture route creee + stocké en mémoire\n");

    TexArray[TEXTURE_VOITURE1] = SOIL_load_OGL_texture(
        "img/car.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture voiture1 creee + stocké en mémoire\n");

    TexArray[TEXTURE_ROUE] = SOIL_load_OGL_texture(
        "img/tyre.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture voiture1 creee + stocké en mémoire\n");

    TexArray[TEXTURE_CIEL] = SOIL_load_OGL_texture(
        "img/sky.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture voiture1 creee + stocké en mémoire\n");

    TexArray[TEXTURE_PTR] = SOIL_load_OGL_texture(
        "img/pointer.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture pointer creee + stocké en mémoire\n");

    TexArray[TEXTURE_COMPTEUR] = SOIL_load_OGL_texture(
        "img/compteur.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture compteur creee + stocké en mémoire\n");

    
    TexArray[TEXTURE_POUBELLE] = SOIL_load_OGL_texture(
        "img/MetalTexture.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture poubelle creee + stocké en mémoire\n");

    TexArray[TEXTURE_GAMEOVER] = SOIL_load_OGL_texture(
        "img/gameover.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture GameOver + stocké en mémoire\n");
    TexArray[TEXTURE_FINISH] = SOIL_load_OGL_texture(
        "img/finish.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Texture finish + stocké en mémoire\n");

    TexArray[TEXTURE_SAND]=SOIL_load_OGL_texture(
        "img/sand.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    
    TexArray[TEXTURE_STAR]=SOIL_load_OGL_texture(
        "img/star.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
    printf("Checkpoint1\n");
    










    //obj

    if (!voitureModel1){
        voitureModel1 = glmReadOBJ("img/car.obj");
        printf("Voiture creee + stocké en mémoire\n");
    }


    if (!roueModel1){
        roueModel1 = glmReadOBJ("img/wheel.obj");
        printf("Roue creee + stocké en mémoire\n");
    }

    if (!poubelleModel){
        poubelleModel = glmReadOBJ("img/Trashcantest.obj");
        printf("Poubelle creee + stocké en mémoire\n");
    }

    if (!finishModel){
        finishModel = glmReadOBJ("img/finish.obj");
        printf("Finish creee + stocké en mémoire\n");
    }

    if (!panneauModel){
        panneauModel = glmReadOBJ("img/panneau.obj");
        printf("Panneau creee + stocké en mémoire\n");
    }

    if (!ovniModel){
        ovniModel = glmReadOBJ("img/ovni.obj");
        printf("ovni creee + stocké en mémoire\n");
    }
    if (!starModel){
        starModel = glmReadOBJ("img/star.obj");
        printf("star creee + stocké en mémoire\n");
    }


    printf("\nFin chargement textures\n");
}


/**
 * @fn loadResourcesNiv2 
 * @brief Genere les ressources du niveau 2
 */

void loadResourcesNiv2(){
    printf("debut\n");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    
    //Route66 ROAD
    TexArray[TEXTURE_SAND]=SOIL_load_OGL_texture(
        "img/route66/sand.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );

    TexArray[TEXTURE_CIEL] = SOIL_load_OGL_texture(
        "img/route66/sky.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );


    TexArray[TEXTURE_ROUTE] = SOIL_load_OGL_texture(
        "img/route66/img_road.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS
    );
    printf("Texture route66 route creee + stocké en mémoire\n");

}

/**
 * @fn loadResourcesNiv3
 * @brief Genere les ressources du niveau 3
 */

void loadResourcesNiv3(){
    printf("debut\n");
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    //RAINBOW ROAD
    TexArray[TEXTURE_SAND]=SOIL_load_OGL_texture(
        "img/rainbow/sand.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );

    TexArray[TEXTURE_CIEL] = SOIL_load_OGL_texture(
        "img/rainbow/sky.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );


    TexArray[TEXTURE_ROUTE] = SOIL_load_OGL_texture(
        "img/rainbow/img_road.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS
    );

    printf("Texture rainbow route creee + stocké en mémoire\n");
}

   /* TexArray[TEXTURE_VOITURE1] = SOIL_load_OGL_texture(
        "img/rainbow/car.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
    );
*/

    //printf("\nFin chargement textures\n");
