#pragma once

#include "IDataStructure.h"
#include <vector>
#include <stdexcept>

template<typename T>
class DynamicStack : public IDataStructure<T> {
public:
    DynamicStack();
    ~DynamicStack();
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
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* m_top;
    int m_size;
};