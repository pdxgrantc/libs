#ifndef QUEUE_TPP
#define QUEUE_TPP

#include <iostream>
#include <stdexcept>
#include "queue.h"

using namespace std;

/*
 * @brief Queue constructor of the template type.
 */
template <typename T>
Queue<T>::Queue()
{
    length = 0;
    head = nullptr; // Set to null pointer for a new queue
    tail = nullptr; // Set to null pointer for a new queue
}

/*
 * @brief Queue destructor. This will not free any data
 * stored within any list item.
 */
template <typename T>
Queue<T>::~Queue()
{
    Item<T> *ptr = head;
    while (ptr != nullptr)
    {
        Item<T> *next = ptr->getNext(); // use ptr
        delete ptr;
        ptr = next;
    }
}

/*
 * @brief Queue destructor. This will not free any data
 * @param newData data to be stored in the queue.
 */
template <typename T>
void Queue<T>::push(T newData)
{
    Item<T> *newItem = new Item<T>(newData);
    if (head == nullptr)
    {
        head = newItem;
        tail = newItem;
    }
    else
    {
        tail->setNext(newItem);
        tail = newItem;
    }
    length++;
}

/*
 * @brief Queue destructor. This will not free any data
 * @param newData data to be stored in the queue.
 */
template <typename T>
T Queue<T>::pop()
{
    if (head == nullptr)
    {
        throw std::runtime_error("Queue is empty");
    }

    T returnData = head->getData();

    Item<T> *newHead = head->getNext();

    delete head;
    head = newHead;

    length--;

    return returnData;
}

template <typename T>
int Queue<T>::len()
{
    return length;
}

#endif
