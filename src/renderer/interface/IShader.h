//
// Created by Cain Martin on 2024/12/04.
//

#ifndef KITEN_ENGINE_ISHADER_H
#define KITEN_ENGINE_ISHADER_H

class IShader
{
public:
    virtual ~IShader() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;
};

#endif //KITEN_ENGINE_ISHADER_H
