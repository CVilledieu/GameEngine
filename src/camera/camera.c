#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "mesh.h"
#include <math.h>




//===================
// View Matrix
//

static float ViewMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

void ViewMtx_Update(){
    ViewMtx[0] = 1.0f;
    ViewMtx[5] = 1.0f;
}

//==================
// Perspective and Orthographic Projection Matrix
//  

/*
x1 = (2 * near) / (right - left)
x3 = -(right + left) / (right - left)
y2 = (2 * near) / (bottom - top)
y3 = -(top + bottom) / (bottom - top)
z3 = far / (far - near)
z4 = -(far * near) / (far - near)

x1  0   0   0
0   y2  0   0
x3  y3  z3  w3  
0   0   1  0

*/


static float ProjectionMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, -1.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


static float aspectRatio = 8.0f / 6.0f; // Width / Height
static float near = 0.1f;
static float far = 100.0f;
static float fov = 90.0f; // Field of View in degrees



void ProjectionMtx_Update(){
    float top = near * tanf(fov * 0.5f * (3.14159265358979323846f / 180.0f));
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;

    ProjectionMtx[0] = (2.0f * near) / (right - left);
    ProjectionMtx[5] = (2.0f * near) / (top - bottom);
    ProjectionMtx[8] = (right + left) / (right - left);
    ProjectionMtx[9] = (top + bottom) / (top - bottom);
    ProjectionMtx[10] = -(far + near) / (far - near);
    ProjectionMtx[14] = -(2.0f * far * near) / (far - near);
}



//===================
// Camera Functions
// 
// Functions related to both the View and Projection Matrices

void Camera_Init() {
    ViewMtx_Update();
    ProjectionMtx_Update();
}

void Camera_Set(){

    glUniformMatrix4fv(glGetUniformLocation(Shader_Get(), "view"), 1, GL_FALSE, ViewMtx);
    glUniformMatrix4fv(glGetUniformLocation(Shader_Get(), "projection"), 1, GL_FALSE, ProjectionMtx);
}

void Player_Controls(int key, int action){
    switch (key){
        case GLFW_KEY_W:
            ViewMtx[13] += 0.1f;
            break;
        case GLFW_KEY_S:
            ViewMtx[13] -= 0.1f;
            break;
        case GLFW_KEY_A:
            ViewMtx[12] -= 0.1f;
            break;
        case GLFW_KEY_D:
            ViewMtx[12] += 0.1f;
            break;
        default:
            break;
    }
}