#ifndef ITEM_H
#define ITEM_H

template <typename T>
class Item
{
private:
    T data;        // Data
    Item<T> *next; // Pointer to the next item in the list
public:
    Item(T data);
    T getData();
    void setData(T);
    Item<T> *getNext();
    void setNext(Item<T> *next);
};

#include "item.tpp"

#endif
