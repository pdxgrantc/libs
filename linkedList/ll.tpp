#ifndef VEC_TPP
#define VEC_TPP

#include <iostream>
#include <stdexcept>
#include "ll.h"

using namespace std;

/*
 * @brief Linked list constructor of the template type.
 */
template <typename T>
LL<T>::LL()
{
    length = 0;
    head = nullptr; // Set to null pointer for a new list
}

/*
 * @brief Linked list destructor. This will not free any data
 * stored within any list item.
 */
template <typename T>
LL<T>::~LL()
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
 * @brief Returns the integer number of items in the linked list.
 */
template <typename T>
int LL<T>::len()
{
    return length;
}

/*
 * @brief Creates a new item at the front of the linked list.
 * @param data - data to store in the new list item.
 */
template <typename T>
void LL<T>::pushFront(T data)
{
    Item<T> *currentHead = head;
    Item<T> *newItem = new Item<T>(data);
    newItem->setNext(currentHead);
    head = newItem;
    length++;
}

/*
 * @brief Creates a new item at the end of the linked list.
 * @param data - data to store in the new list item.
 */
template <typename T>
void LL<T>::pushBack(T data)
{
    if (length != 0)
    {
        // Create new item and set data
        Item<T> *newItem = new Item<T>(data);
        // Find end of list and set its next pointer to new item
        Item<T> *current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newItem);
    }
    // Empty list case
    else
    {
        // make new item and set head
        Item<T> *newItem = new Item<T>(data);
        head = newItem;
    }
    length++;
}

/*
 * @brief Returns the data stored at the index provided.
 * @param index - index of the item to be returned.
 */
template <typename T>
T LL<T>::get(int index)
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of bounds");
    }

    Item<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    return current->getData();
}

/*
 * @brief Sets the data stored at the index provided.
 * @param index List index to be set.
 */
template <typename T>
void LL<T>::set(int index, T newData)
{
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of bounds");
    }

    Item<T> *current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    current->setData(newData);
}

/*
 * @brief Returns the data stored in the first linked list item.
 */
template <typename T>
T LL<T>::getFront()
{
    if (length == 0)
    {
        throw std::out_of_range("Empty list");
    }
    return head->getData();
}

/*
 * @brief Returns the data stored in the last linked list item.
 */
template <typename T>
T LL<T>::getBack()
{
    if (length == 0)
    {
        throw std::out_of_range("Empty list");
    }

    Item<T> *current = head;
    while (current->getNext() != nullptr)
    {
        current = current->getNext();
    }
    return current->getData();
}

/*
 * @brief Creates a new item at the provided index.
 * @param index Index for new list item.
 * @param newData Data to store in the new list item.
 */
template <typename T>
void LL<T>::insert(int index, T newData)
{
    // Out of bounds detection
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of bounds");
    }

    if (index == 0)
    {
        pushFront(newData);
        return;
    }

    Item<T> *current = head;
    Item<T> *oldNext;
    for (int i = 0; i < (index - 1); i++)
    {
        current = current->getNext();
    }
    oldNext = current->getNext();

    Item<T> *newItem = new Item<T>(newData);
    newItem->setNext(oldNext);
    current->setNext(newItem);
    length++;
}

/*
 * @brief Removes the list item at the specified index.
 * @param index Index of the list item to remove.
 * @attention This will not free any memory stored within the list item.
 */
template <typename T>
void LL<T>::remove(int index)
{
    // Out of bounds detection
    if (index < 0 || index >= length)
    {
        throw std::out_of_range("Index out of bounds");
    }
    if (index == 0)
    {
        removeFront();
        return;
    }
    
    Item<T> *current = head;
    Item<T> *next = head->getNext();
    for (int i = 0; i < (index - 1); i++)
    {
        current = current->getNext();
        next = next->getNext();
    }

    Item<T> *newNext = next->getNext();
    current->setNext(newNext);

    delete next;

    length--;
}

/*
 * @brief Removes the first linked list item.
 */
template <typename T>
void LL<T>::removeFront()
{
    Item<T> *secondItem = head->getNext();
    delete head;
    head = secondItem;
    length--;
}

/*
 * @brief Removes the last linked list item.
 */
template <typename T>
void LL<T>::removeBack()
{
    if (length == 0)
    {
        return;
    }

    Item<T> *current = head;
    for (int i = 0; i < (length - 1); i++)
    {
        current = current->getNext();
    }
    delete current->getNext();
    length--;
}

#endif
