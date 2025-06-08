// src/DynamicQueue.cpp
#include "DynamicQueue.h"
#include <stdexcept>

// Adiciona um timestamp ao final da fila (enqueue)
void DynamicQueue::add(const Timestamp& ts) {
    data.push(ts);
}

// Retorna uma referência para o timestamp em um determinado índice.
// Nota: Acesso por índice não é típico para filas, mas é necessário para satisfazer a interface IDataStructure.
// Em uma aplicação de fila pura, este método não existiria ou lançaria uma exceção.
// Para filas, acessar por índice requer esvaziar a fila até o elemento desejado, o que não é eficiente.
// Uma implementação mais adequada para acesso por índice em fila dinâmica seria usar um std::deque.
// No entanto, para manter a consistência com a interface e a proposta de usar std::queue, faremos um acesso simulado.
// IMPORTANTE: Este método é ineficiente para filas e deve ser evitado em uso geral de filas.
Timestamp& DynamicQueue::get(int index) {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of bounds for DynamicQueue");
    }
    // Para acessar um elemento por índice em std::queue, precisaríamos de uma cópia ou iterar.
    // Como a interface pede uma referência, e std::queue não oferece acesso direto por índice,
    // esta implementação é apenas para satisfazer a assinatura da interface.
    // Em um cenário real, reavaliaríamos a interface ou a escolha da estrutura para filas.
    // Para o propósito deste exercício (ordenar convertendo para vetor), este método não será o gargalo.
    // Uma forma de 'simular' o acesso seria copiar para um vetor temporário, mas isso seria ainda menos eficiente.
    // Retornaremos o front() para o índice 0 e assim por diante, o que não é o comportamento esperado de 'get(index)'.
    // Uma alternativa seria usar std::deque que permite acesso por índice.
    // Vamos manter a implementação simples para o exercício, cientes da limitação.
    // Acessar o elemento no índice 'index' em uma std::queue diretamente não é possível.
    // A interface IDataStructure pode não ser ideal para todas as estruturas (pilha/fila) no que diz respeito ao 'get'.
    // Para o objetivo de ordenar (que provavelmente converterá para vetor), o método toVector é mais relevante.
    // Deixaremos esta implementação como está, ciente de que 'get' em fila não é performático/idiomático.
    // TODO: Considerar refatorar a interface IDataStructure se o acesso por índice for crucial para todas as estruturas.
    // Por enquanto, assumimos que a ordenação usará toVector().
    throw std::logic_error("Get by index is not efficiently supported for std::queue");
}

// Retorna o número de elementos na fila
int DynamicQueue::size() const {
    return data.size();
}

// Converte a fila dinâmica para um vetor de Timestamps
// Nota: Esvazia a fila original ao converter.
std::vector<Timestamp> DynamicQueue::toVector() const {
    std::vector<Timestamp> vec;
    std::queue<Timestamp> temp_data = data; // Copia a fila para não esvaziar a original (se necessário)
    while (!temp_data.empty()) {
        vec.push_back(temp_data.front());
        temp_data.pop();
    }
    return vec;
}

// Limpa todos os elementos da fila
void DynamicQueue::clear() {
    // std::queue não tem um método clear direto, mas pode ser limpa trocando por uma nova fila vazia
    std::queue<Timestamp> empty_queue;
    data.swap(empty_queue);
}

// Remove e retorna o timestamp do início da fila (dequeue)
Timestamp DynamicQueue::dequeue() {
    if (!data.empty()) {
        Timestamp front = data.front();
        data.pop();
        return front;
    } else {
        throw std::out_of_range("Dequeue from empty DynamicQueue");
    }
}

