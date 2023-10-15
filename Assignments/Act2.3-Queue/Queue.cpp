#include <iostream>
#include "Queue.h"
#include <stdexcept>

using namespace std;

int main() {
    Queue<int> myList;
    int choice, data, newData, index;
    bool success;

    do {
        cout << "\nOperaciones de Queue" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Agregar un elemento al final de la lista" << endl;
        cout << "2. Elimina el primer elemento de la lista" << endl;
        cout << "3. Regresa el primer elemento de la lista" << endl;
        cout << "4. Imprime toda la lista" << endl;
        cout << "5. Salir" << endl;

        cout << "\nIngrese su elección: ";
        cin >> choice;

        Queue<int> newList = myList;

        switch(choice) {
            case 5:
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
                std::cout << myList.front() << std::endl;
                myList.print();
                break;
            case 4:
                myList.print();
                break;
        }
    } while(choice != 5);

    return 0;
}

