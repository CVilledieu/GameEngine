#ifndef MESH_H
#define MESH_H


typedef struct {
    unsigned int VAO;
    int IndexOrder;
    unsigned int *Indices;
    int VetexCount;
    float *Vertices;
    float *ModelMtx;
} Mesh;




//General

void DrawMesh(Mesh *mesh);


//Mesh: Cube
Mesh Cube_CreateMesh(void);

//Mesh: Square
Mesh Square_CreateMesh(void);







#endif