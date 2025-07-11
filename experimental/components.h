#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <glm/vec3.hpp>


class Texture
{
    public:
        int width;
        int height;
        int nChannels;
        unsigned char* data;
};

class Mesh
{
    int arrSize;
    int* testArray;
    //Texture texture;

    public:
        Mesh(){}
        Mesh(int* arr, int size)
        {
            this->arrSize = size;
            testArray = arr;
        }

        void ArrayAssign(int n)
        {
            testArray[0] = n;
        }

        void PrintArray()
        {
            for (int i = 0; i < arrSize; i++)
            {
                std::cout << testArray[i] << ", ";
            }
            std::cout << std::endl;
        }

};

class MultiMesh
{
    public:
        Mesh mesh;
        glm::vec3 transforms[];
};

struct PlaneMesh
{
    float vertices[30] =
    {
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,     //bot left
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,     //bot right
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     //top right

         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     //top right
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,     //bot left
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f      //top left
    };
};

#endif