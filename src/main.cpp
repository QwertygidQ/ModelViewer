#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "libraries/stb_image.h"

#include "headers/Window.hpp"
#include "headers/Shader.hpp"
#include "headers/Texture.hpp"
#include "headers/Model.hpp"

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

        glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), window.width / (float)window.height, 0.1f, 100.0f);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        Texture texture("uvmap.jpg");
        texture.use();

        Model test("test_obj.obj");

        while(!glfwWindowShouldClose(window.window_ptr))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glm::mat4 model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime() * glm::radians(10.0f), glm::vec3(1.0f, 1.0f, 0.0f));
            shader.setMat4("model", model);

            glBindVertexArray(test.VAO);
            glDrawArrays(GL_TRIANGLES, 0, test.faces.size() * 3);
            glBindVertexArray(0);

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