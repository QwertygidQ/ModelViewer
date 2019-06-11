#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#include <string>

struct Window
{
    Window(int win_width, int win_height, const std::string &win_title);
    ~Window();

    int width, height;
    GLFWwindow *window_ptr;
private:
    static void framebuffer_size_callback(GLFWwindow *window, int new_width, int new_height);
};

#endif