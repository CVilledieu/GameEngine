#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "mesh.h"
#include "camera.h"

static float Background_ModelMtx[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

Mesh Createbackground() {
    Mesh background = Square_CreateMesh();
    
}

void DrawFP(Mesh *mesh) {
    glUniformMatrix4fv(glGetUniformLocation(Shader_Use, "model"), 1, GL_FALSE, Background_ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}