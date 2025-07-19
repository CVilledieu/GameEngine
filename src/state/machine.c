#include "camera.h"



typedef struct SM_Controller{

} SM_Controller;

typedef struct {
    struct SM_Controller Controller;

} SM_Context;

struct SM_Context SM_Context;
struct SM_Controller SM_Controller;


void SM_LoadContext() {
    // Load the context for the state machine
}

void SM_Init() {
    // Initialize the state machine
}


void SM_Draw() {
    View_Set();
}

