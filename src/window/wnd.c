#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "player.h"

GLFWwindow* wnd_main = (void*)0;

void callback_frameBufferSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}


void callback_mainWnd_UserInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) {
        return;
    }
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, 1);
            break;
        default:
            Player_Controls(key, action);
            break;
    }
    //Voiding unused parameters for compiler warnings
    (void)scancode;
	(void)mods;
}


void wnd_init(){
    char *title = "EndMyGE";
    
    if (!glfwInit()){
        printf("%s\n", "Failed to initialize GLFW");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    wnd_main = glfwCreateWindow(800, 600, title, NULL, NULL);
    if (!wnd_main){
        printf("%s\n", "Failed to create GLFW window");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(wnd_main);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("%s\n", "Failed to initialize GLAD");
        return;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(wnd_main, callback_frameBufferSize);
    glfwSetKeyCallback(wnd_main, callback_mainWnd_UserInput);
}



