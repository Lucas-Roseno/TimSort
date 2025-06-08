#pragma once
#include <iostream>

class Timestamp {
private:
    long long m_timestamp;

public:
    // Construtor padrão e de inicialização
    Timestamp(long long timestamp = 0) : m_timestamp(timestamp) {}

    // Getter para o valor do timestamp
    long long getTimestamp() const {
        return m_timestamp;
    }

    // Operador de comparação "maior que" para o TimSort
    bool operator>(const Timestamp& other) const {
        return m_timestamp > other.m_timestamp;
    }

    // Operador de comparação "menor ou igual a" para o TimSort
    bool operator<=(const Timestamp& other) const {
        return m_timestamp <= other.m_timestamp;
    }

    // Operador de stream para facilitar a impressão nos arquivos de saída
    friend std::ostream& operator<<(std::ostream& os, const Timestamp& ts) {
        os << ts.m_timestamp;
        return os;
    }
};