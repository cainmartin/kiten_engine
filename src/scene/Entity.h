//
// Created by cmartin on 2024/12/11.
//

#ifndef KITEN_ENGINE_ENTITY_H
#define KITEN_ENGINE_ENTITY_H

#include "../renderer/Mesh.h"
#include "Transform.h"

class Entity
{
public:
    explicit Entity(Mesh* mesh)
        : m_mesh(mesh)
    {}


    Transform& get_transform() { return m_transform; }
    [[nodiscard]] const Transform& get_transform() const { return m_transform; }

    void set_position(const glm::vec3& pos) { m_transform.set_position(pos); }
    void set_rotation(const glm::quat& rot) { m_transform.set_rotation(rot); }
    void set_scale(const glm::vec3& scale) { m_transform.set_position(scale); }

    void draw();

private:
    Mesh* m_mesh;
    Transform m_transform;
};


#endif //KITEN_ENGINE_ENTITY_H
