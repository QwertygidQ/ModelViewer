#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "libraries/stb_image.h"

#include "headers/Window.hpp"
#include "headers/Shader.hpp"
#include "headers/Texture.hpp"
#include "headers/Model.hpp"
#include "headers/MVP.hpp"

void initialize_stbi()
{
    stbi_set_flip_vertically_on_load(true);
}

void initialize_glad()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");
}

void initialize_gl(int viewport_width, int viewport_height)
{
    glViewport(0, 0, viewport_width, viewport_height);
    glEnable(GL_DEPTH_TEST);
}

int main()
{
    try
    {
        const int width = 800, height = 600;

        initialize_stbi();
        Window window(width, height, "Model viewer");
        initialize_glad();
        initialize_gl(width, height);

        Shader shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");
        shader.use();

        Texture texture("uvmap.jpg");
        texture.use();

        Model test("test_obj.obj");
        MVP mvp(shader, width / (float)height, 2.0f);

        while(!glfwWindowShouldClose(window.window_ptr))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            mvp.apply();
            test.draw();

            glfwSwapBuffers(window.window_ptr);
            glfwPollEvents();
        }

        return EXIT_SUCCESS;
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << "Exception caught: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }
}