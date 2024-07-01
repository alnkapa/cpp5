#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace model {
    class Shape {
       public:
        friend std::ostream &operator<<(std::ostream &out, const Shape &in) {
            for (const auto &v : in.m_vertices) {
                out << v << " ; ";
            }
            return out;
        }
        friend bool operator==(const Shape &a, const Shape &b) { return &a == &b; };
        std::vector<unsigned char> dump() const {
            std::vector<unsigned char> rez{};
            // TODO
            return rez;
        };
        void import(const std::vector<unsigned char> &in) {
            // TODO
        };

       private:
        std::vector<float> m_vertices;
    };

    class Document {
       public:
        friend std::ostream &operator<<(std::ostream &out, const Document &in) {
            for (const auto &v : in.m_doc) {
                out << v;
            }
            return out;
        }
        void clear() { m_doc.clear(); };
        void add_shape(Shape &&shape) { m_doc.emplace_back(shape); };
        void del_shape(const Shape &shape) {
            auto it = std::find(m_doc.begin(), m_doc.end(), shape);
            if (it != m_doc.end()) {
                m_doc.erase(it);
            }
        };
        std::vector<unsigned char> dump() const {
            std::vector<unsigned char> rez{};
            // TODO
            for (const auto &v : m_doc) {
                [[maybe_unused]] auto part = v.dump();
                // TODO
            }
            // TODO
            return rez;
        };
        void import(const std::vector<unsigned char> &in) {
            // TODO
            for (auto &v : m_doc) {
                v.import(in);
                // TODO
            }
            // TODO
        };

       private:
        std::vector<Shape> m_doc;
    };

}  // namespace model
