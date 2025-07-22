#include "model.h"
#include <stdlib.h>
#include "scene.h"

#define MAX_MODEL_COUNT 10 // Define a maximum number of models in a scene



Scene Scene_Create(int id) {
    Scene scene;
    scene.id = id;
    scene.modelCount = 0;
    scene.models = malloc(sizeof(Model) * MAX_MODEL_COUNT); // Initialize models to NULL
    
    scene.OriginMtx = malloc(sizeof(float) * 16);
    

}