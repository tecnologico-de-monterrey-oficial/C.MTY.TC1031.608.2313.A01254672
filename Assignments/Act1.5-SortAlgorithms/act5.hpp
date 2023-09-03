#pragma once

#include <vector>

template <class T>
class solution
{
public:
    solution();
    ~solution();
    std::vector<T> Swapsort(std::vector<T>&);
    void Bubblesort(std::vector<T>);
    void SelectionSort(std::vector<T>);
    void InsertionSort(std::vector<T>);
    void MergeSort(std::vector<T>);
    void QuickSort(std::vector<T>);

};
template <class T>
solution<T>::solution()
{
}

template <class T>
solution<T>::~solution()
{
}

//swapsort
template <class T>
std::vector<T> solution<T>::Swapsort(std::vector<T>& data)
{
    std::cout << "NO SORTED LIST: " << data << std::endl;
    for (T d : data) 
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    int x = 0;
    while (x != 1)
    {
        int y = 0;
        for(int i = 0; i < data.size() -1; i++)
        {
            if (data[i] > data[i+1])
            {
                std::swap(data[i], data[i+1]);
                y = 1;
            }
        }
        if(y == 0)
        {
            x = 1;
        }
    }
    std::cout << "SORTED LIST: " << data << std::endl;
    for (T d : data) 
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for (const T& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}