// src/StaticList.h
#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "IDataStructure.h"
#include <array>
#include "Constants.h"

// Implementação de uma lista estática usando std::array
class StaticList : public IDataStructure {
private:
    std::array<Timestamp, MAX_STATIC_SIZE> data;
    int currentSize;

public:
    // Construtor
    StaticList();

    // Implementação dos métodos da interface IDataStructure
    void add(const Timestamp& ts) override;
    Timestamp& get(int index) override;
    int size() const override;
    std::vector<Timestamp> toVector() const override;
    void clear() override;
};

#endif // STATIC_LIST_H

