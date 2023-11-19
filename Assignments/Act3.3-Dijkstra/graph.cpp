#include <iostream>
#include "graph.hpp"

int main() {
    Graph<int> graph;
    int opcion;
    int vertex, from, to;

    do {
        std::cout << "---- Menú del Grafo ----\n";
        std::cout << "1. Agregar vértice\n";
        std::cout << "2. Agregar arista\n";
        std::cout << "3. Eliminar vértice\n";
        std::cout << "4. Eliminar arista\n";
        std::cout << "5. Mostrar grafo\n";
        std::cout << "6. Recorrido BFS\n";
        std::cout << "7. Recorrido DFS\n";
        std::cout << "8. Camino más corto con Dijkstra\n";
        std::cout << "9. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el valor del vértice a agregar: ";
                std::cin >> vertex;
                graph.addVertex(vertex);
                break;
            case 2:
                std::cout << "Ingrese el valor del vértice de origen: ";
                std::cin >> from;
                std::cout << "Ingrese el valor del vértice de destino: ";
                std::cin >> to;
                graph.addEdge(from, to);
                break;
            case 3:
                std::cout << "Ingrese el valor del vértice a eliminar: ";
                std::cin >> vertex;
                graph.removeVertex(vertex);
                break;
            case 4:
                std::cout << "Ingrese el valor del vértice de origen de la arista a eliminar: ";
                std::cin >> from;
                std::cout << "Ingrese el valor del vértice de destino de la arista a eliminar: ";
                std::cin >> to;
                graph.removeEdge(from, to);
                break;
            case 5:
                graph.print();
                break;
            case 6:
                std::cout << "Ingrese el valor del vértice inicial para BFS: ";
                std::cin >> vertex;
                graph.BFS(vertex);
                break;
            case 7:
                std::cout << "Ingrese el valor del vértice inicial para DFS: ";
                std::cin >> vertex;
                graph.DFS(vertex);
                break;
            case 8:
                std::cout << "Ingrese el vértice inicial para Dijkstra: ";
                std::cin >> vertex;
                graph.DijkstraShortestPath(vertex);
                break;
            case 9:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 9);

    return 0;
}
