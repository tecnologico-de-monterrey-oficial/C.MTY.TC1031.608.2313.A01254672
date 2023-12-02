#include "graph.cpp"

int main() {
    Grafo grafo;
    std::string archivo = "EuropeCities.csv";

    grafo = readFile(archivo);

    if (grafo.empty()) {
        std::cerr << "Error, no file" << std::endl;
        return 1;
    }
    menu(grafo);

    return 0;
}