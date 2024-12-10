//
// Created by Cain Martin on 2024/12/06.
//

#ifndef KITEN_ENGINE_CAMERA_H
#define KITEN_ENGINE_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "../core/InputManager.h"

class Camera
{
public:
    Camera(const glm::vec3& position, float pitch, float yaw, float fov, float aspect, float near, float far);

    void process_input(const InputManager& input_manager, float delta_time);

    void set_position(const glm::vec3& position);
    void set_look_at(const glm::vec3& target);
    void move_forward(float delta);
    void move_up(float delta);
    void move_right(float delta);
    void update();
    [[nodiscard]] glm::mat4 get_view_matrix() const;
    [[nodiscard]] glm::mat4 get_projection_matrix() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_right;
    glm::vec3 m_up;
    float m_fov;
    float m_ratio;
    float m_pitch;
    float m_yaw;
    float m_near;
    float m_far;

    glm::mat4 m_view_matrix;
    glm::mat4 m_projection_matrix;

    void update_camera_vectors();
};


#endif //KITEN_ENGINE_CAMERA_H
