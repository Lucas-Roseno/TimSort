// src/DynamicList.h
#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "IDataStructure.h"
#include <vector>

// Implementação de uma lista dinâmica usando std::vector
class DynamicList : public IDataStructure {
private:
    std::vector<Timestamp> data;

public:
    // Construtor
    DynamicList() = default;

    // Implementação dos métodos da interface IDataStructure
    void add(const Timestamp& ts) override;
    Timestamp& get(int index) override;
    int size() const override;
    std::vector<Timestamp> toVector() const override;
    void clear() override;
};

#endif // DYNAMIC_LIST_H

