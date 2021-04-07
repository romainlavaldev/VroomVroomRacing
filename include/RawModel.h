#include <glew.h>
#include <glfw3.h>
#include <stdio.h>

/**
 * \struct RawModel
 * \brief Initialisation d'un modèle
 *
 * @param int VaoID
 * @param int vertexCount
 */

typedef struct RawModel_s
{
    int VaoID;
    int vertexCount;
}RawModel;

RawModel loadToVAO(GLfloat[]);
void cleanUp();
void unbindVAO();
void initRawModels();
int createVAO();
void storeDataInAttributeList(int, GLfloat[]);
