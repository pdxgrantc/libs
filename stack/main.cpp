#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> *stack = new Stack<int>;

    for (int i = 0; i < 20; i++)
    {
        stack->push(i);
    }

    cout << endl
         << stack->len() << endl;

    while (stack->len() > 0)
{
    cout << stack->pop() << endl;
}
    cout << endl;

    delete stack;

    return 0;
}
