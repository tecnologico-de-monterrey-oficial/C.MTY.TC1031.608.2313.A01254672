#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST<int> bst;
    int choice, data, level;
    bool found;
    do {
        cout << endl;
        cout << "1. Insertar un dato" << endl;
        cout << "2. Buscar un dato" << endl;
        cout << "3. Eliminar un dato" << endl;
        cout << "4. Visitar el árbol" << endl;
        cout << "5. Imprimir el árbol" << endl;
        cout << "6. Verificar si el árbol está vacío" << endl;
        cout << "7. Obtener la altura del árbol" << endl;
        cout << "8. Mostrar los ancestros de un dato" << endl;
        cout << "9. Obtener el nivel de un dato" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingresa tu elección: ";
        cin >> choice;
        
        switch (choice) {
            case 0:
                break;
            case 1:
                cout << "Ingresa el dato a insertar: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Ingresa el dato a buscar: ";
                cin >> data;
                found = bst.find(data);
                if (found) {
                    cout << "El dato está en el árbol." << endl;
                } else {
                    cout << "El dato no está en el árbol." << endl;
                }
                break;
            case 3:
                cout << "Ingresa el dato a eliminar: ";
                cin >> data;
                found = bst.remove(data);
                if (found) {
                    cout << "El dato fue eliminado del árbol." << endl;
                } else {
                    cout << "El dato no está en el árbol." << endl;
                }
                break;
            case 4:
                cout << "1. Preorden" << endl;
                cout << "2. Inorden" << endl;
                cout << "3. Postorden" << endl;
                cout << "4. Por niveles" << endl;
                cout << "Ingresa tu elección: ";
                cin >> data;
                bst.visit(data);
                break;
            case 5:
                bst.print();
                break;
            case 6:
                if (bst.isEmpty()) {
                    cout << "El árbol está vacío." << endl;
                } else {
                    cout << "El árbol no está vacío." << endl;
                }
                break;
            case 7:
                cout << "La altura del árbol es: " << bst.height() << endl;
                break;
            case 8:
                cout << "Ingresa el dato del que deseas conocer los ancestros: ";
                cin >> data;
                bst.ancestors(data);
                break;
            case 9:
                cout << "Ingresa el dato del que deseas conocer el nivel: ";
                cin >> data;
                level = bst.whatLevelAmI(data);
                if (level == -1) {
                    cout << "El dato no está en el árbol." << endl;
                } else {
                    cout << "El nivel del dato es: " << level << endl;
                }
                break;
            default:
                cout << "Elección inválida." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
