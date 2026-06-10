#ifndef VEC_H
#define VEC_H

#include <iostream>

template <typename T>
class Vec
{
private:
    T *data;
    int size;
    int capacity;

public:
    Vec();
    ~Vec();
    Vec(const Vec<T> &other);      
    
    void push(T value);
    void insert(int pos, T value);
    T get(int pos);
    int getLen();
    T pop();
    
    void print_vec();
    void print_vec_obj(void (*)(T));

    Vec<T> &operator=(const Vec<T> &other);
    
    void heapFree();
};

#include "vec.tpp"

#endif
