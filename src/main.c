#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "wnd.h"
#include "shader.h"
#include "mesh.h"

#include "draw.h"


int main(void){
    wnd_init();
    if (!wnd_main) {
        return -1; // Initialization failed
    }
    shader_init();
    Mesh box = Box_CreateMesh();


    while(!glfwWindowShouldClose(wnd_main)){
        Draw_Main(&box);
    }
    glfwTerminate();
    return 0;
}    

