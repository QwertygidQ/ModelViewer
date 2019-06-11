#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "libraries/stb_image.h"

#include "headers/Window.hpp"

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

        while(!glfwWindowShouldClose(window.window_ptr))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window.window_ptr);
            glfwPollEvents();
        }

        return EXIT_SUCCESS;
    }
    catch(const std::runtime_error &err)
    {
        std::cerr << "Exception caught: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }
}