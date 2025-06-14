#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int, char**){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to intialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        // Keyword double buffer
        glfwSwapBuffers(window);
        // Check events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
