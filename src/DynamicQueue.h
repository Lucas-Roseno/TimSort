// src/DynamicQueue.h
#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include "IDataStructure.h"
#include <queue>

// Implementação de uma fila dinâmica usando std::queue
class DynamicQueue : public IDataStructure {
private:
    std::queue<Timestamp> data;

public:
    // Construtor
    DynamicQueue() = default;

    // Implementação dos métodos da interface IDataStructure
    void add(const Timestamp& ts) override; // Enqueue
    Timestamp& get(int index) override; // Acesso não típico para fila, mas necessário para interface
    int size() const override;
    std::vector<Timestamp> toVector() const override;
    void clear() override;

    // Método específico de fila (opcional, mas útil)
    Timestamp dequeue();
};

#endif // DYNAMIC_QUEUE_H

