#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "wnd.h"
#include "shader.h"
#include "mesh.h"
#include "view.h"



int main(void){
    wnd_init();
    if (!wnd_main) {
        return -1; // Initialization failed
    }
    shader_init();
    Mesh Player = CreateMesh();

    initCamera();

    while(!glfwWindowShouldClose(wnd_main)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glUseProgram(ShaderID);
        setCamera();
        DrawMesh(&Player);

        glfwSwapBuffers(wnd_main);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

