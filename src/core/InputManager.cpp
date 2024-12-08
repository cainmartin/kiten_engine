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
}

bool InputManager::is_key_pressed(Key key)
{
    auto it = m_current_key_states.find(key);
    return it != m_current_key_states.end() && it->second;
}

bool InputManager::is_key_just_pressed(Key key)
{
    auto current = m_current_key_states.find(key);
    auto previous = m_previous_key_states.find(key);

    return current != m_current_key_states.end() && current->second &&
            (previous == m_previous_key_states.end() || !previous->second);
}

bool InputManager::is_key_just_released(Key key)
{
    auto current = m_current_key_states.find(key);
    auto previous = m_previous_key_states.find(key);

    return previous != m_previous_key_states.end() && previous->second &&
            (current != m_current_key_states.end() || !current->second);
}

bool InputManager::is_mouse_button_down(MouseButton button)
{

}

glm::vec2 InputManager::get_mouse_position() const
{

}

glm::vec2 InputManager::get_mouse_delta() const
{

}

void InputManager::set_glfw_window(GLFWwindow* window)
{
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
        case GLFW_KEY_SPACE: return Key::Space;
        case GLFW_KEY_ESCAPE: return Key::Esc;
        default: return Key::Unknown;
    }
}