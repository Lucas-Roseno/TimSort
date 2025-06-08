// src/IDataStructure.h
#ifndef IDATA_STRUCTURE_H
#define IDATA_STRUCTURE_H

#include <vector>
#include "Timestamp.h"

// Interface base para as estruturas de dados
class IDataStructure {
public:
    virtual ~IDataStructure() = default; // Destrutor virtual

    // Adiciona um timestamp à estrutura
    virtual void add(const Timestamp& ts) = 0;

    // Retorna o timestamp em um determinado índice (para acesso em ordenação)
    virtual Timestamp& get(int index) = 0;

    // Retorna o tamanho atual da estrutura
    virtual int size() const = 0;

    // Converte a estrutura para um vetor de Timestamps (para facilitar a ordenação)
    virtual std::vector<Timestamp> toVector() const = 0;

    // Limpa a estrutura
    virtual void clear() = 0;
};

#endif // IDATA_STRUCTURE_H

