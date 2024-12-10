//
// Created by Cain Martin on 2024/12/06.
//

#include "Camera.h"


Camera::Camera(const glm::vec3& position, float pitch, float yaw, float fov, float aspect, float near, float far)
: m_position(position)
, m_pitch(pitch)
, m_yaw(yaw)
, m_fov(fov)
, m_ratio(aspect)
, m_near(near)
, m_far(far)
{
    m_up = glm::vec3(0.0, 1.0, 0.0);
    update_camera_vectors();
    update();
}

void Camera::process_input(const InputManager& input_manager, float delta_time)
{
    const float speed = 5.0f * delta_time;
    const float sensitivity = 0.1f;

    if (input_manager.is_key_pressed(Key::W))
    {
        move_forward(speed);
    }
    if (input_manager.is_key_pressed(Key::S))
    {
        move_forward(-speed);
    }
    if (input_manager.is_key_pressed(Key::A))
    {
        move_right(-speed);
    }
    if (input_manager.is_key_pressed(Key::D))
    {
        move_right(speed);
    }
    if (input_manager.is_key_pressed(Key::E))
    {
        move_up(speed);
    }
    if (input_manager.is_key_pressed(Key::Q))
    {
        move_up(-speed);
    }

    auto mouse_delta = input_manager.get_mouse_delta();
    m_yaw += mouse_delta.x * sensitivity;
    m_pitch -= mouse_delta.y * sensitivity;

    if (m_pitch > 89.0f) m_pitch = 89.0f;
    if (m_pitch < -89.0f) m_pitch = -89.0f;

    update_camera_vectors();
    update();
}

void Camera::set_position(const glm::vec3& position)
{
    m_position = position;
    update();
}

void Camera::set_look_at(const glm::vec3& target)
{
    m_forward = glm::normalize(target - m_position);
    m_right = glm::normalize(glm::cross(m_forward, glm::vec3(0.0, 1.0, 0.0)));
    m_up = glm::normalize(glm::cross(m_right, m_forward));
    update();
}

void Camera::move_forward(float delta)
{
    m_position += m_forward * delta;
    update();
}

void Camera::move_up(float delta)
{
    m_position += m_up * delta;
    update();
}

void Camera::move_right(float delta)
{
    m_position += m_right * delta;
    update();
}

void Camera::update()
{
    m_view_matrix = glm::lookAt(m_position, m_position + m_forward, m_up);
    m_projection_matrix = glm::perspective(glm::radians(m_fov), m_ratio, m_near, m_far);
}

void Camera::update_camera_vectors()
{
    glm::vec3 forward;
    forward.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    forward.y = sin(glm::radians(m_pitch));
    forward.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

    m_forward = glm::normalize(forward);

    m_right = glm::normalize(glm::cross(m_forward, glm::vec3(0.0, 1.0, 0.0)));
    m_up = glm::normalize(glm::cross(m_right, m_forward));
}

glm::mat4 Camera::get_view_matrix() const
{
    return m_view_matrix;
}

glm::mat4 Camera::get_projection_matrix() const
{
    return m_projection_matrix;
}