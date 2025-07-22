#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "wnd.h"
#include "shader.h"
#include "model.h"
#include "camera.h"




int main(void){
    wnd_init();
    if (!wnd_main) {
        return -1; // Initialization failed
    }
    Shader_Init();
    glEnable(GL_DEPTH_TEST);
    Model box = Model_Create(TYPE_SQUARE, 0);
    box.CurrentMtx[10] = 0.2f; // Set initial position
    
    Camera_Init();
    
    while(!glfwWindowShouldClose(wnd_main)){
        Shader_Use();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        Camera_Set();
        Model_Draw(&box);
        

        glfwSwapBuffers(wnd_main);
        glfwPollEvents();
    }


    // Cleanup resources
    Shader_Cleanup();
    glfwTerminate();
    return 0;
}    

