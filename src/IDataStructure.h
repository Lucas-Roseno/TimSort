#pragma once
#include <vector>

template<typename T>
class IDataStructure {
public:
    virtual ~IDataStructure() {}
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T& top() = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual std::vector<T> toVector() const = 0;

    virtual T& get(int index) = 0;
    virtual void set(int index, const T& value) = 0;
};