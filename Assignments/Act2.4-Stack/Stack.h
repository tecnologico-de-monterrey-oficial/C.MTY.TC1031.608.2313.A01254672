#ifndef Stack_h
#define Stack_h
#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
    int size;
public:
    Stack();
    ~Stack();
    void push(T data); // agrega un elemento a la pila
    void pop(); // Elimina el elemento de arriba de la pila
    T top(); // Regresa el elemento de arriba de la pila
    bool isEmpty(); // Regresa si la pila esta vacía o no
    void print(); // Imprime toda la pila
};

template <class T>
Stack<T>::Stack(){
    head=nullptr;
    size=0;
}

template <class T>
Stack<T>::~Stack(){}

template <class T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template <class T>
T Stack<T>::top() {
    if (!isEmpty()) {
        return head->data;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template <class T>
void Stack<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


#endif