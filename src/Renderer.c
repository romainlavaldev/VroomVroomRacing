#include <glew.h>
#include <glfw3.h>
#include <Renderer.h>

/**
 * @fn preparer 
 * @brief Preparation rendu
 */

void prepare(){
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