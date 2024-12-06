//
// Created by Cain Martin on 2024/12/06.
//

#ifndef KITEN_ENGINE_TRANSFORM_H
#define KITEN_ENGINE_TRANSFORM_H

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

class Transform
{
public:
    Transform();

    void set_position(const glm::vec3& position);
    void set_rotation(const glm::quat& rotation);
    void set_scale(const glm::vec3& scale);

    glm::vec3 get_position() const;
    glm::quat get_rotation() const;
    glm::vec3 get_scale() const;

    glm::mat4 get_matrix();

private:
    glm::vec3 m_position;
    glm::quat m_rotation;
    glm::vec3 m_scale;

    glm::mat4 m_matrix;

    bool m_dirty = false;
};


#endif //KITEN_ENGINE_TRANSFORM_H
