#include "../headers/Window.hpp"

#include <stdexcept>

void terminate(const std::string &error)
{
    glfwTerminate();
    throw std::runtime_error(error);
}

Window::Window(int win_width, int win_height, const std::string &win_title) : width(win_width), height(win_height)
{
    if (!glfwInit())
        terminate("Failed to initialize GLFW");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ptr = glfwCreateWindow(win_width, win_height, win_title.c_str(), nullptr, nullptr);
    if (!window_ptr)
        terminate("Failed to create a window");

    glfwMakeContextCurrent(window_ptr);

    glfwSetWindowUserPointer(window_ptr, this);
    glfwSetFramebufferSizeCallback(window_ptr, framebuffer_size_callback);
}

Window::~Window()
{
    glfwTerminate();
}

void Window::framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height)
{
    glViewport(0, 0, new_width, new_height);

    Window *this_ptr = (Window*)glfwGetWindowUserPointer(window);
    this_ptr->width = new_width;
    this_ptr->height = new_height;
}