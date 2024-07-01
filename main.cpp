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

namespace view {
    class Shape {
       public:
        Shape(const model::Shape &shape) : m_model(shape){};
        void render() { std::cout << "Shape: " << m_model << std::endl; };

       private:
        const model::Shape &m_model;
    };
    class Document {
       public:
        Document(const model::Document &document) : m_model(document){};
        void render() { std::cout << "Document: " << m_model << std::endl; };

       private:
        const model::Document &m_model;
    };
}  // namespace view

class Controller {
   public:
    void clear_document() {  // создание нового документа
        m_model.clear();
        m_view.render();
    };
    void create_shape(model::Shape &&shape) {  // создание графического примитива
        m_model.add_shape(std::move(shape));
        m_view.render();
    };

    void delete_shape(const model::Shape &shape) {  // удаление графического примитива
        m_model.del_shape(shape);
        m_view.render();
    };

    void import_document(const std::vector<unsigned char> &file) {  // импорт документа из файла
        m_model.import(file);
        m_view.render();
    };
    std::vector<unsigned char> export_document() {  // экспорт документа в файл
        return m_model.dump();
    };

   private:
    model::Document m_model{};
    view::Document m_view{m_model};
};

int main() {
    auto c{Controller{}};
    // TODO
    return 0;
}