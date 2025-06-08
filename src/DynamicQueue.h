#pragma once

#include "IDataStructure.h"
#include <vector>
#include <stdexcept>

template<typename T>
class DynamicQueue : public IDataStructure<T> {
public:
    DynamicQueue();
    ~DynamicQueue();
    void push(const T& value) override;
    T pop() override;
    T& top() override;
    bool isEmpty() const override;
    int size() const override;
    void clear() override;
    std::vector<T> toVector() const override;

    T& get(int index) override;
    void set(int index, const T& value) override;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* m_front;
    Node* m_rear;
    int m_size;
};