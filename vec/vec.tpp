#ifndef VEC_TPP
#define VEC_TPP

#include <iostream>

/*
 * @brief Vector constructor of the template type, default capacity is 4.
 */
template <typename T>
Vec<T>::Vec()
{
    size = 0;
    capacity = 4;
    data = new T[capacity];
}

/*
 * @brief Copy constructor to avoid double frees.
 */
template <typename T>
Vec<T>::Vec(const Vec<T> &other)
{
    size = other.size;
    capacity = other.capacity;

    data = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

/*
 * @brief Vector destructor to remove the heap memory.
 */
template <typename T>
Vec<T>::~Vec()
{
    // std::cout << "Vec destructor called" << std::endl;
    delete[] data;
}

/*
 * @brief Adds the passed element to the end of the vector.
 */
template <typename T>
void Vec<T>::push(T value)
{
    // If vec is at capacity double it and push element
    if (size == capacity)
    {
        capacity *= 2;

        T *newData = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    data[size] = value;
    size++;
}

/*
 * @brief Adds the passed element to the requested position.
 * @param index - requested index of the new element
 * @param value - new item to insert
 */
template <typename T>
void Vec<T>::insert(int index, T value)
{
    // If vec is at capacity double it and push element
    if (size == capacity)
    {
        capacity *= 2;

        T *newData = new T[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    // Move all elements down then insert value at index
    for (int i = (size - 1); i >= index; i--)
    {
        data[i + 1] = data[i];
    }

    // Insert new value and increment size
    data[index] = value;
    size++;
}

/*
 * @brief Returns and removes the last element in the vector.
 */
template <typename T>
T Vec<T>::pop()
{
    size--;
    return data[size];
}

/*
 * @brief Returns the element at the index provided.
 * @param index - index of the requested element
 */
template <typename T>
T Vec<T>::get(int index)
{
    return data[index];
}

/*
 * @brief Returns the number of elements in the Vector.
 */
template <typename T>
int Vec<T>::getLen()
{
    return size;
}

/*
 * @brief Assignment operator overload. Will create new heap memory and copy contents.
 */
template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &other)
{
    // Protect against self-assignment:
    // nums1 = nums1;
    if (this == &other)
    {
        return *this;
    }

    // Free old array
    delete[] data;

    // Copy basic values
    size = other.size;
    capacity = other.capacity;

    // Allocate new array
    data = new T[capacity];

    // Copy elements
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    return *this;
}

/*
 * @brief Iterates through the vector and frees each element in data.
 * This assumes that the vector was created of pointer type.
 */
template <typename T>
void Vec<T>::heapFree()
{
    for (int i = 0; i < size; i++)
    {
        delete data[i];
        data[i] = nullptr;
    }

    size = 0;
}

/*
 * @brief Will print all elements in the vector.
 * @attention Ensure type is printable by iostream.
 */
template <typename T>
void Vec<T>::print_vec()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

/*
 * @brief Allows passing of a function pointer for printing of all array elements should they be of a custom type.
 * @param vec - vector to print from
 * @param print_function pointer to print function for the stored type
 */
template <typename T>
void Vec<T>::print_vec_obj(void (*print_function)(T))
{
    for (int i = 0; i < size; i++)
    {
        print_function(data[i]);
    }
    std::cout << std::endl;
}

#endif
