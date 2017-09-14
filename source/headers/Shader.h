//
// Created by Gleb Vorfolomeew on 08/08/2017.
//

#ifndef OPENGLTRAININGS_SHADER_H
#define OPENGLTRAININGS_SHADER_H

#include  "source/headers/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
public:
    // Constructor crates and builds shader
    Shader(const GLchar *vertexPath, const GLchar *filePath);
    // Use shader
    void use();
    // Get id
    const GLint& getShaderID() const ;
    // Utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int64_t value) const;
    void setFloat(const std::string &name, float value) const;
private:
    GLint m_id;
};

void createShader(GLuint &shaderID, GLenum shaderType, const char *shaderSource);
void checkSader(GLuint &shaderID, GLenum shaderType);




#endif //OPENGLTRAININGS_SHADER_H
