#ifndef minHeap_h
#define minHeap_h

#include <vector>

template <class T>
class MinHeap {
private:
    std::vector<T> heap;

public:
    MinHeap();
    MinHeap(vector<T> list);
    MinHeap(initializer_list<T> list);
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
    void print();
};

template <class T>
MinHeap<T>::MinHeap() {
};

template <class T>
MinHeap<T>::MinHeap(vector<T> list) {
    cout << "constructor con vector" << endl;
}

template <class T>
MinHeap<T>::MinHeap(initializer_list<T> list) {
    cout << "constructor con initializer list" << endl;
}

template <class T>
void MinHeap<T>::push(T value) {
    heap.push_back(value);
    int index = heap.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            std::swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

template <class T>
void MinHeap<T>::pop() {
    if (heap.empty()) {
        return;
    }
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    int index = 0;
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

template <class T>
T MinHeap<T>::top() {
    if (heap.empty()) {
        return T();
    }
    return heap[0];
}

template <class T>
bool MinHeap<T>::empty() {
    return heap.empty();
}

template <class T>
int MinHeap<T>::size() {
    return heap.size();
}

template <class T>
void MinHeap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}


#endif