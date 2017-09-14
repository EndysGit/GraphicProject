//
// Created by Gleb Vorfolomeew on 08/08/2017.
//

#include "source/headers/Shader.h"

// Constructor crates and builds shader
Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath)
{
    // Retrieve source code from file
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Check for exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // Open file
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // Close file handles
        vShaderFile.close();
        fShaderFile.close();
        // Fill string with file data
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    // Compile shaders
    // 1. Createing shaders id
    GLuint vertex, fragment;
    // 2. Compile and check shaders
    createShader(vertex, GL_VERTEX_SHADER, vShaderCode);
    createShader(fragment, GL_FRAGMENT_SHADER, fShaderCode);
    // Creating a program
    m_id = glCreateProgram();
    glAttachShader(m_id, vertex);
    glAttachShader(m_id, fragment);
    glLinkProgram(m_id);

    // Check program
    GLint success;
    const int16_t logSize = 512;
    char infoLog[logSize];

    glGetProgramiv(m_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(m_id, logSize, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED : \n"
                  << infoLog << '\n';
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

const GLint& Shader::getShaderID() const
{
    return m_id;
}

// Use shader
void Shader::use()
{
    glUseProgram(m_id);
}
// Utility uniform functions
void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int64_t value) const
{
    glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value);
}
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(m_id, name.c_str()), value);
}


void createShader(GLuint &shaderID, GLenum shaderType, const char *shaderSource)
{

    shaderID = glCreateShader(shaderType);
    const GLint amountOfLines = 1;
    glShaderSource(shaderID, amountOfLines, &shaderSource, NULL);
    glCompileShader(shaderID);
    // Check for success compilation
    checkSader(shaderID, shaderType);
    /*try
    {
        checkSader(shaderID, shaderType);
    }
    catch (const char* e)
    {
        std::cerr << e << '\n';
    }*/
}

void checkSader(GLuint &shaderID, GLenum shaderType)
{
    std::string shaderTypeStr;
    switch (shaderType)
    {
        case GL_VERTEX_SHADER:
            shaderTypeStr = "VERTEX";
            break;
        case GL_FRAGMENT_SHADER:
            shaderTypeStr = "FRAGMENT";
            break;
        case GL_GEOMETRY_SHADER:
            shaderTypeStr = "GEOMETRY";
            break;
        default:
            throw "Bad shader type";
    }

    GLint success;
    const int16_t logSize = 512;
    char infoLog[logSize];

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID, logSize, NULL, infoLog);
        std::cerr << "ERROR::SHADER::"<< shaderTypeStr << "::COMPILATION_FAILED : \n" << infoLog << '\n';
        //throw;
    }
}
