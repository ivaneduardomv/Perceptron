#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

#include <iostream>
#include <random>
#include <chrono>

#include "MyDefines.h"

using namespace std;

typedef std::chrono::high_resolution_clock myclock;

class Perceptron
{
public:
    Perceptron();
    Perceptron(size_t, float, float[]);
    ~Perceptron();

    float Output(const float[]);

    float Get_Bias(void);
    float Get_Weight_At(unsigned int);
    unsigned int Get_Num_Of_Inputs(void);

    void Set_Bias(float);
    void Set_Weight_At(size_t, float);

    void To_JSON(void);

private:
    size_t num_of_inputs;
    float bias;
    float *weights;

    float Act_Func(float);
};

#endif // PERCEPTRON_H_INCLUDED
