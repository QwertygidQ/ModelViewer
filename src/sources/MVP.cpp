#include "../headers/MVP.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

MVP::MVP(const Shader &shader, float aspect_ratio) :
    shader(shader),
    z_dist(-5.0f),
    model(glm::mat4(1.0f)),
    projection(glm::perspective(glm::radians(45.0f), aspect_ratio, 0.1f, 100.0f))
{
    update_view();
}

void MVP::apply()
{
    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
}

void MVP::handle_mouse_scroll(float yoffset)
{
    const float sensitivity = 0.1f;
    yoffset *= sensitivity;

    z_dist = std::clamp(z_dist + yoffset, -50.0f, 0.0f);
    update_view();
}

void MVP::update_view()
{
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, z_dist), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}