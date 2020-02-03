#include "Layer.h"

Layer::Layer()
{
    p_array = new Perceptron[M];
    output = new float[M];
}

Layer::~Layer()
{
    delete[] p_array;
    delete[] output;
}

void Layer::Feed(const float input[])
{
    for(size_t i = 0; i < M; ++i)
    {
        output[i] = p_array[i].Output(input);
    }
}

 const float *Layer::Get_Output(void)
{
    return this->output;
}

void Layer::To_JSON(void)
{
    cout << "Layer = {" << endl;
    cout << "\t\"M\":" << M << "," << endl;
    cout << "\t\"p_array\":[" << endl;
    for(size_t i = 0; i < M; ++i)
    {
        cout << "\t\t";
        p_array[i].To_JSON();
        if(i < M - 1)
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "\t\t]" << endl;
    cout << "\t\"output\":[" << endl;
    for(size_t i = 0; i < M; ++i)
    {
        cout << "\t\t" << output[i];
        if(i < M - 1)
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "\t\t]" << endl;
    cout << "\t}" << endl;

}
