#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

typedef struct {
    int id;
    float *OriginMtx; // Matrix for origin position and scale
    float *CurrentMtx; // Model matrix for transformations
    Mesh *mesh; // The actual mesh data
} Model;


typedef enum {
    TYPE_SQUARE,
    TYPE_CUBE,
} MeshType;




Model Model_Create(MeshType type, int id);


void Model_Draw(Model *model);
void Model_UpdateOrigin(Model *model);

#endif