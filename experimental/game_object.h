#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "components.h"


class Transform
{
    glm::vec3 localPos = glm::vec3();
    glm::vec3 globalPos = glm::vec3();
    float rotation = 0.0f;     //radians

    public:
        Transform() {}
        Transform(glm::vec3 pos, bool isGlobal = false)
        {
            if(!isGlobal)
                localPos = pos;
                //convert here
            else
                globalPos = pos;
                //convert here
        }

        glm::vec3 LocalPos()
        {
            return localPos;
        }

        glm::vec3 GlobalPos()
        {
            return globalPos;
        }

    private:
        glm::vec3 ToGlobal(glm::vec3 pos) { return glm::vec3(); }
        glm::vec3 ToLocal(glm::vec3 pos) { return glm::vec3(); }

};


class GameObject
{

    public:
        Mesh mesh;
        Transform transform;

        GameObject() {}
        GameObject(Mesh m)
        {
            this->mesh = m;
        }
};

#endif