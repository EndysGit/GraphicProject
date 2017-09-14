//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#include "source/headers/VertexBuffer.h"

// DynamicArray
// ------------
DynamicArray::DynamicArray() : m_data{nullptr}, m_array_size{0}
{

}

DynamicArray::DynamicArray(size_t size) : m_data{new float[size]}, m_array_size{size}
{

}

DynamicArray::DynamicArray(size_t size, float filler) : m_data{new float[size]}, m_array_size{size}
{
    for (ptrdiff_t index{0}; index < m_array_size; ++index)
        m_data[index] = filler;
}

DynamicArray::DynamicArray(const std::initializer_list<float > &list)
{
    m_array_size = list.size();

    try
    {
        m_data = new float(m_array_size);
    }
    catch (std::bad_alloc &bad_alloc)
    {
        std::cerr << "Faild to allocate memory\n";
    }

    ptrdiff_t counter{0};
    for (const auto &element : list)
    {
        m_data[counter] = element;
        ++counter;
    }
}

DynamicArray::DynamicArray(const DynamicArray &dynamicArray)
{
    m_array_size = dynamicArray.size();

    try
    {
        m_data = new float(m_array_size);
    }
    catch (std::bad_alloc &bad_alloc)
    {
        std::cerr << "Faild to allocate memory\n";
    }

    for (ptrdiff_t index(0); index < dynamicArray.size(); ++index)
        m_data[index] = dynamicArray.m_data[index];

}

inline
size_t
DynamicArray::size() const
{
    return m_array_size;
}

inline
float *
DynamicArray::getArray() const
{
    return m_data;
}

DynamicArray::~DynamicArray()
{
    delete [] m_data;
}

float&
DynamicArray::operator[](ptrdiff_t index)
{
    if (index < 0 || index >= m_array_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

const float&
DynamicArray::operator[](ptrdiff_t index) const
{
    if (index < 0 || index >= m_array_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

void
DynamicArray::clear()
{
    m_array_size = 0;

    if (m_data)
        delete[] m_data;

    m_data = nullptr;
}


// VertexBuffer implementation
// ---------------------------
VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, m_id);
    glBindBuffer(GL_ARRAY_BUFFER, *m_id);
}

VertexBuffer::VertexBuffer(const std::vector<Vertex> &vertices)
{

    glGenBuffers(1, m_id);
    glBindBuffer(GL_ARRAY_BUFFER, *m_id);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size(), m_vertices.getArray(), GL_STATIC_DRAW);
}

VertexBuffer::VertexBuffer(const VertexBuffer &vertexBuffer)
{
    glGenBuffers(1, m_id);
    glBindBuffer(GL_ARRAY_BUFFER, *m_id);
    glBufferData(GL_ARRAY_BUFFER, vertexBuffer.m_vertices.size(), vertexBuffer.m_vertices.getArray(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, m_id);
}

void
VertexBuffer::clear()
{
    glDeleteBuffers(1, m_id);
    m_vertices.clear();
}