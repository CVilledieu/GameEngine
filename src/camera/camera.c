#include <glad/glad.h>
#include "shader.h"
#include "mesh.h"


//===================
// View Matrix
//

static float ViewMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

void View_Init(){

}

//==================
// Projection Matrix
//

static float ProjectionMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, -1.0f,
    0.0f, 0.0f, 0.0f, 0.0f
};




// Orthographic Projection
// Used for 2D rendering
// Enlarge or shrink the clipping volume 
static float orthoRight = 1.0f;
static float orthoLeft = -1.0f;
static float orthoTop = 1.0f;
static float orthoBottom = -1.0f;
static float orthoNear = -1.0f;


// Perspective Projection
static float near = 0.1f;
static float far = 100.0f;
static float t = 0.000387851f; // near * tan(45.0f * (3.14159265358979323846f / 180.0f))
static float top = 0.0000387851f;




void Projection_Update(){
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
    View_Init();
    Projection_Init();
}

void Camera_Set(){

    glUniformMatrix4fv(glGetUniformLocation(Shader_Use, "view"), 1, GL_FALSE, ViewMtx);
    glUniformMatrix4fv(glGetUniformLocation(Shader_Use, "projection"), 1, GL_FALSE, ProjectionMtx);
}

