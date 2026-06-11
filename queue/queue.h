#ifndef QUEUE_H
#define QUEUE_H

#include "item.h"

template <typename T>
class Queue
{
private:
    int length;
    Item<T> *head; // First item in the list
    Item<T> *tail; // Last item in the list

public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    int len();
};

#include "queue.tpp"

#endif
