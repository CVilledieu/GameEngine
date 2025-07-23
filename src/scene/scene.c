#include "model.h"
#include <stdlib.h>
#include "scene.h"
#include "camera.h"

#define MAX_MODEL_COUNT 10 // Define a maximum number of models in a scene



static float SceneMtx[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
};


Scene Scene_Create(int id, float OriginVector[3]) {
    Scene scene;
    scene.id = id;
    scene.modelCount = 0;
    scene.models = malloc(sizeof(Model) * MAX_MODEL_COUNT); // Initialize models to NULL
    
    scene.OriginMtx = malloc(sizeof(float) * 16);
    memcpy(scene.OriginMtx, SceneMtx, sizeof(float) * 16);
    scene.OriginMtx[3] = OriginVector[0];
    scene.OriginMtx[7] = OriginVector[1];
    scene.OriginMtx[11] = OriginVector[2];
    return scene;
}




void Scene_AddModel(Scene *scene, MeshType type){
    if (scene->modelCount >= MAX_MODEL_COUNT) {
        return;
    }
    Model model = Model_Create(type, scene->modelCount);
    scene->models[scene->modelCount] = model;
    scene->modelCount++;

}

//====================
// Rendering
// 

// Prepares the scene for rendering by performing necessary updates that do not need to be done every frame.
void Scene_Load(Scene *scene){
    Camera_Init();
}

void Scene_Render(Scene *scene) {
    
    for (int index = 0; index < scene->modelCount; index++) {
        Model *model = &scene->models[index];
        if (model->mesh != NULL) {
            Model_Draw(model); 
        }
    }
}


void Scene_UpdateOrigin(Scene *scene, float translation[3]){
    scene->OriginMtx[3] += translation[0];
    scene->OriginMtx[7] += translation[1];
    scene->OriginMtx[11] += translation[2];
}
