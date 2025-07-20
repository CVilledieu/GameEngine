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
Mesh Mesh_Create(void);
void SetModelVOs(Mesh *mesh);
void DrawMesh(Mesh *mesh);
void SetVAO(Mesh *mesh);
void Move(Mesh *mesh, float x, float y, float z);


//Mesh: Cube
Mesh Cube_CreateMesh(void);

//Mesh: Square
Mesh Square_CreateMesh(void);







#endif