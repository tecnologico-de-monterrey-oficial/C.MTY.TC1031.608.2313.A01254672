#ifndef Queue_h
#define Queue_h
#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue();
    ~Queue();
    void push(T data); // Agrega un elemento al final de la fila (enqueque)
    void pop(); // elimina el primer elemento de la file (dequeue)
    T front(); // regresa el primer elemento de la fila (front)
    bool isEmpty();
    void print();
};

template <class T>
Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <class T>
Queue<T>::~Queue(){}

template <class T>
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
}

template <class T>
void Queue<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif