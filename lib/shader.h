#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

/*
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
*/


class Shader
{
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath)
        {
            char* vertexShaderCode;
            char* fragmentShaderCode;

            vertexShaderCode = getShaderContent(vertexPath);
            fragmentShaderCode = getShaderContent(fragmentPath);

            /* C++ style read - ran into c string compat issue
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vertexShaderFile;
            std::ifstream fragmentShaderFile;

            // ensure ifstream can throw exceptions
            vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try
            {
                vertexShaderFile.open(vertexPath);
                fragmentShaderFile.open(fragmentPath);

                std::stringstream vShaderStream, fShaderStream;
                vShaderStream << vertexShaderFile.rdbuf();
                fShaderStream << fragmentShaderFile.rdbuf();

                vertexShaderFile.close();
                fragmentShaderFile.close();

                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch(std::ifstream::failure& e)
            {
                std::cout << "ERROR::SHADER::FILE_READ_UNSUCCESSFULL: " << e.what() << std::endl;
            }

            const char* vertexShaderCode = vertexCode.c_str();
            const char* fragmentShaderCode = fragmentCode.c_str();

            */

            unsigned int vertex, fragment;
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vertexShaderCode, NULL);
            glCompileShader(vertex);
            checkCompileErrors(vertex, "VERTEX");

            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fragmentShaderCode, NULL);
            glCompileShader(fragment);
            checkCompileErrors(fragment, "FRAGMENT");

            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            checkCompileErrors(ID, "PROGRAM");

            glDeleteShader(vertex);
            glDeleteShader(fragment);

        }

        void use()
        {
            glUseProgram(ID);
        }

        void setBool(const std::string &name, bool value)
        {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
        }

        void setInt(const std::string &name, int value)
        {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        }

        void setFloat(const std::string &name, float value)
        {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        }


    private:
        
        void checkCompileErrors(unsigned int shader, std::string type)
        {
            int success;
            char infoLog[1024];
            if (type != "PROGRAM")
            {
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if (!success)
                {
                    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
            else
            {
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if (!success)
                {
                    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }

        char* getShaderContent(const char* fileName)
        {
            FILE *fp;
            long size = 0;
            void* shaderContent;
            
            /* Read File to get size */
            fp = fopen(fileName, "rb");
            if(fp == NULL) {
                return "";
            }
            fseek(fp, 0L, SEEK_END);
            size = ftell(fp)+1;
            fclose(fp);

            /* Read File for Content */
            fp = fopen(fileName, "r");
            shaderContent = memset(malloc(size), '\0', size);
            fread(shaderContent, 1, size-1, fp);
            fclose(fp);

            return (char*)shaderContent;
        }
};

#endif