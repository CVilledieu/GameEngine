#include "glfw/glfw3.h"

void callback_mainWnd_UserInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS) {
        return;
    }
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, 1);
            break;
        default:
            break;
    }
    //Voiding unused parameters for compiler warnings
    (void)scancode;
	(void)mods;
}