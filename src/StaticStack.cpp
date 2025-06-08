// src/StaticStack.cpp
#include "StaticStack.h"
#include <stdexcept>

// Construtor: inicializa o tamanho atual como 0
StaticStack::StaticStack() : currentSize(0) {}

// Adiciona um timestamp ao topo da pilha (push)
void StaticStack::add(const Timestamp& ts) {
    if (currentSize < MAX_STATIC_SIZE) {
        data[currentSize++] = ts;
    } else {
        // Lançar exceção ou lidar com o erro de pilha cheia
        throw std::out_of_range("StaticStack is full");
    }
}

// Retorna uma referência para o timestamp em um determinado índice.
// Nota: Acesso por índice não é típico para pilhas, mas é necessário para satisfazer a interface IDataStructure.
// Em uma aplicação de pilha pura, este método não existiria ou lançaria uma exceção.
Timestamp& StaticStack::get(int index) {
    if (index >= 0 && index < currentSize) {
        return data[index];
    } else {
        throw std::out_of_range("Index out of bounds for StaticStack");
    }
}

// Retorna o número de elementos na pilha
int StaticStack::size() const {
    return currentSize;
}

// Converte a parte utilizada da pilha estática para um vetor de Timestamps
std::vector<Timestamp> StaticStack::toVector() const {
    std::vector<Timestamp> vec;
    vec.reserve(currentSize); // Otimização: reserva espaço
    for (int i = 0; i < currentSize; ++i) {
        vec.push_back(data[i]);
    }
    return vec;
}

// Limpa a pilha estática redefinindo o tamanho atual para 0
void StaticStack::clear() {
    currentSize = 0;
    // Não é necessário limpar os elementos da array, pois eles serão sobrescritos
}

// Remove e retorna o timestamp do topo da pilha (pop)
Timestamp StaticStack::pop() {
    if (currentSize > 0) {
        return data[--currentSize];
    } else {
        throw std::out_of_range("Pop from empty StaticStack");
    }
}

