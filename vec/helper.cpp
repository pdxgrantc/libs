#include <iostream>
#include "vec.h"

/*
 * @brief Simple print for vectors with base c++ type values 
 */
template <typename T>
void print_vec(Vec<T> *vec)
{
    for (int i = 0; i < vec->getLen(); i++)
    {
        std::cout << vec->get(i) << " ";
    }
    std::cout << std::endl;
}

/*
 * @brief Simple print for vectors with base c++ type values 
 * @param vec - vector to print from
 * @param print_function pointer to print function for the given type
 */
template <typename T>
void print_vec_obj(Vec<T> *vec, void (*print_function)(T))
{
    for (int i = 0; i < vec->getLen(); i++)
    {
        print_function(vec->get(i));
    }
    std::cout << std::endl;
}