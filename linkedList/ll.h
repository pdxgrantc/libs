#ifndef LL_H
#define LL_H

#include "item.h"

template <typename T>
class LL
{
private:
    int length;         // Number of items
    Item<T> *head;      // First item in the list

public:
    LL();
    ~LL();
    int len();
    void pushFront(T data);
    void pushBack(T data);
    T get(int index);
    void set(int index, T);
    T getFront();
    T getBack();
    void insert(int index, T);
    void remove(int index);
    void removeFront();
    void removeBack();
};

#include "ll.tpp"

#endif

