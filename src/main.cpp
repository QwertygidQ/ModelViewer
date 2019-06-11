#include <cstdlib>
#include <string>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "libraries/stb_image.h"

void initialize_stbi()
{
    stbi_set_flip_vertically_on_load(true);
}

void terminate(const std::string &error)
{
    std::cerr << "Error: " << error << std::endl;
    glfwTerminate();
}

GLFWwindow* initialize_glfw(int win_width, int win_height, const std::string &win_title)
{
    if (!glfwInit())
    {
        terminate("Failed to initialize GLFW");
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow *window = glfwCreateWindow(win_width, win_height, win_title.c_str(), nullptr, nullptr);
    if (!window)
    {
        terminate("Failed to create a window");
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    return window;
}

bool initialize_glad()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        terminate("Failed to initialize GLAD");
        return false;
    }

    return true;
}

int main()
{
    initialize_stbi();
    GLFWwindow *window = initialize_glfw(800, 600, "Model viewer");
    if (!window || !initialize_glad())
        return EXIT_FAILURE;

    // Everything goes here

    glfwTerminate();
    return EXIT_SUCCESS;
}