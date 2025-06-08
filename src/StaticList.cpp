// src/StaticList.cpp
#include "StaticList.h"
#include <stdexcept>

// Construtor: inicializa o tamanho atual como 0
StaticList::StaticList() : currentSize(0) {}

// Adiciona um timestamp à lista estática, verificando se há espaço
void StaticList::add(const Timestamp& ts) {
    if (currentSize < MAX_STATIC_SIZE) {
        data[currentSize++] = ts;
    } else {
        // Lançar exceção ou lidar com o erro de lista cheia
        throw std::out_of_range("StaticList is full");
    }
}

// Retorna uma referência para o timestamp no índice especificado, verificando limites
Timestamp& StaticList::get(int index) {
    if (index >= 0 && index < currentSize) {
        return data[index];
    } else {
        // Lançar exceção ou lidar com o erro de índice inválido
        throw std::out_of_range("Index out of bounds for StaticList");
    }
}

// Retorna o número atual de elementos na lista
int StaticList::size() const {
    return currentSize;
}

// Converte a parte utilizada da lista estática para um vetor de Timestamps
std::vector<Timestamp> StaticList::toVector() const {
    std::vector<Timestamp> vec;
    vec.reserve(currentSize); // Otimização: reserva espaço
    for (int i = 0; i < currentSize; ++i) {
        vec.push_back(data[i]);
    }
    return vec;
}

// Limpa a lista estática redefinindo o tamanho atual para 0
void StaticList::clear() {
    currentSize = 0;
    // Não é necessário limpar os elementos da array, pois eles serão sobrescritos
}

