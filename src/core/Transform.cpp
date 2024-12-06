//
// Created by Cain Martin on 2024/12/06.
//

#include "Transform.h"

Transform::Transform()
: m_position(glm::vec3(0.0, 0.0, 0.0))
, m_rotation(glm::quat(1.0, 0.0, 0.0, 0.0))
, m_scale(glm::vec3(1.0, 1.0, 1.0))
, m_dirty(true)
{

}

void Transform::set_position(const glm::vec3& position)
{
    m_position = position;
    m_dirty = true;
}

void Transform::set_rotation(const glm::quat& rotation)
{
    m_rotation = rotation;
    m_dirty = true;
}

void Transform::set_scale(const glm::vec3& scale)
{
    m_scale = scale;
    m_dirty = true;
}

glm::vec3 Transform::get_position() const
{
    return m_position;
}

glm::quat Transform::get_rotation() const
{
    return m_rotation;
}

glm::vec3 Transform::get_scale() const
{
    return m_scale;
}

glm::mat4 Transform::get_matrix()
{
    if (m_dirty)
    {
        glm::mat4 translation_matrix = glm::translate(glm::mat4(1.0f), m_position);
        glm::mat4 rotation_matrix = glm::mat4_cast(m_rotation);
        glm::mat4 scale_matrix = glm::scale(glm::mat4(1.0f), m_scale);

        m_matrix = translation_matrix * rotation_matrix * scale_matrix;

        m_dirty = false;
    }

    return m_matrix;
}
