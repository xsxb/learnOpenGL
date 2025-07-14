#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <vector>
#include <glm/vec3.hpp>

class Texture
{
    private:
        int width;
        int height;
        int nChannels;
        unsigned char* data;

    public:
        Texture() {}
        Texture(unsigned char* data, int width, int height, int nChannels)
        {
            this->data = data;
            this->width = width;
            this->height = height;
            this-> nChannels = nChannels;
        }
};

class UV
{
    public:
        std::vector<float> data;

        UV() {}
        UV(std::vector<float> data)
        {
            this->data = data;
        }

};

class Mesh
{
    std::vector<float> vertexData;
    //UV uv;
    //Texture texture;

    public:
        Mesh(){}
        Mesh(std::vector<float> vertexPos)
        {
            this->vertexData = vertexPos;
        }

        int CreateBuffer(float* bufferData, int bufferSize)
        {
            //ApplyUV(uv);

            return 0;
        }

        void PrintArray()
        {
            for (int i = 0; i < vertexData.size(); i++)
            {
                std::cout << vertexData[i] << ", ";
            }
            std::cout << std::endl;
        }

    private:
        /* not implemented 
        int ApplyUV(UV uv, int stride = 3, int offset = 3)
        {
            if (uv.GetSize() != vertexDataSize)
                throw std::length_error("UV vertex data length error");

            return 0;
        }
        */

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