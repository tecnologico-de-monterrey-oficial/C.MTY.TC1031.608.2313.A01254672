#include "city.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <limits>

void bfs(const Grafo& grafo, const std::string& inicio) {

    if (grafo.find(inicio) == grafo.end()) {
        std::cerr << "Ciudad de inicio no encontrada: " << inicio << std::endl;
        return;
    }

    std::ofstream salida("output608-3.out");
    if (!salida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida para BFS." << std::endl;
        return;
    }

    std::queue<std::string> cola;
    std::unordered_set<std::string> visitados;
    cola.push(inicio);

    while (!cola.empty()) {
        std::string actual = cola.front();
        cola.pop();

        if (visitados.find(actual) == visitados.end()) {
            salida << actual << " ";
            visitados.insert(actual);

            for (const auto& conexion : grafo.at(actual).conexiones) {
                if (visitados.find(conexion.destino) == visitados.end()) {
                    cola.push(conexion.destino);
                    visitados.insert(conexion.destino);
                }
            }
        }
    }

    salida.close();
}

void dfs(const Grafo& grafo, const std::string& inicio) {
    std::ofstream salida("output608-4.out");
    if (!salida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida para DFS." << std::endl;
        return;
    }

    std::stack<std::string> pila;
    std::unordered_set<std::string> visitados;
    pila.push(inicio);

    while (!pila.empty()) {
        std::string actual = pila.top();
        pila.pop();

        if (visitados.find(actual) == visitados.end()) {
            salida << actual << " ";
            visitados.insert(actual);

            for (const auto& conexion : grafo.at(actual).conexiones) {
                pila.push(conexion.destino);
            }
        }
    }

    salida.close();
}

Grafo readFile(const std::string& archivo) {
    Grafo grafo;
    std::ifstream file(archivo);
    std::string linea;
    std::vector<std::string> lineas;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo " << archivo << std::endl;
        return grafo;
    }

    std::getline(file, linea);

    while (std::getline(file, linea)) {
        lineas.push_back(linea);
    }

    for (const auto& l : lineas) {
        std::stringstream ss(l);
        std::string origen, destino, tiempoTren, tiempoCarro;
        int distanciaTren, distanciaCarro;

        std::getline(ss, origen, ',');
        std::getline(ss, destino, ',');
        std::getline(ss, tiempoTren, ',');
        ss >> distanciaTren;
        ss.ignore();
        std::getline(ss, tiempoCarro, ',');
        ss >> distanciaCarro;

        if (grafo.find(origen) == grafo.end()) {
            grafo[origen] = Ciudad(origen);
        }
        grafo[origen].conexiones.push_back(Conexion(destino, tiempoTren, distanciaTren, tiempoCarro, distanciaCarro));
    }

    return grafo;
}

void showSortedCities(const Grafo& grafo) {
    std::vector<std::string> nombres;

    for (const auto& par : grafo) {
        nombres.push_back(par.first);
    }

    std::sort(nombres.begin(), nombres.end());

    std::ofstream salida("output608-1.out");
    if (!salida.is_open()) {
        std::cerr << "Error, file could be open." << std::endl;
        return;
    }

    for (const auto& nombre : nombres) {
        salida << nombre << std::endl;
    }

    salida.close();
}

void mostrarListaAdyacencias(const Grafo& grafo) {
    std::ofstream salida("output608-2.out");
    if (!salida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return;
    }

    for (const auto& ciudad : grafo) {
        salida << ciudad.first << " --> ";
        for (const auto& conexion : ciudad.second.conexiones) {
            salida << conexion.destino << " (" << conexion.distanciaTren << " km en tren), ";
        }
        salida << std::endl;
    }

    salida.close();
}

