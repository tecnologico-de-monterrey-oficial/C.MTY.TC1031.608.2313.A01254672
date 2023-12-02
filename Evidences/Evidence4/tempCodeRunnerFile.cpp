#include "Grafo.cpp"

int main() {
    Grafo grafo;
    std::string archivo = "EuropeCities.csv";

    // Leer el archivo y construir el grafo
    grafo = leerArchivo(archivo);

    if (grafo.empty()) {
        std::cerr << "Error al cargar los datos del archivo." << std::endl;
        return 1;
    }

    // Mostrar el menú y procesar las opciones del usuario
    mostrarMenu(grafo);

    return 0;
}