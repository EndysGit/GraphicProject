//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#ifndef TEXTUREOGL_TEXTURE_H
#define TEXTUREOGL_TEXTURE_H


#include <cstdint>
#include <iostream>
#include "my_glad_configure_functions.h"
#include "source/headers/stb_image.h"

class Texture {
public:
    Texture();
    Texture(GLenum type, const char* path);
    Texture(GLenum type, const std::string &path);
    Texture(GLenum type, const Texture& texture);
    virtual ~Texture();

    void clear();
    void setTexParametri(GLenum pname, GLint param);
    void activateTexture(GLenum layout);
    void bind();
private:
    uint32_t *m_id;
    GLenum m_type;
    const char* m_path;
};



#endif //TEXTUREOGL_TEXTURE_H
