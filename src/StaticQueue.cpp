// src/StaticQueue.cpp
#include "StaticQueue.h"
#include <stdexcept>

// Construtor: inicializa head, tail e currentSize
StaticQueue::StaticQueue() : head(0), tail(0), currentSize(0) {}

// Adiciona um timestamp ao final da fila (enqueue)
void StaticQueue::add(const Timestamp& ts) {
    if (currentSize < MAX_STATIC_SIZE) {
        data[tail] = ts;
        tail = (tail + 1) % MAX_STATIC_SIZE; // Move o tail circularmente
        currentSize++;
    } else {
        // Lançar exceção ou lidar com o erro de fila cheia
        throw std::out_of_range("StaticQueue is full");
    }
}

// Retorna uma referência para o timestamp em um determinado índice.
// Nota: Acesso por índice não é típico para filas, mas é necessário para satisfazer a interface IDataStructure.
// Em uma aplicação de fila pura, este método não existiria ou lançaria uma exceção.
// Acessar o elemento no índice 'index' em uma fila estática implementada com array circular
// requer calcular a posição correta no array: (head + index) % MAX_STATIC_SIZE.
Timestamp& StaticQueue::get(int index) {
    if (index >= 0 && index < currentSize) {
        return data[(head + index) % MAX_STATIC_SIZE];
    } else {
        throw std::out_of_range("Index out of bounds for StaticQueue");
    }
}

// Retorna o número de elementos na fila
int StaticQueue::size() const {
    return currentSize;
}

// Converte a fila estática para um vetor de Timestamps
std::vector<Timestamp> StaticQueue::toVector() const {
    std::vector<Timestamp> vec;
    vec.reserve(currentSize); // Otimização: reserva espaço
    int current = head;
    for (int i = 0; i < currentSize; ++i) {
        vec.push_back(data[current]);
        current = (current + 1) % MAX_STATIC_SIZE;
    }
    return vec;
}

// Limpa a fila estática redefinindo head, tail e currentSize
void StaticQueue::clear() {
    head = 0;
    tail = 0;
    currentSize = 0;
    // Não é necessário limpar os elementos da array, pois eles serão sobrescritos
}

// Remove e retorna o timestamp do início da fila (dequeue)
Timestamp StaticQueue::dequeue() {
    if (currentSize > 0) {
        Timestamp front = data[head];
        head = (head + 1) % MAX_STATIC_SIZE; // Move o head circularmente
        currentSize--;
        return front;
    } else {
        throw std::out_of_range("Dequeue from empty StaticQueue");
    }
}

