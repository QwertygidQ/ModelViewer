#ifndef MVP_HPP
#define MVP_HPP

#include <glm/glm.hpp>
#include "Shader.hpp"

struct MVP
{
    MVP(const Shader &shader, float aspect_ratio);
    void apply();

    void handle_mouse_scroll(float yoffset);

    const Shader &shader;
    glm::mat4 model, view, projection;
    float z_dist, yaw, pitch;

private:
    void update_view();
};

#endif