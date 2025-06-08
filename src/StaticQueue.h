#pragma once

#include "IDataStructure.h"
#include "Constants.h"
#include <vector>
#include <stdexcept>

template<typename T>
class StaticQueue : public IDataStructure<T> {
public:
    StaticQueue();
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
    T m_arr[MAX_SIZE];
    int m_front;
    int m_rear;
    int m_size;
};