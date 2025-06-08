#include "DynamicStack.h"
#include "Timestamp.h"
#include <stdexcept>
#include <vector>

template<typename T>
DynamicStack<T>::DynamicStack() : m_top(nullptr), m_size(0) {}

template<typename T>
DynamicStack<T>::~DynamicStack() {
    clear();
}

template<typename T>
void DynamicStack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
bool DynamicStack<T>::isEmpty() const {
    return m_top == nullptr;
}

template<typename T>
int DynamicStack<T>::size() const {
    return m_size;
}

template<typename T>
void DynamicStack<T>::push(const T& value) {
    m_top = new Node(value, m_top);
    m_size++;
}

template<typename T>
T DynamicStack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicStack is empty");
    }
    T value = m_top->data;
    Node* oldTop = m_top;
    m_top = m_top->next;
    delete oldTop;
    m_size--;
    return value;
}

template<typename T>
T& DynamicStack<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicStack is empty");
    }
    return m_top->data;
}

template<typename T>
std::vector<T> DynamicStack<T>::toVector() const {
    std::vector<T> vec;
    vec.reserve(m_size);
    Node* current = m_top;
    while(current != nullptr) {
        vec.push_back(current->data);
        current = current->next;
    }
    // A pilha é LIFO, então o vetor precisa ser revertido para a ordem de inserção
    std::reverse(vec.begin(), vec.end());
    return vec;
}

template<typename T>
T& DynamicStack<T>::get(int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("DynamicStack: Index out of range.");
    }
    // O acesso a índice na pilha é LIFO, então o índice 0 é o topo.
    Node* current = m_top;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void DynamicStack<T>::set(int index, const T& value) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("DynamicStack: Index out of range.");
    }
    Node* current = m_top;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = value;
}

template T& DynamicStack<Timestamp>::get(int);
template void DynamicStack<Timestamp>::set(int, const Timestamp&);
template class DynamicStack<Timestamp>;