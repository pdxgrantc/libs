#ifndef STACK_TPP
#define STACK_TPP

/*
 * @brief Stack constructor of the template type.
 */
template <typename T>
Stack<T>::Stack()
{
    length = 0;
    head = nullptr; // Set to null pointer for a new queue
}

/*
 * @brief Queue destructor. This will not free any data
 * stored within any list item.
 */
template <typename T>
Stack<T>::~Stack()
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
void Stack<T>::push(T newData)
{
    // create new item and save current head
    Item<T> *newItem = new Item<T>(newData);
    Item<T> *oldHead = head;

    // set new relationships
    newItem->setNext(oldHead);
    head = newItem;

    length++;
    std::cout << length << std::endl;
}

/*
 * @brief Queue destructor. This will not free any data
 * @param newData data to be stored in the queue.
 */
template <typename T>
T Stack<T>::pop()
{
    if (head == nullptr)
    {
        throw std::runtime_error("Queue is empty");
    }

    T returnData = head->getData();

    Item<T> *newHead = head->getNext();

    if (newHead == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        delete head;
        head = newHead;
    }
    length--;

    return returnData;
}

template <typename T>
int Stack<T>::len()
{
    return length;
}

#endif
