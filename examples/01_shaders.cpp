#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// VERTEX SHADER
const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";

// FRAGMENT SHADER
const char *fragmentShaderSource = 
    "#version 330 core\n"
    "in vec3 ourColor;\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0);\n"
    "}\0";


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



int main(int, char**){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Get number of possible vertex attributes
    // will be at least 16, but gpu might support more
    /*
    int noAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &noAttributes);
    std::cout << "Maximum number of vertex attributes supported: " << noAttributes << std::endl;
    */


    // Compiling vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    
    // Check if vertex shader compilation failed and output error log
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPLATION_FAILED\n" << infoLog << std::endl;
    }

    // Compiling fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Creating shader program and linking shaders
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check fragment shader compilation
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        std::cout << "ERROR::SHADER::FRAGMENT::COMPLATION_FAILED\n" << infoLog << std::endl;
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    }

    // Check if linking failed
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }

    // Shaders not needed after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // VERTICE DATA
    float vertices[] = {
        // pos
        0.5f,  -0.5f,  0.0f,    1.0f, 0.0f, 0.0f,
       -0.5f,  -0.5f,  0.0f,    0.0f, 1.0f, 0.0f,
        0.0f,   0.5f,  0.0f,    0.0f, 0.0f, 1.0f
    };

    // Storing vertex data in GPU buffer
    unsigned int VBO, VAO; //vertex buffer obj, vertex array obj, element buffer obj
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // colour
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // can unbind after glVertexAttribPointer registered VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Draw wireframe
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Can be set to default using:
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //float timeValue = glfwGetTime();
        //float greenValue = (sin(timeValue) / 2.0f) + 0.5;
        //int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor"); //returns -1 on failure
        glUseProgram(shaderProgram);
        //glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f); // works only on active shader program

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


// glfw: called on window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}