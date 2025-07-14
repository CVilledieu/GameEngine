#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window/wnd.h"
#include "shaders/shader.h"

int main(void){
    wnd_init();
    if (!wnd_main) {
        return -1; // Initialization failed
    }
    shader_init();

    while(!glfwWindowShouldClose(wnd_main)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        glfwSwapBuffers(wnd_main);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
