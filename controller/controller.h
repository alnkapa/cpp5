#pragma once
#include <iostream>
#include <vector>

#include "../model/model.h"
#include "../view/view.h"

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

    void import_document(const std::vector<unsigned char> & file) {  // импорт документа из файла
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
