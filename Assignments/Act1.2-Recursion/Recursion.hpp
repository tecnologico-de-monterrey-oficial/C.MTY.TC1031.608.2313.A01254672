#pragma once
#include <iostream>
template <class T>
class Recursion
{
    public:
        Recursion();
        T sumIterative(T);
        T sumRecursive(T);
        T sumFormula(T);
        T fibonacciIterative(T);
        T fibonacciRecursive(T);
        T bacteriasIterative(T);
        T bacteriasRecursive(T);
        T investmentIterative(T,T);
        T investmentRecursive(T,T);
        T powIterative(T,T);
        T powRecursive(T,T);

};

//Constructor
template <class T>
Recursion<T>::Recursion(){}

template <class T>
T Recursion<T>::sumIterative(T data)
{
    T result = data;
    for (int i = 1; i < data; i++)
    {
        result = i + result ;
    }
    return result;
}


template <class T>
T Recursion<T>::sumRecursive(T data)
{
    if (data>1) {
        return data + sumRecursive(data-1);
    } 
    else {
        return 1;
    }
}

template <class T>
T Recursion<T>::sumFormula(T data)
{
    return data * (data + 1) / 2;
}


template <class T>
T Recursion<T>::fibonacciIterative(T data)
{
    if (data == 1 || data == 2)
    {
        return 1;
    }
    int num1 = 1;
    int num2 = 1;
    for (int i = 2; i < data; i++)
    {
        int  numtemp = num1 + num2;
        num1 = num2;
        num2 = numtemp;
    }
    return num2;
}

template <class T>
T Recursion<T>::fibonacciRecursive(T data)
{
     if (data == 1 || data == 2) {
        return 1;
    } else {
        return fibonacciRecursive(data - 1) + fibonacciRecursive(data - 2);
    }  
}

template <class T>
T Recursion<T>::bacteriasIterative(T data)
{
    float bacteria = 1;
    for (int i=0; i < data; i++)
    {
        float births = bacteria * 3.78;
        float deaths = bacteria * 2.34;
        bacteria += (births-deaths);
    }
    return bacteria;
}

template <class T>
T Recursion<T>::bacteriasRecursive(T data)
{
    if (data == 0) {
        return 1;
    } else {
        float bacteria = bacteriasRecursive(data - 1);
        float births = bacteria * 3.78;
        float deaths = bacteria * 2.34;
        return bacteria + (births - deaths);
    }
}



template <class T>
T Recursion<T>::investmentIterative(T months, T money)
{
    float capital = money;
    for (int i=0; i < months; i++)
    {
        capital += capital * .1875;
    }
    return capital;
}


template <class T>
T Recursion<T>::investmentRecursive(T months, T money)
{
    if (months==0) {
        return money;
    } 
    else {
        return investmentRecursive(months - 1, money + money * .1875);
    }
}


template <class T>
T Recursion<T>::powIterative(T n, T y)
{
    if (y == 0)
    {
        return 1;
    }
    int number = n;
    for (int i=1; i < y; i++)
    {
        number = n * number;
    }
    return number;
}


template <class T>
T Recursion<T>::powRecursive(T n, T y)
{
    if (y == 0) {
        return 1;
    } 
    else 
    {
        return n * powRecursive(n, y - 1);
    }
}
