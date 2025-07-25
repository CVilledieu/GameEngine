#ifndef TERRRAIN_H
#define TERRRAIN_H

typedef struct {
    unsigned int VAO;
    int IndexCount;
    unsigned int *Indices;
    int VertexCount;
    float *Vertices;
    float ModelMtx[16];
} TileMesh;


typedef struct {
    float X_Cord;
    float Y_Cord;
    float Height;
    TileMesh *Mesh;
} Tile;

Tile Tile_Create(int width, int height);
void Terrain_Init(Tile *Tile);

void Terrain_Draw(Tile *Tile);

Tile TileMesh_Create();

void DrawTile(Tile *tile);

#endif