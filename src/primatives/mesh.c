#include <glad/glad.h>
#include "mesh.h"
#include "shader.h"
#include <string.h>
#include <stdlib.h>


static float ModelMtx_Base[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


void Move(Mesh *mesh, float x, float y, float z) {
    mesh->ModelMtx[12] += x;
    mesh->ModelMtx[13] += y;
    mesh->ModelMtx[14] += z;
}




void SetVAO(Mesh *mesh) {
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(mesh->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->VetexCount * sizeof(float), mesh->Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->IndexOrder * sizeof(unsigned int), mesh->Indices, GL_STATIC_DRAW);

    //Indices 0-2 are position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //Indices 3-6 are color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind VAO to avoid accidental modification
    glBindVertexArray(0);
}


/*
Mesh Mesh_Create() {
    Mesh newMesh;
    newMesh.VAO = 0;
    newMesh.IndexOrder = sizeof(Square_DrawIndices) / sizeof(unsigned int);
    newMesh.Indices = Square_DrawIndices;
    newMesh.VetexCount = sizeof(Square_Vertices) / sizeof(float);
    newMesh.Vertices = Square_Vertices;
    newMesh.ModelMtx = malloc(16 * sizeof(float));
    memcpy(newMesh.ModelMtx, ModelMtx_Base, 16 * sizeof(float));
    SetModelVOs(&newMesh);
    return newMesh;
}
*/

void SetModelVOs(Mesh *mesh) {
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &mesh->VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(mesh->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->VetexCount * sizeof(float), mesh->Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->IndexOrder * sizeof(unsigned int), mesh->Indices, GL_STATIC_DRAW);

    //Indices 0-2 are position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //Indices 3-6 are color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind VAO to avoid accidental modification
    glBindVertexArray(0);
}

void DrawMesh(Mesh *mesh) {
    glUniformMatrix4fv(glGetUniformLocation(Shader_Use, "model"), 1, GL_FALSE, mesh->ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

//=================
// Mesh: Square
//=================

static float Square_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int Square_DrawIndices[] = { 0, 1, 2, 2, 3, 0};

Mesh Square_CreateMesh() {
    Mesh newMesh;
    
    newMesh.IndexOrder = sizeof(Square_DrawIndices) / sizeof(unsigned int);
    newMesh.Indices = Square_DrawIndices;

    newMesh.VetexCount = sizeof(Square_Vertices) / sizeof(float);
    newMesh.Vertices = Square_Vertices;

    newMesh.ModelMtx = malloc(16 * sizeof(float));
    memcpy(newMesh.ModelMtx, ModelMtx_Base, 16 * sizeof(float));

    newMesh.VAO = 0;
    SetModelVOs(&newMesh);
    return newMesh;
}


//=================
// Mesh: Box
//=================

static float Box_Vertices[] ={
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,
};

static unsigned int Box_DrawIndices[] = {
    0, 1, 2, 2, 3, 0, // Back face
    4, 5, 6, 6, 7, 4, // Front face
    0, 1, 5, 5, 4, 0, // Bottom face
    2, 3, 7, 7, 6, 2, // Top face
    0, 3, 7, 7, 4, 0, // Left face
    1, 2, 6, 6, 5, 1 // Right face
};


Mesh Box_CreateMesh() {
    Mesh newMesh;
    
    newMesh.IndexOrder = sizeof(Box_DrawIndices) / sizeof(unsigned int);
    newMesh.Indices = Box_DrawIndices;

    newMesh.VetexCount = sizeof(Box_Vertices) / sizeof(float);
    newMesh.Vertices = Box_Vertices;

    newMesh.ModelMtx = malloc(16 * sizeof(float));
    memcpy(newMesh.ModelMtx, ModelMtx_Base, 16 * sizeof(float));

    newMesh.VAO = 0;
    SetModelVOs(&newMesh);
    return newMesh;
}