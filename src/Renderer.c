#include <glfw3.h>
#include <glew.h>
#include <Renderer.h>

/**
 * @fn preparer 
 * @brief Preparation rendu
 */

void preparer(){
    glClear(GL_COLOR_BUFFER_BIT);
}

/**
 * @fn render 
 * @brief Création rendu
 * @param RawModel model
 */

void render(RawModel model){
    glBindVertexArray(model.VaoID);
    glEnableVertexArrayAttrib(model.VaoID,0);
    glDrawArrays(GL_TRIANGLES, 0, model.vertexCount);
    glDisableVertexAttribArray(0);
}