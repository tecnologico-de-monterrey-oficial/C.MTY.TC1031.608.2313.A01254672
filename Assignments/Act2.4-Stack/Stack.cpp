#include <iostream>
#include "Stack.h"
#include <stdexcept>

using namespace std;

int main() {
    Stack<int> myList;
    int choice, data, newData, index;
    bool success;

    do {
        cout << "\nOperaciones de Queue" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Agregar un elemento a la pila" << endl;
        cout << "2. Elimina el elemento de arriba de la pila" << endl;
        cout << "3. Regresa el elemento de arriba de la pila" << endl;
        cout << "4. Regresa si la pila esta vacía o no" << endl;
        cout << "5. Imprime toda la pila" << endl;
        cout << "6. Salir" << endl;

        cout << "\nIngrese su elección: ";
        cin >> choice;

        Stack<int> newList = myList;

        switch(choice) {
            case 6:
                cout << "\nGracias por participar:)" << endl;
                break;
            case 1:
                cout << "\nIngrese el valor del elemento: ";
                cin >> data;
                myList.push(data);
                myList.print();
                break;
            case 2:
                myList.pop();
                myList.print();
                break;
            case 3:
                std::cout << myList.top() << std::endl;
                myList.print();
                break;
            case 4:
                std::cout << myList.isEmpty() << std::endl;
                myList.print();
                break;
            case 5:
                myList.print();
                break;
        }
    } while(choice != 6);

    return 0;
}

