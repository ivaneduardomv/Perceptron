#include "Trainers.h"

bool Train_Perceptron(Perceptron &p, float input[][N], float expected_out[])
{
    bool is_training_succes = false;

    unsigned int error_count = 0;
    unsigned int iterations = 0;
    float learn_factor = 0.1;

    do
    {
        error_count = 0;
        for(unsigned int i = 0; i < 4; ++i)
        {
            float computed_out = p.Output(input[i]);
            float error = expected_out[i] - computed_out;
            if(expected_out[i] != computed_out)
                ++error_count;

            float current_bias = p.Get_Bias();
            float new_bias = current_bias + learn_factor * error;
            p.Set_Bias(new_bias);

            for(unsigned int j = 0; j < p.Get_Num_Of_Inputs(); ++j)
            {
                float current_weight = p.Get_Weight_At(j);
                float new_weight = current_weight + learn_factor * error * input[i][j];
                p.Set_Weight_At(j, new_weight);
            }
        }
        ++iterations;
    }while(error_count != 0 && iterations < 10000);


    if(iterations < 10000) is_training_succes = true;

    return is_training_succes;
}

bool Train_Layer(Layer &layer, Perceptron &p, float input[][N], float expected_out[])
{
    bool is_training_succes = false;

    unsigned int error_count = 0;
    unsigned int iterations = 0;
    float learn_factor = 0.1;

    do
    {
        error_count = 0;
        for(unsigned int i = 0; i < 4; ++i)
        {
            layer.Feed(input[i]);
            const float *out_layer = layer.Get_Output();

            float computed_out = p.Output(out_layer);
            float error = expected_out[i] - computed_out;
            if(expected_out[i] != computed_out)
                ++error_count;

            float current_bias = p.Get_Bias();
            float new_bias = current_bias + learn_factor * (error/4.0f);
            p.Set_Bias(new_bias);

            for(unsigned int j = 0; j < p.Get_Num_Of_Inputs(); ++j)
            {
                float current_weight = p.Get_Weight_At(j);
                float new_weight = current_weight + learn_factor * (error/4.0f) * input[i][j];
                p.Set_Weight_At(j, new_weight);
            }

            for(unsigned int k = 0; k < M; ++k)
            {
                float current_bias = layer.p_array[k].Get_Bias();
                float new_bias = current_bias + learn_factor * (error/4.0f);
                layer.p_array[k].Set_Bias(new_bias);

                unsigned int num_of_inputs = layer.p_array[k].Get_Num_Of_Inputs();
                for(unsigned int j = 0; j < num_of_inputs; ++j)
                {
                    float current_weight = layer.p_array[k].Get_Weight_At(j);
                    float new_weight = current_weight + learn_factor * (error/4.0f) * input[i][j];
                    layer.p_array[k].Set_Weight_At(j, new_weight);
                }
            }
        }
        ++iterations;

        cout << "--------------------------------------------------iteracion #" << iterations << endl;
        layer.To_JSON();
        p.To_JSON();
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
    }while(error_count != 0 && iterations < 100);


    if(iterations < 100) is_training_succes = true;

    return is_training_succes;
}
