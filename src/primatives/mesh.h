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


typedef enum {
    SQUARE_MESH,
    CUBE_MESH,
} MeshType;




//General
void SetModelVOs(Mesh *mesh);
void DrawMesh(Mesh *mesh);
void SetVAO(Mesh *mesh);

Mesh Mesh_Create(MeshType type);


//Mesh: Cube
Mesh Cube_CreateMesh(void);

//Mesh: Square
Mesh Square_CreateMesh(void);







#endif