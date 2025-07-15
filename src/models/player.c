#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "primative.h"
#include "shader.h"



static float ModelMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float Player_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int Player_Indices[] = { 0, 1, 2, 2, 3, 0};

Mesh Player_InitMesh() {
    Mesh playerMesh;
    playerMesh.VAO = 0;
    playerMesh.IndexOrder = sizeof(Player_Indices) / sizeof(unsigned int);
    playerMesh.Indices = Player_Indices;
    playerMesh.VetexCount = sizeof(Player_Vertices) / sizeof(float);
    playerMesh.Vertices = Player_Vertices;
    

    SetModelVOs(&playerMesh);
    return playerMesh;
}
void DrawPlayer(Mesh *mesh) {
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "model"), 1, GL_FALSE, ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


void Player_Controls(int key, int action){
    switch (key){
        case GLFW_KEY_W:
            if (action == GLFW_PRESS) {
                // Handle W key press
            }
            break;
        case GLFW_KEY_S:
            if (action == GLFW_PRESS) {
                // Handle S key press
            }
            break;
        case GLFW_KEY_A:
            if (action == GLFW_PRESS) {
                // Handle A key press
            }
            break;
        case GLFW_KEY_D:
            if (action == GLFW_PRESS) {
                // Handle D key press
            }
            break;
        default:
            break;
    }
}