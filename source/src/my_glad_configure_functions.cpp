//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#include "source/headers/my_glad_configure_functions.h"
#include <iostream>
#include <GLFW/glfw3.h>

LoadOpenGLFunctionException::LoadOpenGLFunctionException()
{

}

LoadOpenGLFunctionException::LoadOpenGLFunctionException(const char *exception_message)
        : m_exception_message{exception_message}
{

}

LoadOpenGLFunctionException::LoadOpenGLFunctionException(const std::string &exception_message)
        : m_exception_message{exception_message}
{

}

LoadOpenGLFunctionException::LoadOpenGLFunctionException(const LoadOpenGLFunctionException &exception)
        : m_exception_message{exception.m_exception_message}
{

}

LoadOpenGLFunctionException::~LoadOpenGLFunctionException()
{

}

inline
const char*
LoadOpenGLFunctionException::what() const _NOEXCEPT
{
    std::cout << m_exception_message << '\n';
}



void my_glad_configure_functions::setOpenGLFunctionPointers()
{
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw LoadOpenGLFunctionException("Failed to initialize GLAD");
}