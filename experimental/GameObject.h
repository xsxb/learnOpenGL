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

        }

        glm::vec3 GlobalPos()
        {
            return globalPos;
        }

    private:
        glm::vec3 ToGlobal(glm::vec3 pos) {}
        glm::vec3 ToLocal(glm::vec3 pos) {}

};

class GameObject
{
    Mesh mesh;
    Transform transform;

    public:
        GameObject() {}
        GameObject(Mesh m)
        {
            this->mesh = m;
        }
};

#endif