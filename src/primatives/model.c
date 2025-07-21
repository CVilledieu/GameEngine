#include "mesh.h"
#include <string.h>


typedef struct {
    int id;
    float *originMtx; // Matrix for origin position and scale
    float *ModelMtx; // Model matrix for transformations
    Mesh *mesh; // The actual mesh data
} Model;

static float ModelMtx_Base[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float ModelMtx_nonBase[16] = {
    0.05f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.05f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.5f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};



Model Model_Create(MeshType type, int id) {
    Model model;
    model.id = id;
    
    Mesh mesh = Mesh_Create(type);
    model.mesh = &mesh;

    model.originMtx = malloc(sizeof(float) * 16);
    memcpy(model.originMtx, ModelMtx_Base, sizeof(float) * 16);

    model.ModelMtx = malloc(sizeof(float) * 16);
    memcpy(model.ModelMtx, ModelMtx_Base, sizeof(float) * 16);

    return model;
}

void Model_SetPosition(Mesh *mesh, float x, float y, float z) {
    mesh->ModelMtx[3] = x;
    mesh->ModelMtx[7] = y;
    mesh->ModelMtx[11] = z;
}

void Model_SetScale(Mesh *mesh, float scale[3]) {
    mesh->ModelMtx[0] = scale[0];
    mesh->ModelMtx[5] = scale[1]; 
    mesh->ModelMtx[10] = scale[2];
}