void rutaMasCortaTren(const Grafo& grafo, const std::string& origen, const std::string& destino) {
    std::unordered_map<std::string, int> distancias;
    std::unordered_map<std::string, std::string> predecesores;
    std::set<std::pair<int, std::string>> cola;

    for (const auto& par : grafo) {
        distancias[par.first] = std::numeric_limits<int>::max();
    }
    distancias[origen] = 0;

    cola.insert({0, origen});

    while (!cola.empty()) {
        std::string actual = cola.begin()->second;
        cola.erase(cola.begin());

        if (actual == destino) {
            break;
        }

        for (const auto& conexion : grafo.at(actual).conexiones) {
            int nuevaDistancia = distancias[actual] + conexion.distanciaTren;

            if (nuevaDistancia < distancias[conexion.destino]) {
                cola.erase({distancias[conexion.destino], conexion.destino});
                distancias[conexion.destino] = nuevaDistancia;
                predecesores[conexion.destino] = actual;
                cola.insert({nuevaDistancia, conexion.destino});
            }
        }
    }

    std::vector<std::string> camino;
    if (distancias[destino] == std::numeric_limits<int>::max()) {
        std::cout << "No existe ruta de " << origen << " a " << destino << std::endl;
        return;
    }

    for (std::string at = destino; at != origen; at = predecesores[at]) {
        camino.push_back(at);
    }
    camino.push_back(origen);
    std::reverse(camino.begin(), camino.end());

    std::cout << "Camino más corto en tren de " << origen << " <---> " << destino << ": ";
    for (const auto& ciudad : camino) {
        std::cout << ciudad << " ";
    }
    std::cout << "\nDistancia total en tren: " << distancias[destino] << " km\n";
}


void rutaMasCortaCarro(const Grafo& grafo, const std::string& origen, const std::string& destino) {
    std::unordered_map<std::string, int> distancias;
    std::unordered_map<std::string, std::string> predecesores;
    std::set<std::pair<int, std::string>> cola;

    for (const auto& par : grafo) {
        distancias[par.first] = std::numeric_limits<int>::max();
    }
    distancias[origen] = 0;

    cola.insert({0, origen});

    while (!cola.empty()) {
        std::string actual = cola.begin()->second;
        cola.erase(cola.begin());

        if (actual == destino) {
            break;
        }

        for (const auto& conexion : grafo.at(actual).conexiones) {
            int nuevaDistancia = distancias[actual] + conexion.distanciaCarro;

            if (nuevaDistancia < distancias[conexion.destino]) {
                cola.erase({distancias[conexion.destino], conexion.destino});
                distancias[conexion.destino] = nuevaDistancia;
                predecesores[conexion.destino] = actual;
                cola.insert({nuevaDistancia, conexion.destino});
            }
        }
    }

    std::vector<std::string> camino;
    if (distancias[destino] == std::numeric_limits<int>::max()) {
        std::cout << "No existe ruta de " << origen << " <---> " << destino << std::endl;
        return;
    }

    for (std::string at = destino; at != origen; at = predecesores[at]) {
        camino.push_back(at);
    }
    camino.push_back(origen);
    std::reverse(camino.begin(), camino.end());

    std::cout << "Camino más corto en carro de " << origen << " a " << destino << ": ";
    for (const auto& ciudad : camino) {
        std::cout << ciudad << " ";
    }
    std::cout << "\nDistancia total en carro: " << distancias[destino] << " km\n";
}

void menu(Grafo& grafo) {
    int opcion;
    std::string inicio, detinoFinal;

    do {
        std::cout << "1. ------> Mostrar ciudades ordenadas\n";
        std::cout << "2. ------> Mostrar lista de adyacencias\n";
        std::cout << "3. ------> BFS\n";
        std::cout << "4. ------> DFS\n";
        std::cout << "5. ------> Ruta más corta en tren\n";
        std::cout << "6. ------> Ruta más corta en carro\n";
        std::cout << "0. ------> Salir\n";
        std::cout << "---->";std::cin >> opcion;

        switch (opcion) {
            case 1:
                showSortedCities(grafo);
                break;
            case 2:
                mostrarListaAdyacencias(grafo);
                break;
            case 3:
                std::cout << "Ingrese ciudad de inicio para BFS: ";
                std::cin >> inicio;
                bfs(grafo, inicio);
                break;
            case 4:
                std::cout << "Ingrese ciudad de inicio para DFS: ";
                std::cin >> inicio;
                dfs(grafo, inicio);
                break;
            case 5:
                std::cout << "Ingrese ciudad de origen para la ruta en tren: ";
                std::cin >> inicio;
                std::cout << "Ingrese ciudad de destino para la ruta en tren: ";
                std::cin >> detinoFinal;
                rutaMasCortaTren(grafo, inicio, detinoFinal);
                break;
            case 6:
                std::cout << "Ingrese ciudad de origen para la ruta en carro: ";
                std::cin >> inicio;
                std::cout << "Ingrese ciudad de destino para la ruta en carro: ";
                std::cin >> detinoFinal;
                rutaMasCortaCarro(grafo, inicio, detinoFinal);
                break;
        }
    } while (opcion != 0);
}