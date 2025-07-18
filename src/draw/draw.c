#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "view.h"
#include "wnd.h"
#include "mesh.h"


void Draw_Prep(void) {
    glUseProgram(ShaderID);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    View_Set();
}


void Draw_Cleanup() {
    glfwSwapBuffers(wnd_main);
    glfwPollEvents();
}

// 
void Draw_Main(Mesh *mesh) {
    // Clear screen and prepare to draw
    Draw_Prep();


    DrawMesh(mesh);
    Move(mesh, 0.0f, -0.01f, 0.0f);

    //After draw processes. Swap buffers and poll events
    Draw_Cleanup();
}

