#include <iostream>
#include <string>
#include "ll.h"

using namespace std;

void printList(LL<int> *);

int main()
{
    LL<int> *list = new LL<int>;

    list->removeBack();

    for (int i = 0; i < 20; i++)
    {
        list->pushBack(i);
    }

    printList(list);

    printList(list);    

    delete list;

    return 0;
}

void printList(LL<int> *list) {
    for (int i=0; i<list->len(); i++) {
        cout << "Index: " << i << ", \t" << list->get(i) << endl;
    }
    cout << endl;
}
