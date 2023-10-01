#include <iostream>
#include "nodeDoubly.hpp"
#include <stdexcept>

using namespace std;

template <class T>
class DoublylinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* prev;

    int size;
public:
    DoublylinkedList();
    ~DoublylinkedList();
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
    void operator=(DoublylinkedList<T> list);
    void clear();
    void duplicate();
    void sort();
    void removeDuplicates();
    bool isEmpty();
    void print();
};

template <class T>
DoublylinkedList<T>::DoublylinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <class T>
DoublylinkedList<T>::~DoublylinkedList(){}

template <class T>
int DoublylinkedList<T>::getSize()
{
    return size;
}

template<class T> 
void DoublylinkedList<T>::addFirst(T data) {
  Node<T>* newNode = new Node<T>(data);
  newNode->next = head;
  if (head) head->prev = newNode;
  head = newNode;
  if (!tail) tail = newNode;
  size++;
}

template<class T>
void DoublylinkedList<T>::addLast(T data) {
  Node<T>* newNode = new Node<T>(data);
  if (tail == nullptr) {
    head = tail = newNode; 
  } 
  else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  size++;
}

template<class T>
void DoublylinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* current = head;
        int currentIndex = 0;
        while (currentIndex != index) {
            current = current->next;
            currentIndex++;
        }
        current->next = new Node<T>(data, current->next, current->prev);
        size++;
    } else {
        throw out_of_range("El índice es incorrecto");
    }
}

template<class T>
int DoublylinkedList<T>::findData(T data) {
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
T DoublylinkedList<T>::getData(int index) {
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
void DoublylinkedList<T>::updateData(T data, T newData) {
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
void DoublylinkedList<T>::updateAt(int index, T data) {
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
T& DoublylinkedList<T>::operator[](int index) {
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
void DoublylinkedList<T>::clear() {
  Node<T>* current = head;
  while(current) {
    Node<T>* temp = current;
    current = current->next;
    delete temp;
  }
  head = tail = nullptr;
  size = 0;
}

template<class T>
void DoublylinkedList<T>::sort() {
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  Node<T>* current = head->next;
  while (current != nullptr) {
    Node<T>* prev = current->prev;
    while (prev != nullptr && prev->data > current->data) {
      T temp = prev->data;
      prev->data = current->data;
      current->data = temp;
      current = prev;
      prev = prev->prev;
    }
    current = current->next;
  }
}

template<class T>  
void DoublylinkedList<T>::duplicate() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* duplicate = new Node<T>(current->data);
    duplicate->next = current->next;
    duplicate->prev = current;
    if (current->next) {
      current->next->prev = duplicate; 
    }
    current->next = duplicate;
    if (current == tail) {
      tail = duplicate; 
    }
    current = duplicate->next;
    size++;
  }
}

template<class T>
void DoublylinkedList<T>::removeDuplicates() {
  sort();
  
  Node<T>* current = head;
  while (current != nullptr && current->next != nullptr) {
    if (current->data == current->next->data) {
      Node<T>* nextNext = current->next->next;
      delete current->next;
      current->next = nextNext;
      if (nextNext) {
        nextNext->prev = current;
      }
      size--;
    } else {
      current = current->next; 
    }
  }
}

template <typename T>
void DoublylinkedList<T>::insertBack(T data) {
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
void DoublylinkedList<T>::operator=(DoublylinkedList<T> list) {
    clear();
    Node<T>* current = list.head;
    while (current != nullptr) {
        insertBack(current->data);
        current = current->next;
    }
}

template <class T>
bool DoublylinkedList<T>::deleteData(T data) {
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
bool DoublylinkedList<T>::deleteAt(int index) {
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
bool DoublylinkedList<T>::isEmpty() {
    return size == 0;
}

template <class T>
void DoublylinkedList<T>::print()
{
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
