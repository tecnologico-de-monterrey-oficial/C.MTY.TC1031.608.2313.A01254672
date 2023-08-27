#pragma once
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;



class Solution
{
    public:

        Solution();
        int sequentialSearch(int);
        int binarySearch(int);
        void uniqueCharSeq(vector<std::string>);
        void uniqueCharBin(vector<std::string>);

        
};

Solution::Solution(){}


int Solution::sequentialSearch(int data)
{
    std::vector<int>bank;
    for(int i=0; i < 10000; i++)
    {
        int ranum = std::rand()%1000000 + 1;
        bank.push_back(ranum);
    }
    int x = 0;
    for(auto i : bank)
    {
        if (i == data)
        {
            return x;
        }
        x += 1;
    }
    return -1;
}


int Solution::binarySearch(int data)
{
    std::vector<int>bank;
    for(int i=0; i < 10000; i++)
    {
        int ranum = std::rand()%1000000 + 1;
        bank.push_back(ranum);
    }
    int x = 0;
    std::sort(std::begin(bank), std::end(bank));
    std::size_t size = bank.size();
    
    int low = 0;
    int high = bank.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (bank[mid] == data)
        {
            return mid;
        }
        else if (bank[mid] < data)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
    
}

void Solution::uniqueCharSeq(vector<std::string> data)
{
    for(auto i : data)
    {
        for(int x = 1; x<i.size()-1; x++)
        {
            if(i[0] != i[1])
            {
                std::cout << i[0] << " " << x << std::endl;
                break;
            }
            if((i[x] != i[x+1]) && (i[x] != i[x-1]))
            {
                std::cout << i[x] << " " << x << std::endl;
                break;
            }
            if(i[i.size()-1] != i[i.size()-2])
            {
                std::cout << i[i.size()-1] << " " << x << std::endl;
                break;
            }
        }
    }
}

void Solution::uniqueCharBin(vector<std::string> data)
{
    for(auto i : data)
    {
        for(int x = 1; x<i.size()-1; x++)
        {
            if(i[0] != i[1])
            {
                std::cout << i[0] << " " << x << std::endl;
                break;
            }
            if((i[x] != i[x+1]) && (i[x] != i[x-1]))
            {
                std::cout << i[x] << " " << x << std::endl;
                break;
            }
            if(i[i.size()-1] != i[i.size()-2])
            {
                std::cout << i[i.size()-1] << " " << x << std::endl;
                break;
            }
        }
    }
}


