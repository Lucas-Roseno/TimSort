#include "DynamicQueue.h"
#include "Timestamp.h"
#include <stdexcept>
#include <vector>

template<typename T>
DynamicQueue<T>::DynamicQueue() : m_front(nullptr), m_rear(nullptr), m_size(0) {}

template<typename T>
DynamicQueue<T>::~DynamicQueue() {
    clear();
}

template<typename T>
void DynamicQueue<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
bool DynamicQueue<T>::isEmpty() const {
    return m_front == nullptr;
}

template<typename T>
int DynamicQueue<T>::size() const {
    return m_size;
}

template<typename T>
void DynamicQueue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (m_rear == nullptr) {
        m_front = m_rear = newNode;
    } else {
        m_rear->next = newNode;
        m_rear = newNode;
    }
    m_size++;
}

template<typename T>
T DynamicQueue<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicQueue is empty");
    }
    T value = m_front->data;
    Node* temp = m_front;
    m_front = m_front->next;
    if (m_front == nullptr) {
        m_rear = nullptr;
    }
    delete temp;
    m_size--;
    return value;
}

template<typename T>
T& DynamicQueue<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicQueue is empty");
    }
    return m_front->data;
}

template<typename T>
std::vector<T> DynamicQueue<T>::toVector() const {
    std::vector<T> vec;
    vec.reserve(m_size);
    Node* current = m_front;
    while(current != nullptr) {
        vec.push_back(current->data);
        current = current->next;
    }
    return vec;
}

template<typename T>
T& DynamicQueue<T>::get(int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("DynamicQueue: Index out of range.");
    }
    Node* current = m_front;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void DynamicQueue<T>::set(int index, const T& value) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("DynamicQueue: Index out of range.");
    }
    Node* current = m_front;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->data = value;
}

template T& DynamicQueue<Timestamp>::get(int);
template void DynamicQueue<Timestamp>::set(int, const Timestamp&);
template class DynamicQueue<Timestamp>;