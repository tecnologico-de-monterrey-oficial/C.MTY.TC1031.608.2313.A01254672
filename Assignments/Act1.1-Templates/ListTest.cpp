#include <iostream>
#include <vector>
using namespace std;

#include "List.hpp"

int main() {
    List<int> list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.insert(25);

    list.print();

    std::cout << "El numero mas alto en la lista es: " << list.getMax() << std::endl;
    std::cout << "El tamaño de la lista es: " << list.getSize() << std::endl;
    std::cout << "El numero en el indice 2 es: " << list.getData(2) << std::endl;
    std::cout << "Ahora removere el ultimo elemento de la lista: "; list.removeLast();
    std::cout << "El tamaño de la lista actual es: " << list.getSize() << std::endl;

    list.print();

    std::cout<<" "<<std::endl;

    List<string> listS;

    listS.insert("Hola");
    listS.insert("Crayola");
    listS.insert("tu cajita");
    listS.insert("de Colores");

    listS.print();
    std::cout << "El numero mas alto en la lista es: " << listS.getMax() << std::endl;
    std::cout << "El tamaño de la lista es: " << listS.getSize() << std::endl;
    std::cout << "El numero en el indice 2 es: " << listS.getData(2) << std::endl;
    std::cout << "Ahora removere el ultimo elemento de la lista: "; listS.removeLast();
    std::cout << "El tamaño de la lista actual es: " << listS.getSize() << std::endl;
    listS.print();

    
    return 0;
}