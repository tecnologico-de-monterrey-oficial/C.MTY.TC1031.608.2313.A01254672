#include <iostream>
#include "Heap.h"
#include "minHeap.h" 

int main() {
    int choice;
    Heap<int> maxHeap; 
    MinHeap<int> minHeap;

    do {
        std::cout << "----- Menú -----" << std::endl;
        std::cout << "1. Insertar elemento en el Max Heap" << std::endl;
        std::cout << "2. Insertar elemento en el Min Heap" << std::endl;
        std::cout << "3. Eliminar elemento del Max Heap" << std::endl;
        std::cout << "4. Eliminar elemento del Min Heap" << std::endl;
        std::cout << "5. Mostrar elemento máximo del Max Heap" << std::endl;
        std::cout << "6. Mostrar elemento mínimo del Min Heap" << std::endl;
        std::cout << "7. Ordenar elementos del Max Heap (ascendente)" << std::endl;
        std::cout << "8. Ordenar elementos del Max Heap (descendente)" << std::endl;
        std::cout << "9. Imprimir el Max Heap" << std::endl;
        std::cout << "10. Imprimir el Min Heap" << std::endl;
        std::cout << "11. Salir" << std::endl;
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Ingrese el valor a insertar en el Max Heap: ";
                std::cin >> value;
                maxHeap.push(value);
                break;
            }
            case 2: {
                int value;
                std::cout << "Ingrese el valor a insertar en el Min Heap: ";
                std::cin >> value;
                minHeap.push(value);
                break;
            }
            case 3: {
                maxHeap.pop();
                break;
            }
            case 4: {
                minHeap.pop();
                break;
            }
            case 5: {
                int max = maxHeap.top();
                std::cout << "El elemento máximo del Max Heap es: " << max << std::endl;
                break;
            }
            case 6: {
                int min = minHeap.top();
                std::cout << "El elemento mínimo del Min Heap es: " << min << std::endl;
                break;
            }
            case 7: {
                Heap<int> maxHeapCopy = maxHeap;

                while (!maxHeapCopy.empty()) {
                    int max = maxHeapCopy.top();
                    maxHeapCopy.pop();
                    std::cout << max << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 8: {
                Heap<int> maxHeapCopy = maxHeap;

                std::vector<int> descendingOrder;
                while (!maxHeapCopy.empty()) {
                    int max = maxHeapCopy.top();
                    descendingOrder.push_back(max);
                    maxHeapCopy.pop();
                }
                for (int i = descendingOrder.size() - 1; i >= 0; i--) {
                    std::cout << descendingOrder[i] << " ";
                }
                std::cout << std::endl;
                break;
            }
            case 9: {
                maxHeap.print();
                break;
            }
            case 10: {
                minHeap.print();
                break;
            }
            case 11: {
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
                break;
            }
        }

    } while (choice != 11);

    return 0;
}
