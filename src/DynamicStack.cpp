// src/DynamicStack.cpp
#include "DynamicStack.h"
#include <stdexcept>

// Adiciona um timestamp ao topo da pilha (push)
void DynamicStack::add(const Timestamp& ts) {
    data.push_back(ts);
}

// Retorna uma referência para o timestamp em um determinado índice.
// Nota: Acesso por índice não é típico para pilhas, mas é necessário para satisfazer a interface IDataStructure.
// Em uma aplicação de pilha pura, este método não existiria ou lançaria uma exceção.
Timestamp& DynamicStack::get(int index) {
    if (index >= 0 && index < data.size()) {
        return data.at(index);
    } else {
        throw std::out_of_range("Index out of bounds for DynamicStack");
    }
}

// Retorna o número de elementos na pilha
int DynamicStack::size() const {
    return data.size();
}

// Converte a pilha dinâmica para um vetor de Timestamps
std::vector<Timestamp> DynamicStack::toVector() const {
    return data;
}

// Limpa todos os elementos da pilha
void DynamicStack::clear() {
    data.clear();
}

// Remove e retorna o timestamp do topo da pilha (pop)
Timestamp DynamicStack::pop() {
    if (!data.empty()) {
        Timestamp top = data.back();
        data.pop_back();
        return top;
    } else {
        throw std::out_of_range("Pop from empty DynamicStack");
    }
}

