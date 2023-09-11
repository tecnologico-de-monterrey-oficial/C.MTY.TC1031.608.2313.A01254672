template <class T>
std::vector<T> RadixSort(std::vector<T> data)
{
    if (data.empty())
        return data;

    T max = data[0];
    for (int i = 1; i < data.size(); i++)
        if (data[i] > max)
            max = data[i];
            
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        std::vector<T> output(data.size());
        std::vector<int> count(10, 0);

        for (int i = 0; i < data.size(); i++)
            count[(data[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = data.size() - 1; i >= 0; i--)
        {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }
        for (int i = 0; i < data.size(); i++)
            data[i] = output[i];
    }

    return data;
};