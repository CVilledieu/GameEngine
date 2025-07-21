#include "model.h"


typedef struct {
    Model Ground;
    Model playerModel;
    Model *objects;
    int modelCount; 

} State;