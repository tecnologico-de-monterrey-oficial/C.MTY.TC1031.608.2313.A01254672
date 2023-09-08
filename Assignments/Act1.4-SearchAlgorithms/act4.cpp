// Aejandro Barrera Bejarano
// A01254672
// ITC
// 25/08/2023


#include <iostream>
#include "act4.hpp"
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

vector<std::string> hola = {"AACCZZTTVXX","AAB","CCAAXWWTT","XXYYZZAAC"};


int main()
{
   

    Solution act;

    int x = 1;

    while (x != 0)
    {
        std::cout << "solicita al usuario un número entero entre 1 y 1,000,000 y muestra en pantalla si el número se encuentra en la lista o no (teclee 0 para salir). Numero: "; std::cin>> x;

        srand(time(0));
        chrono::high_resolution_clock::time_point begin;
        chrono::high_resolution_clock::time_point end;
        startTime(begin);

        int result = act.sequentialSearch(x);

        std::cout << "el metodo secuencial tardo: "; getTime(begin, end);
        std::cout << "Index: " << result << std::endl;

        srand(time(0));
        chrono::high_resolution_clock::time_point begin2;
        chrono::high_resolution_clock::time_point end2;
        startTime(begin2);

        int result2 = act.binarySearch(x);

        std::cout << "el metodo binario tardo: "; getTime(begin2, end2);
        std::cout << "Index: " << result2 << std::endl;
    }

    std::cout << "\n" << "PARTE 2 DE LA ACT" << std::endl;

    srand(time(0));
    chrono::high_resolution_clock::time_point begin3;
    chrono::high_resolution_clock::time_point end3;
    startTime(begin3);
    act.uniqueCharSeq(hola);
    std::cout << "el metodo secuencial tardo: "; getTime(begin3, end3);

   



    return 0;
}

