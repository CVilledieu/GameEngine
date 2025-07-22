#include <glad/glad.h>
#include <string.h>
#include <stdlib.h>

#include "mesh.h"
#include "shader.h"
#include "model.h"

static float ModelMtx[16] = {
    0.05f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.05f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.5f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


// Controller class will determine the type of mesh to create and the id for the model.
Model Model_Create(MeshType type, int id) {
    Model model;
    model.id = id;
    model.mesh = malloc(sizeof(Mesh));
    switch (type) {
        case TYPE_SQUARE:
            *model.mesh = Square_CreateMesh();
            break;
        case TYPE_CUBE:
            *model.mesh = Cube_CreateMesh();
            break;
        default:
            model.mesh = NULL; // Invalid type
            break;
    }

    model.OriginMtx = malloc(sizeof(float) * 16);
    memcpy(model.OriginMtx, ModelMtx, sizeof(float) * 16);

    model.CurrentMtx = malloc(sizeof(float) * 16);
    memcpy(model.CurrentMtx, ModelMtx, sizeof(float) * 16);

    return model;
}

// Draw calls DrawMesh() so that if a new mesh type is added that neeeds its own drawing logic, a swithc statement can be added here.
void Model_Draw(Model *model) {
    if (model->mesh == NULL) {
        return; // No mesh to draw
    }

    glUniformMatrix4fv(glGetUniformLocation(Shader_Get(), "model"), 1, GL_FALSE, model->CurrentMtx);
    DrawMesh(model->mesh);
}

// CurrentMtx should be updated and then OriginMtx can be updated
// This is to cut down on number of support functions needed, but also
// to reduce potential errors in updating the matrices.
void Model_UpdateOrigin(Model *model){
    memcpy(model->OriginMtx, model->CurrentMtx, sizeof(float) * 16);
}



// ===========================================
// Model transformations
//

// SetPosition is relative to the world origin, not the model's origin.
void Model_Move(Model *m, float translate[3]) {
    m->CurrentMtx[3] = translate[0];
    m->CurrentMtx[7] = translate[1];
    m->CurrentMtx[11] = translate[2];
}

void Model_Scale(Mesh *m, float scale[3]) {
    m->ModelMtx[0] = scale[0];
    m->ModelMtx[5] = scale[1]; 
    m->ModelMtx[10] = scale[2];
}


void Model_Rotate(Model *model, float direction){
    // Models are only able to rotate around the Y-axis, so
    // direction indicates clockwise or counter-clockwise rotation.
    switch ((int)direction) {
        case 1: // Clockwise
            direction = 1.0f;
            break;
        case -1: // Counter-clockwise
            direction = -1.0f;
            break;
        default:
            return; // Invalid direction, do nothing
    }

    float angle = direction * 0.01f; // Adjust rotation speed as needed
    float cosAngle = 0;
    float sinAngle = 0;
    model->CurrentMtx[0]  *=   cosAngle;
    model->CurrentMtx[2]  *=  -sinAngle;
    model->CurrentMtx[8]  *=   sinAngle;
    model->CurrentMtx[10] *=   cosAngle;
    

}