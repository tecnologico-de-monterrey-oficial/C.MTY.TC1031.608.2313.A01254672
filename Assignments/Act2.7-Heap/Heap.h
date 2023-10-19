#ifndef Heap_h
#define Heap_h

#include <vector>

using namespace std;

template <class T>
class Heap {
private:
    std::vector<T> heap;
public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    void print();
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();

};

template <class T>
Heap<T>::Heap() {
    
}

template <class T>
Heap<T>::Heap(vector<T> list) {
    cout << "constructor con vector" << endl;
}

template <class T>
Heap<T>::Heap(initializer_list<T> list) {
    cout << "constructor con initializer list" << endl;
}

template <class T>
void Heap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
void Heap<T>::push(T value) {
    heap.push_back(value);
    int index = heap.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            std::swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

template <class T>
void Heap<T>::pop() {
    if (heap.empty()) {
        return;
    }
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

template <class T>
T Heap<T>::top() {
    if (heap.empty()) {
        return T();
    }
    return heap[0];
}

template <class T>
bool Heap<T>::empty() {
    return heap.empty();
}

template <class T>
int Heap<T>::size() {
    return heap.size();
}




#endif