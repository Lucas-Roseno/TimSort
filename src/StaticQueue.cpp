#include "StaticQueue.h"
#include "Timestamp.h"
#include <stdexcept>
#include <vector>

template<typename T>
StaticQueue<T>::StaticQueue() : m_front(0), m_rear(-1), m_size(0) {}

template<typename T>
bool StaticQueue<T>::isEmpty() const {
    return m_size == 0;
}

template<typename T>
int StaticQueue<T>::size() const {
    return m_size;
}

template<typename T>
void StaticQueue<T>::clear() {
    m_front = 0;
    m_rear = -1;
    m_size = 0;
}

template<typename T>
void StaticQueue<T>::push(const T& value) {
    if (m_size >= MAX_SIZE) {
        throw std::out_of_range("StaticQueue is full");
    }
    m_rear = (m_rear + 1) % MAX_SIZE;
    m_arr[m_rear] = value;
    m_size++;
}

template<typename T>
T StaticQueue<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("StaticQueue is empty");
    }
    T value = m_arr[m_front];
    m_front = (m_front + 1) % MAX_SIZE;
    m_size--;
    return value;
}

template<typename T>
T& StaticQueue<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("StaticQueue is empty");
    }
    return m_arr[m_front];
}

template<typename T>
std::vector<T> StaticQueue<T>::toVector() const {
    std::vector<T> vec;
    vec.reserve(m_size);
    if (!isEmpty()) {
        int count = 0;
        int i = m_front;
        while(count < m_size) {
            vec.push_back(m_arr[i]);
            i = (i + 1) % MAX_SIZE;
            count++;
        }
    }
    return vec;
}

template<typename T>
T& StaticQueue<T>::get(int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("StaticQueue: Index out of range.");
    }
    int physical_index = (m_front + index) % MAX_SIZE;
    return m_arr[physical_index];
}

template<typename T>
void StaticQueue<T>::set(int index, const T& value) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("StaticQueue: Index out of range.");
    }
    int physical_index = (m_front + index) % MAX_SIZE;
    m_arr[physical_index] = value;
}

template T& StaticQueue<Timestamp>::get(int);
template void StaticQueue<Timestamp>::set(int, const Timestamp&);
template class StaticQueue<Timestamp>;