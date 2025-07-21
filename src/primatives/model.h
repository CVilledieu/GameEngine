#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"

typedef struct {
    int id;
    float *originMtx; // Matrix for origin position and scale
    float *ModelMtx; // Model matrix for transformations
    Mesh *mesh; // The actual mesh data
} Model;


Model Model_Create(float position[3], MeshType type, int id); 
#endif