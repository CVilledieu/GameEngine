#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "wnd.h"
#include "shader.h"
#include "mesh.h"





int main(void){
    wnd_init();
    if (!wnd_main) {
        return -1; // Initialization failed
    }
    Shader_Init();
    glEnable(GL_DEPTH_TEST);
    Mesh box = Box_CreateMesh();


    
    while(!glfwWindowShouldClose(wnd_main)){
        Shader_Use();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);



        glfwSwapBuffers(wnd_main);
        glfwPollEvents();
    }


    // Cleanup resources
    Shader_Cleanup();
    glfwTerminate();
    return 0;
}    

