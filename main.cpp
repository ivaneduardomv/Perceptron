#include <iostream>

#include "MyDefines.h"

#include "Perceptron.h"
#include "Layer.h"
#include "Trainers.h"

using namespace std;

int main(int argc, char *argv[])
{
    Layer l1;
    Perceptron p_xor;

    float in_data_xor[][N] = {{0,0},
                              {0,1},
                              {1,0},
                              {1,1}};
    float out_data_xor[] = {0,
                            0,
                            0,
                            1,};

    cout << "--------------------------------------------------Initial states" << endl;
    l1.To_JSON();
    p_xor.To_JSON();
    cout << endl;
    cout << "------------------------------------------------------------" << endl;

    if(Train_Layer(l1, p_xor, in_data_xor, out_data_xor))
    {
        cout << "Training success!" << endl;
    }
    else
    {
        cout << "Training failure!" << endl;
    }

    cout << "--------------------------------------------------Final states" << endl;
    l1.To_JSON();
    p_xor.To_JSON();
    cout << endl;
    cout << "------------------------------------------------------------" << endl;

    return 0;
}
