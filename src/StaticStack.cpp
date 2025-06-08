#include "StaticStack.h"
#include "Timestamp.h"
#include <stdexcept>
#include <vector>

template<typename T>
StaticStack<T>::StaticStack() : m_top(0) {}

template<typename T>
bool StaticStack<T>::isEmpty() const {
    return m_top == 0;
}

template<typename T>
int StaticStack<T>::size() const {
    return m_top;
}

template<typename T>
void StaticStack<T>::clear() {
    m_top = 0;
}

template<typename T>
void StaticStack<T>::push(const T& value) {
    if (m_top >= MAX_SIZE) {
        throw std::out_of_range("StaticStack is full");
    }
    m_arr[m_top++] = value;
}

template<typename T>
T StaticStack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("StaticStack is empty");
    }
    return m_arr[--m_top];
}

template<typename T>
T& StaticStack<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("StaticStack is empty");
    }
    return m_arr[m_top - 1];
}

template<typename T>
std::vector<T> StaticStack<T>::toVector() const {
    return std::vector<T>(m_arr, m_arr + m_top);
}

template<typename T>
T& StaticStack<T>::get(int index) {
    if (index < 0 || index >= m_top) {
        throw std::out_of_range("StaticStack: Index out of range.");
    }
    return m_arr[index];
}

template<typename T>
void StaticStack<T>::set(int index, const T& value) {
    if (index < 0 || index >= m_top) {
        throw std::out_of_range("StaticStack: Index out of range.");
    }
    m_arr[index] = value;
}

template T& StaticStack<Timestamp>::get(int);
template void StaticStack<Timestamp>::set(int, const Timestamp&);
template class StaticStack<Timestamp>;