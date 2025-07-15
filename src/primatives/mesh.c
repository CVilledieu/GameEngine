#include <glad/glad.h>
#include "primative.h"
#include "shader.h"


static float STDOBJ_ModelMtx[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float STDOBJ_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int STDOBJ_Indices[] = { 0, 1, 2, 2, 3, 0};



Mesh CreateMesh() {
    Mesh playerMesh;
    playerMesh.VAO = 0;
    playerMesh.IndexOrder = sizeof(STDOBJ_Indices) / sizeof(unsigned int);
    playerMesh.Indices = STDOBJ_Indices;
    playerMesh.VetexCount = sizeof(STDOBJ_Vertices) / sizeof(float);
    playerMesh.Vertices = STDOBJ_Vertices;
    

    SetModelVOs(&playerMesh);
    return playerMesh;
}


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
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "model"), 1, GL_FALSE, mesh->ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


