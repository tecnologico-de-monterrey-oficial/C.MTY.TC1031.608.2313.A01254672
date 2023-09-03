#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
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

template <class T>
void test(std::vector<T>& data, const std::vector<std::vector<T>(*)(std::vector<T>)>& functions)
{
    std::vector<std::string> names = {"Swap Sort", "Bubble Sort", "Selection Sort", "Insertion Sort", "MergeSort"};
    int i = 0;
    for (auto func : functions) 
    {
        std::cout << names[i] << std::endl; std::cout<<std::endl;
        std::cout << "NO SORTED LIST: " << data << std::endl;
        srand(time(0));
        chrono::high_resolution_clock::time_point begin;
        chrono::high_resolution_clock::time_point end;
        startTime(begin);

        auto sorted_vec = func(data);

        std::cout << "el algoritmo " << names[i] << " tardo: "; getTime(begin, end); 
        i++;
        std::cout << "SORTED LIST: " << sorted_vec << std::endl;
        std::cout << std::endl;
    }
}

template <class T>
std::vector<T> Swapsort(std::vector<T> data)

{
    int comparaciones = 0;
    int intercambios = 0;
    int x = 0;
    while (x != 1)
    {
        int y = 0;
        for(int i = 0; i < data.size() -1; i++)
        {
            comparaciones++;
            if (data[i] > data[i+1])
            {
                std::swap(data[i], data[i+1]);
                intercambios++;
                y = 1;
            }
        }
        if(y == 0)
        {
            x = 1;
        }
    }
    
    std::cout<<"Comparaciones: "<<comparaciones<<std::endl;
    std::cout<<"Intercambios: "<<intercambios<<std::endl;
    return data;
    
}

template <class T>
std::vector<T> Bubblesort(std::vector<T> data)
{
   int comparaciones = 0;
    int intercambios = 0;
    int x = 0;
    while (x != 1)
    {
        int y = 0;
        for(int i = 0; i < data.size() -1; i++)
        {
            comparaciones++;
            if (data[i] > data[i+1])
            {
                std::swap(data[i], data[i+1]);
                intercambios++;
                y = 1;
            }
        }
        if(y == 0)
        {
            x = 1;
        }
    }
    
    std::cout<<"Comparaciones: "<<comparaciones<<std::endl;
    std::cout<<"Intercambios: "<<intercambios<<std::endl;
    return data;
}

template <class T>
std::vector<T> SelectionSort(std::vector<T> data)
{
    int comparaciones = 0;
    int intercambios = 0;
    int iterations = 0;
    
    for (int x = 0; x < data.size(); x++)
    {
        int min_index = x;
        for(int i=x; i<data.size(); i++)
            {
                comparaciones++;
                if (data[i] < data[min_index])
                {
                    min_index = i;
                }
            }
            std::swap(data[x], data[min_index]);
            intercambios++;
    }

    std::cout<<"Comparaciones: "<<comparaciones<<std::endl;
    std::cout<<"Intercambios: "<<intercambios<<std::endl;
    return data;
    
};

template <class T>
std::vector<T> InsertionSort(std::vector<T> data)
{
    int comparaciones = 0;
    int intercambios = 0;

    for(int i=0; i < data.size(); i++)
    {
        int x = i;
        while(x > 0 && data[x] < data[x-1])
        {
            comparaciones++;
            std::swap(data[x], data[x-1]);
            x--;
            intercambios++;
        }
    }

    std::cout<<"Comparaciones: "<<comparaciones<<std::endl;
    std::cout<<"Intercambios: "<<intercambios<<std::endl;
    return data;
};

template <class T>
std::vector<T> Merge(std::vector<T> leftside, std::vector<T> rightside)
{
    std::vector<T> nlist;
    // using reserve() to preallocate memory for the new merged vector can also 
    //improve performance by reducing the number of memory allocations needed.
    nlist.reserve(leftside.size() + rightside.size());
    
    
    //why use move()?
    //makes it faster because it allows the function to move 
    //the elements of the input vectors instead of copying them.

    while (!leftside.empty() && !rightside.empty())
    {
        if (leftside[0] < rightside[0])
        {
            nlist.push_back(std::move(leftside[0]));
            leftside.erase(leftside.begin());
        }
        else
        {
            nlist.push_back(std::move(rightside[0]));
            rightside.erase(rightside.begin());
        }
    }
    while (!leftside.empty())
    {
        nlist.push_back(std::move(leftside[0]));
        leftside.erase(leftside.begin());
    }
    while (!rightside.empty())
    {
        nlist.push_back(std::move(rightside[0]));
        rightside.erase(rightside.begin());
    }

    return nlist;
}

template <class T>
std::vector<T> MergeSort(std::vector<T> data)
{
    if (data.size() == 1)
    {
        return data;
    }
    std::vector<T> leftSide(data.begin(), data.begin() +  data.size() / 2);
    std::vector<T> rightSide((data.begin() +  data.size() / 2), data.end());

    std::vector<T>left = MergeSort(leftSide);
    std::vector<T>right = MergeSort(rightSide);

    return Merge(left, right);

};


template <class T>
std::vector<T> QuickSort(std::vector<T>data)
{
    if (data.begin() < data.end())
    {
        return
    }
};

int main()
{
    std::vector<int> data = {46,57,86,73,43,21,23};

    std::vector<std::vector<int>(*)(std::vector<int>)> functions = {Swapsort, Bubblesort, SelectionSort, InsertionSort,MergeSort};

    test(data, functions);


    return 0;
}
