#include <stdlib.h>
#include "mesh.h"


typedef struct {
    Mesh *Ground;
    Mesh *Sky;
    Mesh *Backgound;

} World;


World World_Create() {
    World world;
    world.Ground = malloc(sizeof(Mesh));
    *world.Ground = Square_CreateMesh();
    // Set initial position
    world.Ground->ModelMtx[12] = 0.0f; 
    world.Ground->ModelMtx[13] = -0.5f; 
    
    world.Sky = malloc(sizeof(Mesh));
    *world.Sky = Square_CreateMesh();
    
    world.Backgound = malloc(sizeof(Mesh));
    *world.Backgound = Square_CreateMesh();

    return world;
}

void World_Init_Floor(Mesh *mesh) {
    mesh->ModelMtx[12] = 0.0f; 
    mesh->ModelMtx[13] = -0.5f; 
}

void World_Init_Sky(Mesh *mesh) {
    mesh->ModelMtx[12] = 0.0f; 
    mesh->ModelMtx[13] = 0.5f; 
}

void World_Init_Background(Mesh *mesh) {
    mesh->ModelMtx[12] = 0.0f; 
    mesh->ModelMtx[13] = 0.0f; 
}


void World_Update_Floor(){}

void World_Update_Sky(){

}
void World_Update_Background() {
    // Update logic for the world meshes can be added here
}

void World_Draw(World *world) {
    DrawMesh(world->Ground);
    DrawMesh(world->Sky);
    DrawMesh(world->Backgound);
}