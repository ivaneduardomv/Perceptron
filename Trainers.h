#ifndef TRAINERS_H_INCLUDED
#define TRAINERS_H_INCLUDED

#include "MyDefines.h"

#include "Perceptron.h"
#include "Layer.h"

bool Train_Perceptron(Perceptron&, float[][N], float[]);

bool Train_Layer(Layer&, Perceptron&, float[][N], float[]);

#endif // TRAINERS_H_INCLUDED
