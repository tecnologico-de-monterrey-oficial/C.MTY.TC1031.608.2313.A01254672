#include <iostream>
#include "nodeDoubly-2.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

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
    Node<T>* getHead();
    Node<T>* getTail();
    Node<T>* getPrev();
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
    void quicksort(Node<T>* left, Node<T>* right);
    void swapSort(Node<T>* left, Node<T>* right);
    void print();
    void print2Format();
    void showValues(const std::string& firstValue, const std::string& lastValue);
    void reverseIP();
    void SumOfData();
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

template <class T>
Node<T>* DoublylinkedList<T>::getHead()
{
    return head;
}

template <class T>
Node<T>* DoublylinkedList<T>::getTail()
{
    return tail;
}

template <class T>
Node<T>* DoublylinkedList<T>::getPrev()
{
    return prev;
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
void DoublylinkedList<T>::quicksort(Node<T>* left, Node<T>* right) {
    if (left == nullptr || right == nullptr || left == right || left->prev == right) {
        return;
    }

    // Choose pivot element (e.g. first word of each line)
    std::string pivot = left->data.substr(0, 14);

    // Partition the list around the pivot element
    Node<T>* i = left;
    Node<T>* j = right;

    while (true) {
        // Move i pointer to the right until data[i] is greater than or equal to pivot
        while (i != right && i->data.substr(0, 14).compare(pivot) < 0) {
            i = i->next;
        }

        // Move j pointer to the left until data[j] is less than or equal to pivot
        while (j != left && j->data.substr(0, 14).compare(pivot) > 0) {
            j = j->prev;
        }

        // If i and j have crossed, break out of the loop
        if (i == j || i->prev == j) {
            break;
        }

        // Swap data[i] and data[j]
        std::swap(i->data, j->data);
    }

    // Swap data[left] and data[j]
    std::swap(left->data, j->data);

    // Recursively apply quicksort to sublists
    quicksort(left, j->prev);
    quicksort(j->next, right);
}
template <class T>
void DoublylinkedList<T>::swapSort(Node<T>* left, Node<T>* right) {
    if (left == nullptr || right == nullptr || left == right || left->prev == right) {
        return;
    }

    Node<T>* i = left;
    while (i != right) {
        Node<T>* j = i->next;
        while (j != left) {
            if (j->prev->data.substr(0, 14).compare(j->data.substr(0, 14)) > 0) {
                std::swap(j->prev->data, j->data);
            }
            j = j->prev;
        }
        i = i->next;
    }
}


template <class T>
void DoublylinkedList<T>::print()
{
    std::ofstream outfile("output602-1.txt");
    Node<T>* current = head;
    if (outfile.is_open()) {
        while (current != nullptr) {
                outfile << current->data.substr(15) << std::endl;
                current = current->next;
        }
        outfile.close();
    }
}

template <class T>
void DoublylinkedList<T>::print2Format(){

    std::multimap<std::string, std::pair<int, std::string>> lines;
    std::ifstream infile("output602-1.txt");
    std::ofstream outfile("output602-2.txt");
    std::string currLine;

    if (outfile.is_open()) {
        int lineNumber = 0;
        while (std::getline(infile, currLine)) {
            std::istringstream iss(currLine);
            std::string word, line, ip;
            int count = 0;
            while (iss >> word) {
                ++count;
                if (count == 5) {
                    ip = word;
                }
                else{
                    line += word + " ";
                }
            }
            std::string defLine = ip + " " + line;
            lines.insert(std::make_pair(ip, std::make_pair(lineNumber, defLine)));
            ++lineNumber;
        }
        for (auto& p : lines) {
        outfile << p.second.second << std::endl;
        }
        outfile.close();
    }
    infile.close();
}

template <class T>
void DoublylinkedList<T>::showValues(const std::string& firstValue, const std::string& lastValue) {
    std::ifstream infile("output602-2.txt");
    std::ofstream outfile("iprange602-a.txt");
    std::string currLine;
    if (outfile.is_open()) {
        int lineNumber = 0;
        while (std::getline(infile, currLine)) {
            std::istringstream iss(currLine);
            std::string word, line, ip;
            int count = 0;
            while (iss >> word) {
                ++count;
                if (count == 1) {
                    ip = word;
                }
                else{
                    line += word + " ";
                }
            }
            std::string defLine = ip + " " + line;
            if (ip >= firstValue && ip <= lastValue){
                outfile << defLine << std::endl;
            }
        }
        outfile.close();
    }
    infile.close();
}

template <class T>
void DoublylinkedList<T>::reverseIP() {
    std::ifstream infile("iprange602-a.txt");
    std::ofstream outfile("iprange602-d.txt");
    std::vector<std::string> lines;
    std::string line;
    
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }

    std::reverse(lines.begin(), lines.end());

    for (const auto& line : lines) {
        outfile << line << std::endl;
    }
    outfile.close();
    infile.close();
}

template <class T>
void DoublylinkedList<T>::SumOfData() {
    std::ifstream infile("output602-2.txt");
    std::string line;

    std::map<std::string, int> counts;

    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string ip, month, day, year, time, description;
        if (iss >> ip >> month >> day >> year >> time >> description) {
            std::string yearMonth = year + "-" + month;
            counts[yearMonth]++;
        }
    }
    infile.close();
    for (const auto& count : counts) {
        std::cout << count.first << ": " << count.second << " IP's" << std::endl;
    }
}