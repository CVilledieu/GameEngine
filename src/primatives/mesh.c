#include <glad/glad.h>
#include "primative.h"
#include "../shaders/shader.h"
static float ModelMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //Indices 3-6 are color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind VAO to avoid accidental modification
    glBindVertexArray(0);
}


void DrawMesh(Mesh *mesh) {
    glUseProgram(ShaderID);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

