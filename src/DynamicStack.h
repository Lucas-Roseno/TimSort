// src/DynamicStack.h
#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "IDataStructure.h"
#include <vector>

// Implementação de uma pilha dinâmica usando std::vector
class DynamicStack : public IDataStructure {
private:
    std::vector<Timestamp> data;

public:
    // Construtor
    DynamicStack() = default;

    // Implementação dos métodos da interface IDataStructure
    void add(const Timestamp& ts) override; // Push
    Timestamp& get(int index) override; // Acesso não típico para pilha, mas necessário para interface
    int size() const override;
    std::vector<Timestamp> toVector() const override;
    void clear() override;

    // Método específico de pilha (opcional, mas útil)
    Timestamp pop();
};

#endif // DYNAMIC_STACK_H

