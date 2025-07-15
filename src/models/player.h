#ifndef PLAYER_H
#define PLAYER_H

#include "primative.h"



Mesh Player_InitMesh(void);
void DrawPlayer(Mesh *mesh);

void Player_Controls(int key, int action);

#endif