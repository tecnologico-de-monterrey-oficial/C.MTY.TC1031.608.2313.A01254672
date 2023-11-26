#include "hashTable.hpp"
#include <iostream>
#include <fstream>


void cargarMatriculasDesdeArchivo(const std::string& nombreArchivo, HashMatriculas& hm) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        hm.insert(linea);
    }
    archivo.close();
}

int main() {
    HashMatriculas hm;
    cargarMatriculasDesdeArchivo("matriculas.txt", hm);

    char opcion;
    std::string matricula;

    do {
        std::cout << "\nMENU\n";
        std::cout << "1. Insertar Matricula\n";
        std::cout << "2. Eliminar Matricula\n";
        std::cout << "3. Buscar Matricula\n";
        std::cout << "4. Mostrar Tabla Hash\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1':
                std::cout << "Ingrese una matricula para insertar: ";
                std::cin >> matricula;
                hm.insert(matricula);
                break;
            case '2':
                std::cout << "Ingrese una matricula para eliminar: ";
                std::cin >> matricula;
                if (hm.remove(matricula)) {
                    std::cout << matricula << " ha sido eliminada.\n";
                } else {
                    std::cout << matricula << " no encontrada.\n";
                }
                break;
            case '3':
                std::cout << "Ingrese una matricula para buscar: ";
                std::cin >> matricula;
                if (hm.findData(matricula) != -1) {
                    std::cout << matricula << " está en la tabla hash.\n";
                } else {
                    std::cout << matricula << " no encontrada.\n";
                }
                break;
            case '4':
                hm.display();
                break;
            case '5':
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida. Por favor, intente nuevamente.\n";
        }
    } while (opcion != '5');

    return 0;
}

