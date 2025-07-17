#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <stdlib.h>
#include "mesh.h"
#include "shader.h"

Mesh *Player;

static float Player_ModelMtx[16] = {
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


void Player_Init(void) {
    Player = malloc(sizeof(Mesh));
    *Player = CreateMesh();
}
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
    glUniformMatrix4fv(glGetUniformLocation(ShaderID, "model"), 1, GL_FALSE, mesh->ModelMtx);
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->IndexOrder, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


void Player_Controls(int key, int action){
    switch (key){
        case GLFW_KEY_W:
            Player->ModelMtx[13] += 0.1f;
            break;
        case GLFW_KEY_S:
            Player->ModelMtx[13] -= 0.1f;
            break;
        case GLFW_KEY_A:
            Player->ModelMtx[12] -= 0.1f;
            break;
        case GLFW_KEY_D:
            Player->ModelMtx[12] += 0.1f;
            break;
        default:
            break;
    }
}