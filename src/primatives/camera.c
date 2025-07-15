#include <glad/glad.h>
#include "shader.h"

static float ProjectionMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, -1.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float ViewMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};



void initViewMtx(){
    float aspectRatio = 800.0f / 600.0f; // Assuming a window size of 800x600

    // Adjust scaling based on aspect ratio
    ViewMtx[0] = 1.0f / aspectRatio; 
    ViewMtx[5] = 1.0f / aspectRatio; 

}

void initCamera(){
    initViewMtx();
}

void setCamera(){
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "view"), 1, GL_FALSE, ViewMtx);
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "projection"), 1, GL_FALSE, ProjectionMtx);
}
