#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "mesh.h"
#include "shader.h"

static float square_ModelMtx[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float square_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int square_Indices[] = { 0, 1, 2, 2, 3, 0};

Mesh CreateSquareMesh() {
    Mesh squareMesh;
    squareMesh.VAO = 0;
    squareMesh.IndexOrder = sizeof(square_Indices) / sizeof(unsigned int);
    squareMesh.Indices = square_Indices;
    squareMesh.VetexCount = sizeof(square_Vertices) / sizeof(float);
    squareMesh.Vertices = square_Vertices;

    SetModelVOs(&squareMesh);
    return squareMesh;
}


