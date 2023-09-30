#pragma once

#include "node.hpp"
#include <stdexcept>
using namespace std;


template <class T>
class linkedList
{
private:
    Node<T>* head;
    int size;
public:
    linkedList();
    ~linkedList();
    int getSize();
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    void insertBack(T data);
    int findData(T data);
    T getData(int index);
    void updateData(T data, T newData); 
    void updateAt(int index, T data); 
    bool deleteData(T data); 
    bool deleteAt(int index);
    T& operator[](int index);
    void operator=(linkedList<T> list);
    void clear();
    bool isEmpty();
    void print();
};

template <class T>
linkedList<T>::linkedList()
{
    head = nullptr;
    size = 0;
}
template <class T>
linkedList<T>::~linkedList(){}

template <class T>
int linkedList<T>::getSize()
{
    return size;
}

template <class T>
void linkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template<class T>
void linkedList<T>::addLast(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }
    size++;
}

template<class T>
void linkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (currentIndex != index) {
            current = current->next;
            currentIndex++;
        }
        current->next = new Node<T>(data, current->next);
        size++;
    } else {
        throw out_of_range("El índice es incorrecto");
    }
}

template<class T>
int linkedList<T>::findData(T data) {
    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr) {
        if (current->data == data) {
            return currentIndex;
        }
        current = current->next;
        currentIndex++;
    }
    return -1;
}

template<class T>
T linkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    } else {
        throw out_of_range("Incorrect index");
    }
}

template<class T>
void linkedList<T>::updateData(T data, T newData) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            current->data = newData;
            break;
        }
        current = current->next;
    }
}

template<class T>
void linkedList<T>::updateAt(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        current->data = data;
    }
}

template<class T>
T& linkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    } else {
        throw out_of_range("Incorrect index");
    }
}

template<class T>
void linkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* current = head;
        head = head->next;
        delete current;
    }
    size = 0;
}

template <typename T>
void linkedList<T>::insertBack(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head; 
        while (current->next != nullptr) {
            current = current->next;   
        }
        current->next = newNode;
    }
    size++; 
}



template<class T>
void linkedList<T>::operator=(linkedList<T> list) {
    clear();
    Node<T>* current = list.head;
    while (current != nullptr) {
        insertBack(current->data);
        current = current->next;
    }
}

template <class T>
bool linkedList<T>::deleteData(T data) {
    if (!isEmpty()) {
        if (head->data == data) {
            Node<T>* current = head;
            head = head->next;
            size--;
            delete current;
            return true;
        } else {
            Node<T>* prevNode = head;
            Node<T>* current = head->next;
            while (current != nullptr) {
                if (current->data == data) {
                    prevNode->next = current->next;
                    size--;
                    delete current;
                    return true;
                }
                prevNode = current;
                current = current->next;
            }
            return false;
        }
    } else {
        return false;
    }
}

template <class T>
bool linkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        if (index == 0) {
            Node<T>* current = head;
            head = head->next;
            size--;
            delete current;
            return true;
        } else {
            Node<T>* prevNode = head;
            Node<T>* current = head->next;
            int currentIndex = 1;
            while (currentIndex < index) {
                prevNode = current;
                current = current->next;
                currentIndex++;
            }
            prevNode->next = current->next;
            size--;
            delete current;
            return true;
        }
    } else {
        return false;
    }
}

template<class T>
bool linkedList<T>::isEmpty() {
    return size == 0;
}

template <class T>
void linkedList<T>::print()
{
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
