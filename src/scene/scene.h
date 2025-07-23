#ifndef SCENE_H
#define SCENE_H

#include "model.h"


// Future Notes:
// Will need to create SceneManager to handle multiple scenes, scene transitions, and scene states.
// Possibly create new properties, for active models, world objects, and scene-specific data.
// Scene-specific data could include lighting, camera settings, and other environmental factors.
//
// OriginMtx will need to be worked into ModelMtx, so that models can be positioned relative to the scene's origin rather than the world origin.
typedef struct {
    int id;
    int modelCount; // Number of models in the scene
    float *OriginMtx; // Matrix for origin position and scale
    Model *models;
    
} Scene;



#endif