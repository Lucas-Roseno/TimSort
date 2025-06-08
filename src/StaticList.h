#pragma once

#include "IDataStructure.h"
#include "Constants.h"
#include <stdexcept>
#include <vector>

template<typename T>
class StaticList : public IDataStructure<T> {
public:
    StaticList();
    void push(const T& value) override;
    T pop() override;
    T& top() override;
    bool isEmpty() const override;
    int size() const override;
    void clear() override;
    std::vector<T> toVector() const override;

    T& operator[](int index);
    const T& operator[](int index) const;

    // Implementação inline dos métodos de acesso para ordenação.
    // Eles usam o operator[] que já existe na lista.
    T& get(int index) override {
        return this->operator[](index);
    }

    void set(int index, const T& value) override {
        this->operator[](index) = value;
    }

private:
    T m_arr[MAX_SIZE];
    int m_size;
};