//
// Created by Cain Martin on 2024/12/09.
//

#include "InputManager.h"

InputManager::InputManager()
: m_window(nullptr)
{
}

void InputManager::update()
{
    m_previous_key_states = m_current_key_states;

    for (int glfw_key = GLFW_KEY_SPACE; glfw_key <= GLFW_KEY_LAST; glfw_key++)
    {
        Key key = map_glfw_key(glfw_key);
        if (key != Key::Unknown)
        {
            m_current_key_states[key] = glfwGetKey(m_window, glfw_key) == GLFW_PRESS;
        }
    }

    double x, y;
    glfwGetCursorPos(m_window, &x, &y);
    glm::vec2 current_mouse_position = { x, y };
    m_mouse_delta = current_mouse_position - m_last_mouse_position;
    m_last_mouse_position = current_mouse_position;
}

bool InputManager::is_key_pressed(Key key) const
{
    auto it = m_current_key_states.find(key);
    return it != m_current_key_states.end() && it->second;
}

bool InputManager::is_key_just_pressed(Key key) const
{
    auto current = m_current_key_states.find(key);
    auto previous = m_previous_key_states.find(key);

    return current != m_current_key_states.end() && current->second &&
            (previous == m_previous_key_states.end() || !previous->second);
}

bool InputManager::is_key_just_released(Key key) const
{
    auto current = m_current_key_states.find(key);
    auto previous = m_previous_key_states.find(key);

    return previous != m_previous_key_states.end() && previous->second &&
            (current != m_current_key_states.end() || !current->second);
}

bool InputManager::is_mouse_button_down(MouseButton button) const
{
    int glfwButton;

    switch(button)
    {
        case MouseButton::Left: glfwButton = GLFW_MOUSE_BUTTON_LEFT; break;
        case MouseButton::Right: glfwButton = GLFW_MOUSE_BUTTON_RIGHT; break;
        case MouseButton::Middle: glfwButton = GLFW_MOUSE_BUTTON_MIDDLE; break;
        default: return false;
    }

    return glfwGetMouseButton(m_window, glfwButton) == GLFW_PRESS;
}

glm::vec2 InputManager::get_mouse_position() const
{
    double x, y;
    glfwGetCursorPos(m_window, &x, &y);

    return {x, y};
}

glm::vec2 InputManager::get_mouse_delta() const
{
    return m_mouse_delta;
}

void InputManager::set_glfw_window(GLFWwindow* window)
{
    assert(window && "GLFW window is null!");
    m_window = window;
}

Key InputManager::map_glfw_key(GLuint key) const
{
    switch(key)
    {
        case GLFW_KEY_A: return Key::A;
        case GLFW_KEY_W: return Key::W;
        case GLFW_KEY_D: return Key::D;
        case GLFW_KEY_S: return Key::S;
        case GLFW_KEY_E: return Key::E;
        case GLFW_KEY_Q: return Key::Q;
        case GLFW_KEY_SPACE: return Key::Space;
        case GLFW_KEY_ESCAPE: return Key::Esc;
        default: return Key::Unknown;
    }
}