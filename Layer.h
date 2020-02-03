#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "MyDefines.h"

#include "Perceptron.h"

class Layer
{
public:
    Layer();
    ~Layer();

    void Feed(const float[]);
    const float *Get_Output(void);

    void To_JSON(void);

    Perceptron *p_array;
    float *output;
};

#endif // LAYER_H_INCLUDED
