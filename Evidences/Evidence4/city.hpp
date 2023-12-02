#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

struct Conexion {
    std::string destino;
    std::string tiempoTren;
    int distanciaTren;
    std::string tiempoCarro;
    int distanciaCarro;

    Conexion(const std::string& dest, const std::string& tiempoTren, int distanciaTren, 
             const std::string& tiempoCarro, int distanciaCarro) 
        : destino(dest), tiempoTren(tiempoTren), distanciaTren(distanciaTren),
          tiempoCarro(tiempoCarro), distanciaCarro(distanciaCarro) {}
};

struct Ciudad {
    std::string nombre;
    std::list<Conexion> conexiones;

    Ciudad() : nombre("") { }
    explicit Ciudad(const std::string& nombre) : nombre(nombre) { }
};

using Grafo = std::unordered_map<std::string, Ciudad>;