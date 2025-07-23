#include <glad/glad.h>
#include "terrain.h"

static float Tile_Vertices[] = {
    -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
     1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -1.0f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int Tile_DrawIndices[] = {
    0, 2, 1,
    1, 2, 3,
    3, 2, 4,
    0, 2, 4,
};

static void Set_VAO(Tile *tile) {
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &tile->VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(tile->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, tile->VertexCount * sizeof(float), tile->Vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, tile->IndexCount * sizeof(unsigned int), tile->Indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0); 
}


Tile Tile_Create() {
    Tile newTile;

    newTile.IndexCount = sizeof(Tile_DrawIndices) / sizeof(unsigned int);
    newTile.Indices = Tile_DrawIndices;
    newTile.VertexCount = sizeof(Tile_Vertices) / sizeof(float);
    newTile.Vertices = Tile_Vertices;

    newTile.VAO = 0;
    Set_VAO(&newTile);
    return newTile;
}