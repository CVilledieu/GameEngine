#ifndef PLAYER_H
#define PLAYER_H

#include "mesh.h"

extern Mesh Player;

void Player_Init(void);
Mesh Player_InitMesh(void);
void DrawPlayer(Mesh *mesh);



#endif