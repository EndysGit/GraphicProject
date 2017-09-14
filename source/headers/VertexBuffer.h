//
// Created by Gleb Vorfolomeew on 25/08/2017.
//

#ifndef TEXTUREOGL_VERTEXBUFFER_H
#define TEXTUREOGL_VERTEXBUFFER_H

#include <cstdint>
#include "source/headers/my_glad_configure_functions.h"
#include <initializer_list>
#include "source/headers/ServiceGLEnum.h"
#include <iostream>
#include <vector>
#include "Vertex.h"

class DynamicArray
{
public:
    DynamicArray();
    explicit DynamicArray(size_t size);
    DynamicArray(size_t size, float filler);
    DynamicArray(const std::initializer_list<float> &list);
    DynamicArray(const DynamicArray &dynamicArray);
    ~DynamicArray();
    float& operator[](ptrdiff_t index);
    const float& operator[](ptrdiff_t index) const;
    void clear();
    size_t size() const;
    float* getArray() const ;
private:
    float *m_data;
    size_t m_array_size;
};


class VertexBuffer {
public:
    VertexBuffer();
    explicit VertexBuffer(const std::vector<Vertex> &vertices);
    VertexBuffer(const VertexBuffer &vertexBuffer);
    ~VertexBuffer();
    void clear();
    void changeBufferData(const std::vector<Vertex> &vertices);
    static float* convertTo(const std::vector<Vertex> $vertices);
private:
    uint32_t *m_id;
    DynamicArray m_vertices;
};



#endif //TEXTUREOGL_VERTEXBUFFER_H
