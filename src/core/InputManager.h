//
// Created by Cain Martin on 2024/12/09.
//

#ifndef KITEN_ENGINE_INPUTMANAGER_H
#define KITEN_ENGINE_INPUTMANAGER_H

#include <map>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class Key
{
    W,
    A,
    S,
    D,
    E,
    Q,
    Space,
    Esc,
    Unknown
};

enum class MouseButton
{
    Left,
    Middle,
    Right,
    Unknown
};

class InputManager
{
public:
    InputManager();
    ~InputManager() = default;

    void update();

    bool is_key_pressed(Key key) const;
    bool is_key_just_pressed(Key key) const;
    bool is_key_just_released(Key key) const;
    bool is_mouse_button_down(MouseButton button) const;
    glm::vec2 get_mouse_position() const;
    glm::vec2 get_mouse_delta() const;

    void set_glfw_window(GLFWwindow* window);

private:
    std::unordered_map<Key, bool> m_current_key_states;
    std::unordered_map<Key, bool> m_previous_key_states;

    GLFWwindow* m_window;

    Key map_glfw_key(GLuint key) const;
    glm::vec2 m_last_mouse_position;
    glm::vec2 m_mouse_delta;

    bool m_is_first_run;
};


#endif //KITEN_ENGINE_INPUTMANAGER_H
