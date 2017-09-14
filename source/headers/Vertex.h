//
// Created by Gleb Vorfolomeew on 27/08/2017.
//

#ifndef TEXTUREOGL_VERTEX_H
#define TEXTUREOGL_VERTEX_H

#include <map>
#include <vector>
#include "source/headers/ServiceGLEnum.h"
#include <exception>

class ConversionFail : public std::exception
{
public:
    ConversionFail();
    ConversionFail(const char* exception_message);
    ConversionFail(const std::string &exception_message);
    ConversionFail(const ConversionFail &conversionFail);

    virtual ~ConversionFail();
    virtual const char* what() const _NOEXCEPT override;
private:
    std::string m_exception_message;
};

class Vertex_base
{
protected:
    Vertex_base();

    virtual ~Vertex_base();

    virtual void addAttribute(AttributeType type, const std::vector<float> &attribute);
    virtual void addAttribute(AttributeType type);
    virtual void removeAttribute(AttributeType type);
    virtual std::vector<float>& getAttribute(AttributeType type);
    virtual bool equal(const Vertex_base& vertex) const;
    virtual bool empty() const;
};


class Vertex : public Vertex_base
{
public:
    Vertex();
    explicit Vertex(AttributeType type);
    Vertex(AttributeType type, const std::vector<float> &attribute);
    Vertex(const Vertex &vertex);

    virtual ~Vertex() override;

    virtual void addAttribute(AttributeType type, const std::vector<float> &attribute) override;
    virtual void addAttribute(AttributeType type) override;
    virtual void removeAttribute(AttributeType type) override;
    virtual std::vector<float>& getAttribute(AttributeType type) override;
    virtual bool equal(const Vertex_base& vertex) const override ;
    virtual bool empty() const override;

private:
    std::map<AttributeType, std::vector<float> > m_labeled_vertex;
};

// TODO: Check and refactor
// architectural mistakes:
// because of dynamic_cast int "equal" function
// second argument here can't be const reference
bool operator==(const Vertex &vertex1, const Vertex &vertex2);
bool operator!=(const Vertex &vertex1, const Vertex &vertex2);


#endif //TEXTUREOGL_VERTEX_H
