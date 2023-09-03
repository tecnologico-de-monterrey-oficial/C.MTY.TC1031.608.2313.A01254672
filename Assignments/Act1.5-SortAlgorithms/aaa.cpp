template <class T>
void SelectionSort(std::vector<T> data)
{
    int iterations = 0;
    swap = 1;
    while (swap != 0)
    {
        int min_index = iterations
        for(int i=iterations; i<data.size(); i++)
            {
                if (data[i] < data[min_index])
                {
                    min_index = i;
                    swap++;
                }
            }
            std::swap(data[iterations], data[min_index]);
            
        iterations++;
    }
    
};