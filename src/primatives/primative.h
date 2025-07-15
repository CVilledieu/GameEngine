#ifndef PRIMATIVE_H
#define PRIMATIVE_H



typedef struct {
    unsigned int VAO;
    int IndexOrder;
    unsigned int *Indices;
    int VetexCount;
    float *Vertices;
    float ModelMtx[16];
} Mesh;


//Camera.c
void initCamera(void);
void setCamera(void);

//Mesh.c
Mesh CreateMesh(void);
void SetModelVOs(Mesh *mesh);
void DrawMesh(Mesh *mesh);

#endif