#ifndef MESH_H
#define MESH_H


typedef struct {
    unsigned int VAO;
    int IndexOrder;
    unsigned int *Indices;
    int VetexCount;
    float *Vertices;
    float ModelMtx[16];
} Mesh;

//Mesh.c
Mesh CreateMesh(void);
void SetModelVOs(Mesh *mesh);
void DrawMesh(Mesh *mesh);

#endif