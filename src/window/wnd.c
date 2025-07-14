#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "wnd.h"

GLFWwindow* wnd_main = (void*)0;

void callback_frameBufferSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
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
