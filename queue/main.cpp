#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> *queue = new Queue<int>;

    for (int i = 0; i < 20; i++)
    {
        queue->push(i);
    }

    for (int i = 0; i < queue->len(); i++) {
        cout << queue->pop() << " ";
    }
    cout << endl;

    delete queue;

    return 0;
}
