#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

struct Model
{
    Model(std::vector<float> vertex_data);

    unsigned int VAO;
};

#endif