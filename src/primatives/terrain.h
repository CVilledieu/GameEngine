#ifndef TERRRAIN_H
#define TERRRAIN_H


typedef struct {} Terrain;

typedef struct {
    int Width;
    int Length;
    int TileCount;
    Tile *Tiles;

} Chunk;

typedef struct {
    unsigned int VAO;
    int IndexCount;
    unsigned int *Indices;
    int VertexCount;
    float *Vertices;
    
} Tile;


#endif