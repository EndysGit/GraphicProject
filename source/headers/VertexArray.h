//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#ifndef TEXTUREOGL_VERTEXARRAY_H
#define TEXTUREOGL_VERTEXARRAY_H


#include <cstdint>
#include <array>
#include <string>
#include <iostream>
#include "source/headers/my_glad_configure_functions.h"
#include "VertexBuffer.h"
#include "source/headers/ServiceGLEnum.h"


struct Attribute
{
    AttributeType attribute_type;
    size_t attribute_position;
    size_t number_of_elements;
    bool normalize_true_false;
    size_t attribute_offset;
};



class VertexArray {
public:
    VertexArray();
    VertexArray(const VertexArray &vertexArray);
    virtual ~VertexArray();

    VertexArray& operator=(const VertexArray &vertexArray);

    void BindVertexArray();

    size_t attributeNumber();

    void addAttribute();
    void add1DCoordinateAttribute();
    void add2DCoordinateAttribute();
    void add3DCoordinateAttribute();
    void addColorAttribute();
    void add1DTextureAttribute();
    void add2DTextureAttribute();
    void add3DTextureAttribute();

    void enableAttribute(size_t attribute);
    void disableAttribute(size_t attribute);
private:
    static constexpr size_t attribute_array_size = 16;
    uint32_t *m_id;
    VertexBuffer *m_associated_vertex_buffer;
    std::array<Attribute, attribute_array_size> m_attribute_array;
    size_t m_last_attribute;
    size_t m_last_stride;
};

VertexArray::VertexArray() : m_id{new uint32_t()}, m_last_attribute{0}, m_last_stride{0}
{
    glGenVertexArrays(1, m_id);
    glBindVertexArray(0);
}

VertexArray::VertexArray(const VertexArray &vertexArray)
        : m_id{new uint32_t()},
          m_last_attribute{vertexArray.m_last_attribute},
          m_last_stride{vertexArray.m_last_stride}
{
    glGenVertexArrays(1, m_id);

    for (ptrdiff_t index{0}; index < attribute_array_size; ++index)
        m_attribute_array[index] = vertexArray.m_attribute_array[index];

    glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, m_id);
    delete m_id;
}

VertexArray& VertexArray::operator=(const VertexArray &vertexArray)
{
    VertexArray temp{vertexArray};
    //std::swap(m_id, );
}

inline
void
VertexArray::BindVertexArray()
{
    glBindVertexArray(*m_id);
}

inline
size_t
VertexArray::attributeNumber()
{
    return m_last_attribute;
}

void
VertexArray::addAttribute()
{
}

void
VertexArray::add1DCoordinateAttribute()
{
    m_last_stride += typeToSize(AttributeType::GS_COORDINATE1D);
    auto local_number_of_elements(typeToSize(AttributeType::GS_COORDINATE1D));
    auto local_stride(m_last_stride  * sizeof(float));
    auto local_offset((m_last_stride - local_number_of_elements) * sizeof(float));
    if (!m_last_attribute)
    {
        m_attribute_array[m_last_attribute] = Attribute{AttributeType::GS_COORDINATE1D,
                                                        m_last_attribute,
                                                        local_number_of_elements,
                                                        false,
                                                        local_offset
        };
    }
    else
    {

    }
    glVertexAttribPointer(m_last_attribute,
                          typeToSize(AttributeType::GS_COORDINATE1D),
                          GL_FLOAT,
                          GL_TRUE,
                          static_cast<GLsizei>(m_last_stride * sizeof(float)),
                          (void*)0 );

    glEnableVertexAttribArray(m_last_attribute);
    ++m_last_attribute;
}

void
VertexArray::add2DCoordinateAttribute()
{

}
void
VertexArray::add3DCoordinateAttribute()
{

}

void
VertexArray::addColorAttribute()
{

}
void
VertexArray::add1DTextureAttribute()
{

}

void
VertexArray::add2DTextureAttribute()
{

}

void
VertexArray::add3DTextureAttribute()
{

}

void
VertexArray::enableAttribute(size_t attribute)
{
    glEnableVertexAttribArray(attribute);
}

void
VertexArray::disableAttribute(size_t attribute)
{
    glDisableVertexAttribArray(attribute);
}

#endif //TEXTUREOGL_VERTEXARRAY_H
