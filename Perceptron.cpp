#include "Perceptron.h"

Perceptron::Perceptron()
{
    std::string str;
    std::cout << "Please, enter a seed: ";
    std::getline(std::cin,str);
    std::seed_seq seed1 (str.begin(),str.end());

    std::uniform_real_distribution<float> uniform_distribution(-1.0, 1.0);
    std::mt19937 generator(seed1);

    this->num_of_inputs  = N;
    this->bias = uniform_distribution(generator);
    this->weights = new float[num_of_inputs];
    for(size_t i = 0; i < num_of_inputs; ++i)
    {
        this->weights[i] = uniform_distribution(generator);
    }
}

Perceptron::Perceptron(size_t number_of_inputs, float init_bias, float init_weights[])
{
    this->num_of_inputs  = number_of_inputs;
    this->bias = init_bias;
    this->weights = new float[num_of_inputs];
    for(size_t i = 0; i < num_of_inputs; ++i)
    {
        this->weights[i] = init_weights[i];
    }
}

Perceptron::~Perceptron()
{
    delete[] this->weights;
}

float Perceptron::Output(const float input[])
{
    float weighted_sum = this->bias;
    for(size_t i = 0; i < num_of_inputs; ++i)
    {
        weighted_sum += this->weights[i] * input[i];
    }
    return this->Act_Func(weighted_sum);
}

float Perceptron::Get_Bias(void)
{
    return this->bias;
}
float Perceptron::Get_Weight_At(size_t index)
{
    return this->weights[index];
}

size_t Perceptron::Get_Num_Of_Inputs(void)
{
    return this->num_of_inputs;
}

void Perceptron::Set_Bias(float new_bias)
{
    this->bias = new_bias;
}

void Perceptron::Set_Weight_At(size_t index, float new_weight)
{
    this->weights[index] = new_weight;
}

void Perceptron::To_JSON(void)
{
    cout << "Perceptron = {";
    cout << "\"num_of_inputs\":" << this->num_of_inputs << ",";
    cout << "\"bias\":" << this->bias << ",";
    cout << "\"weights\":[";
    for(size_t i = 0; i < this->num_of_inputs; ++i)
    {
        cout << this->weights[i];
        if(i < num_of_inputs - 1)
        {
            cout << ",";
        }
    }
    cout << "]}";
}

float Perceptron::Act_Func(float weighted_sum)
{
    float output = 0.0;
    if(weighted_sum > 0.0) output = 1.0;

    return output;
}
