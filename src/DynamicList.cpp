#include "DynamicList.h"
#include "Timestamp.h"
#include <stdexcept>
#include <vector>

template<typename T>
DynamicList<T>::DynamicList() : m_head(nullptr), m_size(0) {}

template<typename T>
DynamicList<T>::~DynamicList() {
    clear();
}

template<typename T>
void DynamicList<T>::clear() {
    Node* current = m_head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    m_head = nullptr;
    m_size = 0;
}

template<typename T>
bool DynamicList<T>::isEmpty() const {
    return m_size == 0;
}

template<typename T>
int DynamicList<T>::size() const {
    return m_size;
}

template<typename T>
void DynamicList<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (m_head == nullptr) {
        m_head = newNode;
    } else {
        Node* current = m_head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    m_size++;
}

template<typename T>
T DynamicList<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicList is empty");
    }

    T value;
    if (m_size == 1) {
        value = m_head->data;
        delete m_head;
        m_head = nullptr;
    } else {
        Node* current = m_head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        value = current->next->data;
        delete current->next;
        current->next = nullptr;
    }
    m_size--;
    return value;
}

template<typename T>
T& DynamicList<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("DynamicList is empty");
    }
    return getNodeAt(m_size - 1)->data;
}

template<typename T>
std::vector<T> DynamicList<T>::toVector() const {
    std::vector<T> vec;
    vec.reserve(m_size);
    Node* current = m_head;
    while (current != nullptr) {
        vec.push_back(current->data);
        current = current->next;
    }
    return vec;
}

template<typename T>
typename DynamicList<T>::Node* DynamicList<T>::getNodeAt(int index) const {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range for DynamicList");
    }
    Node* current = m_head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

template<typename T>
T& DynamicList<T>::operator[](int index) {
    return getNodeAt(index)->data;
}

template<typename T>
const T& DynamicList<T>::operator[](int index) const {
    return getNodeAt(index)->data;
}

template class DynamicList<Timestamp>;