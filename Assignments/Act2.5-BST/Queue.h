#ifndef Queue_h
#define Queue_h

#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    Queue();
    void push(T data);
    void pop();
    T front();
    bool isEmpty();
    void print();
};

template<class T>
Queue<T>::Queue() {
    head = nullptr;
}

template<class T>
void Queue<T>::push(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
}

template<class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* aux = head;
        T auxData = aux->data;
        head = head->next;
        delete aux;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

template<class T>
void Queue<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

#endif
