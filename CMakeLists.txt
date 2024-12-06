cmake_minimum_required(VERSION 3.27)
project(kiten_engine)

set(CMAKE_CXX_STANDARD 23)

add_library(glad STATIC vendor/glad/src/glad.c)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)
target_include_directories(glad PUBLIC vendor/glad/include)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE vendor/glm)
target_compile_definitions(glm INTERFACE GLM_ENABLE_EXPERIMENTAL GLM_FORCE_RADIANS)

add_subdirectory(vendor/glfw)

add_executable(${PROJECT_NAME}
        main.cpp
        src/core/ResourceManager.cpp
        src/scene/Transform.cpp
        src/platform/Window.cpp
        src/renderer/Renderer.cpp
        src/renderer/Shader.cpp
        src/Application.cpp
)

# Link dependencies
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)

    # Link Mac-specific frameworks along with OpenGL and other libraries
    target_link_libraries(${PROJECT_NAME} PRIVATE
            glad
            glfw
            glm
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
            ${CORE_FOUNDATION_LIBRARY}
            ${OPENGL_LIBRARY}
    )
elseif(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
            glad
            glfw
            glm
            opengl32
    )
else()

    # Fallback for non-Mac systems
    target_link_libraries(${PROJECT_NAME} PRIVATE
            glad
            glfw
            glm
            OpenGL::GL
    )
endif()