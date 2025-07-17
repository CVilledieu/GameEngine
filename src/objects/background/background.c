#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "mesh.h"
#include "view.h"

static float Background_ModelMtx[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float Background_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 0.8f, 0.8f, 0.8f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.8f, 0.8f, 0.8f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.8f, 0.8f, 0.8f, 1.0f,
    -0.5f,  0.5f, 0.0f, 0.8f, 0.8f, 0.8f, 1.0f
};

static unsigned int Background_Indices[] = { 0, 1, 2, 2, 3, 0};



Mesh Createbackground() {
    Mesh FP_Mesh;
    FP_Mesh.VAO = 0;
    FP_Mesh.IndexOrder = sizeof(Background_Indices) / sizeof(unsigned int);
    FP_Mesh.Indices = Background_Indices;
    FP_Mesh.VetexCount = sizeof(Background_Vertices) / sizeof(float);
    FP_Mesh.Vertices = Background_Vertices;
    

    SetModelVOs(&FP_Mesh);
    return FP_Mesh;
}

void DrawFP(Mesh *mesh) {
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "model"), 1, GL_FALSE, Background_ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}