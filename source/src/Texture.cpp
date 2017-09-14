//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#include "source/headers/Texture.h"

Texture::Texture()
{

}


Texture::Texture(GLenum type, const char *path)
{
    m_id = new uint32_t(0);
    m_type = type;
    m_path = path;
    glGenTextures(1, m_id);
    glBindTexture(type, *m_id);

    // Set Default parametres
    // set the texture wrapping parameters
    glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    {
        int width, height, nrChannels;

        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

        if (data)
        {
            glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(type);
        }
        else
        {
            std::cerr << "Failed to load texture" << std::endl;
        }

        stbi_image_free(data);
    }
}

Texture::Texture(GLenum type, const std::string &path) : Texture(type, path.c_str())
{

}

Texture::Texture(GLenum type, const Texture &texture)
        : Texture(texture.m_type, texture.m_path)
{

}

Texture::~Texture()
{
    glDeleteTextures(1, m_id);
    delete m_id;
}

void
Texture::clear()
{
    glDeleteTextures(1, m_id);
    delete m_id;
    m_id = nullptr;
}

void
Texture::setTexParametri(GLenum pname, GLint param)
{
    glTexParameteri(m_type, pname, param);
}

void
Texture::activateTexture(GLenum layout)
{
    glActiveTexture(layout);
    glBindTexture(m_type, *m_id);
}

void
Texture::bind()
{
    glBindTexture(m_type, *m_id);
}