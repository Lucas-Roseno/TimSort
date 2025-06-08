#include "StaticList.h"
#include "Timestamp.h"

template<typename T>
StaticList<T>::StaticList() : m_size(0) {}

template<typename T>
void StaticList<T>::push(const T& value) {
    if (m_size >= MAX_SIZE) {
        throw std::out_of_range("StaticList is full");
    }
    m_arr[m_size++] = value;
}

template<typename T>
T StaticList<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("StaticList is empty");
    }
    return m_arr[--m_size];
}

template<typename T>
T& StaticList<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("StaticList is empty");
    }
    return m_arr[m_size - 1];
}

template<typename T>
bool StaticList<T>::isEmpty() const {
    return m_size == 0;
}

template<typename T>
int StaticList<T>::size() const {
    return m_size;
}

template<typename T>
void StaticList<T>::clear() {
    m_size = 0;
}

template<typename T>
std::vector<T> StaticList<T>::toVector() const {
    return std::vector<T>(m_arr, m_arr + m_size);
}

template<typename T>
T& StaticList<T>::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[index];
}

template<typename T>
const T& StaticList<T>::operator[](int index) const {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[index];
}

// Instanciação explícita do template para a classe Timestamp
template class StaticList<Timestamp>;