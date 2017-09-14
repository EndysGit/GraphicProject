//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#ifndef TEXTUREOGL_MY_GLAD_CONFIGURE_FUNCTIONS_H
#define TEXTUREOGL_MY_GLAD_CONFIGURE_FUNCTIONS_H

#include "source/headers/glad.h"
#include <exception>
#include <string>

class LoadOpenGLFunctionException : public std::exception
{
public:
    LoadOpenGLFunctionException();
    explicit LoadOpenGLFunctionException(const char *exception_message);
    explicit LoadOpenGLFunctionException(const std::string &exception_message);
    LoadOpenGLFunctionException(const LoadOpenGLFunctionException&);
    virtual ~LoadOpenGLFunctionException();
    virtual const char* what() const _NOEXCEPT;

private:
    std::string m_exception_message;
};

class my_glad_configure_functions {
    static void setOpenGLFunctionPointers();
};


#endif //TEXTUREOGL_MY_GLAD_CONFIGURE_FUNCTIONS_H
