// src/StaticQueue.h
#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include "IDataStructure.h"
#include <array>
#include "Constants.h"

// Implementação de uma fila estática usando std::array
class StaticQueue : public IDataStructure {
private:
    std::array<Timestamp, MAX_STATIC_SIZE> data;
    int head; // Índice do início da fila
    int tail; // Índice do final da fila
    int currentSize;

public:
    // Construtor
    StaticQueue();

    // Implementação dos métodos da interface IDataStructure
    void add(const Timestamp& ts) override; // Enqueue
    Timestamp& get(int index) override; // Acesso não típico para fila, mas necessário para interface
    int size() const override;
    std::vector<Timestamp> toVector() const override;
    void clear() override;

    // Método específico de fila (opcional, mas útil)
    Timestamp dequeue();
};

#endif // STATIC_QUEUE_H

