#include "primative.h"


static float STDOBJ_ModelMtx[] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};

static float STDOBJ_Vertices[] = {
    // Positions          // Colors
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
};

static unsigned int STDOBJ_Indices[] = { 0, 1, 2, 2, 3, 0};



Mesh CreateNPCMesh() {
    Mesh STDOBJ_Mesh;
    STDOBJ_Mesh.VAO = 0;
    STDOBJ_Mesh.IndexOrder = sizeof(STDOBJ_Indices) / sizeof(unsigned int);
    STDOBJ_Mesh.Indices = STDOBJ_Indices;
    STDOBJ_Mesh.VetexCount = sizeof(STDOBJ_Vertices) / sizeof(float);
    STDOBJ_Mesh.Vertices = STDOBJ_Vertices;
    

    SetModelVOs(&STDOBJ_Mesh);
    return STDOBJ_Mesh;
}
