#ifndef STACK_H
#define STACK_H

#include "item.h"

template <typename T>
class Stack
{
private:
    int length;
    Item<T> *head; // First item in the list\

public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    int len();
};

#include "stack.tpp"

#endif
