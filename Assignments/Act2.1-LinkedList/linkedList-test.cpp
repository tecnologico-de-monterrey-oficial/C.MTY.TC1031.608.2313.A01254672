#include <iostream>
#include "linkedList.hpp"

using namespace std;

int main() {
     linkedList<int> myList;
    int choice, data, newData, index;
    bool success;

    do {
        cout << "\nOperaciones de Lista Enlazada" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Agregar un elemento al principio de la lista" << endl;
        cout << "2. Agregar un elemento al final de la lista" << endl;
        cout << "3. Insertar un elemento a la derecha del índice dado" << endl;
        cout << "4. Borrar un elemento dado de la lista" << endl;
        cout << "5. Borrar un elemento en una posición de la lista" << endl;
        cout << "6. Obtener el elemento de una posición dada de la lista" << endl;
        cout << "7. Actualizar un elemento dado de la lista" << endl;
        cout << "8. Actualizar un elemento que se encuentra en una posición dada de la lista" << endl;
        cout << "9. Encuentra un elemento dado en la lista" << endl;
        cout << "10. Obtener el elemento de una posición de la lista (sobrecarga operador [])" << endl;
        cout << "11. Actualizar el elemento de una posición de la lista (sobrecarga operador [])" << endl;
        cout << "12. Iguala una lista con los datos de otra lista (sobrecarga operador =) (Duplica la lista)" << endl;
        cout << "13. Salir" << endl;

        cout << "\nIngrese su elección: ";
        cin >> choice;

        linkedList<int> newList = myList;

        switch(choice) {
            case 13:
                cout << "\nGracias por participar:)" << endl;
                break;
            case 1:
                cout << "\nIngrese el valor del elemento: ";
                cin >> data;
                myList.addFirst(data);
                myList.print();
                break;
            case 2:
                cout << "\nIngrese el valor del elemento: ";
                cin >> data;
                myList.addLast(data);
                myList.print();
                break;
            case 3:
                cout << "\nIngrese el valor del elemento: ";
                cin >> data;
                cout << "\nIngrese el índice después del cual desea insertar el elemento: ";
                cin >> index;
                try {
                    myList.insert(index+1, data);
                    myList.print();
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 4:
                cout << "\nIngrese el valor del elemento que desea borrar: ";
                cin >> data;
                success = myList.deleteData(data);
                if (success) {
                    cout << "Elemento borrado exitosamente." << endl;
                    myList.print();
                } else {
                    cout << "El elemento no se encontró en la lista." << endl;
                }
                break;
            case 5:
                cout << "\nIngrese el índice del elemento que desea borrar: ";
                cin >> index;
                try {
                    myList.deleteAt(index);
                    myList.print();
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 6:
                cout << "\nIngrese el índice del elemento que desea obtener: ";
                cin >> index;
                try {
                    data = myList.getData(index);
                    cout << "El valor del elemento es: " << data << endl;
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 7:
                cout << "\nIngrese el valor del elemento que desea actualizar: ";
                cin >> data;
                cout << "\nIngrese el nuevo valor del elemento: ";
                cin >> newData;
                myList.updateData(data, newData);
                myList.print();
                break;
            case 8:
                cout << "\nIngrese el índice del elemento que desea actualizar: ";
                cin >> index;
                cout << "\nIngrese el nuevo valor del elemento: ";
                cin >> newData;
                try {
                    myList.updateAt(index, newData);
                    myList.print();
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 9:
                cout << "\nIngrese el valor del elemento que desea encontrar: ";
                cin >> data;
                index = myList.findData(data);
                if (index != -1) {
                    cout << "El elemento se encuentra en el índice: " << index << endl;
                } else {
                    cout << "El elemento no se encontró en la lista." << endl;
                }
                break;
            case 10:
                cout << "\nIngrese el índice del elemento que desea obtener: ";
                cin >> index;
                try {
                    data = myList[index];
                    cout << "El valor del elemento es: " << data << endl;
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 11:
                cout << "\nIngrese el índice del elemento que desea actualizar: ";
                cin >> index;
                cout << "\nIngrese el nuevo valor del elemento: ";
                cin >> newData;
                try {
                    myList[index] = newData;
                    myList.print();
                } catch(const out_of_range& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            default:
                cerr << "\nError: Elección inválida. Intente nuevamente." << endl;
            case 12:
                linkedList<int> newList = myList;
                myList = newList;
                cout << "\nLa lista ha sido duplicada." << endl;
                break;
        }
    } while(choice != 13);

    return 0;
}
