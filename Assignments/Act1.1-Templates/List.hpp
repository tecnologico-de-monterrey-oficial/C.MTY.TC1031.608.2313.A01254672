#pragma once
#include <vector>

template <class T>
class List{
    private:
        vector<T>list;
        int size;
    public:
        List();
        void insert(T);
        void removeLast();
        T getData(int);
        int getSize();
        T getMax();
        void print();
        
};

//constructor
template <class T>
List<T>::List() {
    this -> size=0;
}

//insert
template <class T>
void List<T>::insert(T data){
    list.push_back(data);
    size++;
}

//Remove last
template <class T>

void List<T>::removeLast()
{
    if (size == 0)
    {
        std::cout<<"No hay elementos"<<std::endl;
    }
    else
    {
        std::cout<<list[size-1]<<std::endl;
        list.pop_back();
        size--;
    }   
}

//getData
template <class T>
T List<T>::getData(int index)
{
    if (index >= 0 && index < size)
    {
        return list[index];
    }
    std::cout<<"No existe"<<std::endl;
    return T();
}

//getSize
template <class T>
int List<T>::getSize()
{
    return size;
}

//getMax
template <class T>
T List<T>::getMax()
{
    auto max = list[0];
    for (int i=1; i < size; i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    return max;

}

//Imprimir
template <class T>
void List<T>::print()
{
    // Iteramos de manera moderna
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

//
