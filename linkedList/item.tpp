#ifndef ITEM_TPP
#define ITEM_TPP

#include <iostream>
#include "item.h"

template <typename T>
Item<T>::Item(T newData)
{
    data = newData;
    next = nullptr;
}

template <typename T>
T Item<T>::getData()
{
    return data;
}

template <typename T>
Item<T> *Item<T>::getNext()
{
    return next;
}

template <typename T>
void Item<T>::setNext(Item<T> *nextPtr)
{
    next = nextPtr;
}

template <typename T>
void Item<T>::setData(T newData)
{
    data = newData;
}

#endif