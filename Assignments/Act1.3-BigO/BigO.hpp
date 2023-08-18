#pragma once
#include <vector>

class BigO{

    public:
        BigO();
        int SumOddIte(std::vector<int>);
        int SumOddRec(std::vector<int>);
        int SumOddRecTrick(std::vector<int>, int, int);
};

BigO::BigO(){}

int BigO::SumOddIte(std::vector<int>nums)
{
    int sum = 0;
    for (auto num : nums)
    {
        if (num%2 != 0){
            sum += num;
        }
    }
    return sum;
}

int BigO::SumOddRecTrick(std::vector<int> nums, int index, int sum)
{
    if (index >= nums.size()) {
        return sum;
    }
    
    if (nums[index] % 2 != 0) {
        sum += nums[index];
    }
    
    return SumOddRecTrick(nums, index + 1, sum);
}

int BigO::SumOddRec(std::vector<int> nums)
{
    return SumOddRecTrick(nums,0,0);
}
