#include "../headers/Model.hpp"

#include <glad/glad.h>

Model::Model(const std::vector<float> &data) : vertex_data(data)
{
    float *raw_data = vertex_data.data();

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(VBO, vertex_data.size() * sizeof(float), raw_data, GL_STATIC_DRAW);

    const int num_floats_per_vertex = 3; // TODO: add textures
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, num_floats_per_vertex * sizeof(float), (void*)0); // position
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}