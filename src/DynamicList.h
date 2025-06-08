#pragma once

#include "IDataStructure.h"
#include <vector>
#include <stdexcept>

template<typename T>
class DynamicList : public IDataStructure<T> {
public:
    DynamicList();
    ~DynamicList();
    void push(const T& value) override;
    T pop() override;
    T& top() override;
    bool isEmpty() const override;
    int size() const override;
    void clear() override;
    std::vector<T> toVector() const override;

    T& operator[](int index);
    const T& operator[](int index) const;
    
    // Implementação inline dos métodos de acesso para ordenação
    T& get(int index) override {
        return this->operator[](index);
    }

    void set(int index, const T& value) override {
        this->operator[](index) = value;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* m_head;
    int m_size;
    Node* getNodeAt(int index) const;
};