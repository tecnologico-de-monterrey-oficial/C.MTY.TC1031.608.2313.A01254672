#include <iostream>
#include "BigO.hpp"

int main()
{
    BigO test;

    std::vector<int>nums = {1,2,3,4,5,6,7,8,9,10};

    int resultIter = test.SumOddIte(nums);
    int resultRec = test.SumOddRec(nums);
    

    std::cout<< "Resultado función iterativa: " <<resultIter<< "    // vector = {1,2,3,4,5,6,7,8,9,10}"<< std::endl;
    std::cout<< "Resultado función recursiva: " <<resultRec<< "     // vector = {1,2,3,4,5,6,7,8,9,10}"<< std::endl;
};