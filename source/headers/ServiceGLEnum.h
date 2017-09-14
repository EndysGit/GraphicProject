//
// Created by Gleb Vorfolomeew on 27/08/2017.
//

#include <cstdio>

#ifndef TEXTUREOGL_SERVICEGLENUM_H
#define TEXTUREOGL_SERVICEGLENUM_H

enum class AttributeType
{
    GS_COORDINATE1D = 1,
    GS_COORDINATE2D,
    GS_COORDINATE3D,
    GS_COORDINATE4D,

    GS_TEXTURE1D,
    GS_TEXTURE2D,
    GS_TEXTURE3D,
    GS_TEXTURE4D,

    COLOR
};

// Convert Attribute type to container size
// This fnction returns sizes(demensions) associated with
// each Attribute type

size_t
typeToSize(AttributeType type);

#endif //TEXTUREOGL_SERVICEGLENUM_H










