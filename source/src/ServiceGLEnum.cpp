//
// Created by Gleb Vorfolomeew on 28/08/2017.
//

#include "source/headers/ServiceGLEnum.h"


size_t
typeToSize(AttributeType type)
{
    switch (type)
    {
        case AttributeType::GS_TEXTURE1D:
            return 1;
        case AttributeType::GS_TEXTURE2D:
            return 2;
        case AttributeType::GS_TEXTURE3D:
            return 3;
        case AttributeType::GS_TEXTURE4D:
            return 4;
        case AttributeType::COLOR:
            return 3;
        default:
            return static_cast<size_t>(type);
    }
}
