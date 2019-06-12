#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>

struct Model
{
    Model(const std::vector<float> vertex_data);
    Model(const std::string &obj_path);

    unsigned int VAO;
};

#endif