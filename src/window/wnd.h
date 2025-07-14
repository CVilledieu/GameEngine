#ifndef MAIN_WND_H
#define MAIN_WND_H

#include <GLFW/glfw3.h>

extern GLFWwindow* wnd_main;
void wnd_init();

// Callback functions
void callback_mainWnd_UserInput(GLFWwindow* window, int key, int scancode, int action, int mods);


#endif