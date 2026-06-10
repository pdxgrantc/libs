#ifndef OBJ_TPP
#define OBJ_TPP

#include <iostream>

/*
 * @brief Obj constructor of the template type, default capacity is 4.
 */
Obj::Obj()
{
    data1 = 1;
    data2 = 2;
}

/*
 * @brief Obj constructor of the template type, default capacity is 4.
 */
Obj::Obj(int dataIn1, int dataIn2)
{
    data1 = dataIn1;
    data2 = dataIn2;
}

/*
 * @brief Obj destructor to remove the heap memory.
 */
Obj::~Obj()
{
    // std::cout << "Obj destructor called" << std::endl;
}

/*
 * @brief Obj destructor to remove the heap memory.
 */
void Obj::print_obj()
{
    // std::cout << "Obj destructor called" << std::endl;
    std::cout << "D1: " << data1 << " D2: " << data2 << std::endl;
}

#endif