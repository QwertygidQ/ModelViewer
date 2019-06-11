#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

struct Model
{
    Model(const std::vector<float> &data);

    unsigned int VAO;
    std::vector<float> vertex_data;
};

#endif