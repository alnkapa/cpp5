#pragma once
#include <iostream>

#include "../model/model.h"

namespace view {
    class Shape {
       public:
        Shape(const model::Shape &shape) : m_model(shape){};
        ~Shape() = default;
        void render() { std::cout << "Shape: " << m_model << std::endl; };

       private:
        const model::Shape &m_model;
    };
    class Document {
       public:
        Document(const model::Document &document) : m_model(document){};
        ~Document() = default;
        void render() { std::cout << "Document: " << m_model << std::endl; };

       private:
        const model::Document &m_model;
    };
}  // namespace view
