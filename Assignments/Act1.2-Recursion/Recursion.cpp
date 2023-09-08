// Aejandro Barrera Bejarano
// A01254672
// ITC
// 15/08/2023


#include <iostream>
#include "Recursion.hpp"

using namespace std;

int main(){

    Recursion<int> recursion;

    std::cout << "sumIterative(5) = " << recursion.sumIterative(5) << std::endl;

    std::cout << "sumRecursive(5) = " << recursion.sumRecursive(5) << std::endl;

    std::cout << "sumFormula(5) = " << recursion.sumFormula(5) << std::endl;

    std::cout << "fibonacciIterative(6) = " << recursion.fibonacciIterative(6) << std::endl;

    std::cout << "fibonacciRecursive(6) = " << recursion.fibonacciRecursive(6) << std::endl;

    std::cout << "bacteriasIterative(4) = " << recursion.bacteriasIterative(4) << std::endl;

    std::cout << "bacteriasRecursive(4) = " << recursion.bacteriasRecursive(4) << std::endl;

    std::cout << "investmentIterative(12, 1000) = " << recursion.investmentIterative(12, 1000) << std::endl;

    std::cout << "investmentRecursive(12, 1000) = " << recursion.investmentRecursive(12, 1000) << std::endl;

    std::cout << "powIterative(2, 5) = " << recursion.powIterative(2, 5) << std::endl;

    std::cout << "powRecursive(2, 5) = " << recursion.powRecursive(2, 5) << std::endl;


    return 0;
};