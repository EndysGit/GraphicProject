//
// Created by Gleb Vorfolomeew on 27/08/2017.
//

#include <iostream>
#include "source/headers/Vertex.h"


// Exception implementation
// ------------------------
ConversionFail::ConversionFail()
{

}

ConversionFail::ConversionFail(const char *exception_message)
        : m_exception_message{exception_message}
{

}

ConversionFail::ConversionFail(const std::string &exception_message)
        : m_exception_message{exception_message}
{

}

ConversionFail::ConversionFail(const ConversionFail &conversionFail)
        : m_exception_message{conversionFail.m_exception_message}
{

}

ConversionFail::~ConversionFail()
{

}

const char*
ConversionFail::what() const _NOEXCEPT
{
    return m_exception_message.c_str();
}

// Vertex_base trivial implementation
// ----------------------------------
Vertex_base::Vertex_base()
{

}

Vertex_base::~Vertex_base()
{

}

bool
Vertex_base::empty() const
{

}

void
Vertex_base::addAttribute(AttributeType type)
{

}

void
Vertex_base::addAttribute(AttributeType type, const std::vector<float> &attribute)
{

}

void
Vertex_base::removeAttribute(AttributeType type)
{

}

std::vector<float>&
Vertex_base::getAttribute(AttributeType type)
{

}

bool
Vertex_base::equal(const Vertex_base& vertex) const
{

}

// Vertex class impleemntation
// ---------------------------

Vertex::Vertex()
{

}

Vertex::Vertex(AttributeType type)
{
    m_labeled_vertex[type];
}

Vertex::Vertex(AttributeType type, const std::vector<float> &attribute)
{
    if (attribute.size() != typeToSize(type))
    {
        std::cerr << "The attribute container size should match type demension\n";

    }
    m_labeled_vertex[type] = attribute;
}

Vertex::Vertex(const Vertex &vertex)
{
    m_labeled_vertex = vertex.m_labeled_vertex;
}

Vertex::~Vertex()
{

}

bool
Vertex::empty() const
{
    return m_labeled_vertex.empty();
}

void
Vertex::addAttribute(AttributeType type)
{
    if (!m_labeled_vertex[type].empty())
    {
        std::cerr << "Attribute with this type is already exists\n";
        return;
    }
    m_labeled_vertex[type];
}

void
Vertex::addAttribute(AttributeType type, const std::vector<float> &attribute)
{
    if (!m_labeled_vertex[type].empty())
    {
        std::cerr << "Attribute with this type is already exists\n";
        return;
    }
    if (attribute.size() != typeToSize(type))
    {
        std::cerr << "The attribute container size should match type demension\n";
        return;
    }
    m_labeled_vertex[type] = attribute;
}

void
Vertex::removeAttribute(AttributeType type)
{
    if (m_labeled_vertex.empty())
    {
        std::cerr << "Attempt to remove data from empty Vertex\n";
        return;
    }

    try
    {
        m_labeled_vertex.erase(type);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::vector<float>&
Vertex::getAttribute(AttributeType type)
{
    return m_labeled_vertex[type];
}

bool
Vertex::equal(const Vertex_base&  vertex) const
{

    const auto temp = dynamic_cast<const Vertex*>(&vertex);

    if (!temp)
        throw ConversionFail("Failed to dynamicaly convert type.\n"
                                     "Check if given type the same as type you try to compare to\n");

    if (this->m_labeled_vertex.size() != temp->m_labeled_vertex.size())
        return false;

    std::map<AttributeType , std::vector<float >>::const_iterator it1 = this->m_labeled_vertex.begin();
    std::map<AttributeType , std::vector<float>>::const_iterator it2 = temp->m_labeled_vertex.begin();

    for ( ; it1 != this->m_labeled_vertex.end(); ++it1, ++it2)
        if (it1->first != it2->first)
            return false;
    return true;
}


bool
operator==(const Vertex &vertex1, const Vertex &vertex2)
{
    return vertex1.equal(vertex2);
}
bool
operator!=(const Vertex &vertex1, const Vertex &vertex2)
{
    return !(vertex1 ==  vertex2);
}