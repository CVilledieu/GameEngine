#include <glad/glad.h>
#include "shader.h"
#include "mesh.h"


static float farPlane = 100.0f; 
static float nearPlane = 0.1f;



//===================
// View and Projection
//===================
static float ProjectionMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float ViewMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};



void ViewMtx_updateAspectRatio(){
    float aspectRatio = 800.0f / 600.0f; // Assuming a window size of 800x600

    // Adjust scaling based on aspect ratio
    ViewMtx[0] = 1.0f / aspectRatio; 
    ViewMtx[5] = 1.0f / aspectRatio; 

}


void View_Set(){
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "view"), 1, GL_FALSE, ViewMtx);
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "projection"), 1, GL_FALSE, ProjectionMtx);
}



void Rotate_X(float angle) {
    float SinTheta = farPlane / (360000 + (farPlane * farPlane));
    float Cos = 1.0 / (1.0 + (farPlane * farPlane));

    ViewMtx[5] = Cos;
    ViewMtx[6] = SinTheta;
    ViewMtx[9] = -SinTheta;
    ViewMtx[10] = Cos;
}
/*
void Rotate_Y(float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    ViewMtx[0] = cosAngle;
    ViewMtx[2] = -sinAngle;
    ViewMtx[8] = sinAngle;
    ViewMtx[10] = cosAngle;
}

void Rotate_Z(float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    ViewMtx[0] = cosAngle;
    ViewMtx[1] = sinAngle;
    ViewMtx[4] = -sinAngle;
    ViewMtx[5] = cosAngle;
}

*/





//==================
// Far plane
//==================

float GetFarPlane() {
    return farPlane;
}




//===================
// Near plane
//===================

float GetNearPlane() {
    return nearPlane;
}