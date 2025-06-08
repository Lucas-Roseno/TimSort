// src/DynamicList.cpp
#include "DynamicList.h"

// Adiciona um timestamp ao final da lista
void DynamicList::add(const Timestamp& ts) {
    data.push_back(ts);
}

// Retorna uma referência para o timestamp no índice especificado
Timestamp& DynamicList::get(int index) {
    return data.at(index);
}

// Retorna o número de elementos na lista
int DynamicList::size() const {
    return data.size();
}

// Converte a lista dinâmica para um vetor de Timestamps
std::vector<Timestamp> DynamicList::toVector() const {
    return data;
}

// Limpa todos os elementos da lista
void DynamicList::clear() {
    data.clear();
}

