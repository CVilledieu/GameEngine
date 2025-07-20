#ifndef CAMERA_H
#define CAMERA_H


// Sets View and Projection Matrices
// Called before rendering
void Camera_Set(void);

void Camera_Init(void);

void Player_Controls(int key, int action);

#endif