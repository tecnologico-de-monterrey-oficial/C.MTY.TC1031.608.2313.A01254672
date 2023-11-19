#pragma once

#include <unordered_map>
#include <vector>
#include <set>

template <typename T>
class Graph {
private:
    std::unordered_map<T, std::set<T>> adjList;

public:
    Graph();
    void addVertex(const T& vertex);
    void addEdge(const T& from, const T& to);
    void removeVertex(const T& vertex);
    void removeEdge(const T& from, const T& to);
    void print();
};

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(const T& vertex) {
    // Agregar vértice solo si no existe
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = std::set<T>();
    }
}

template <typename T>
void Graph<T>::addEdge(const T& from, const T& to) {
    // Agregar arista solo si ambos vértices existen
    if (adjList.find(from) != adjList.end() && adjList.find(to) != adjList.end()) {
        adjList[from].insert(to);
        // Si el grafo es no dirigido, descomentar la siguiente línea:
        // adjList[to].insert(from);
    }
}

template <typename T>
void Graph<T>::removeVertex(const T& vertex) {
    // Eliminar vértice y todas las aristas relacionadas
    if (adjList.find(vertex) != adjList.end()) {
        adjList.erase(vertex);
        for (auto& pair : adjList) {
            pair.second.erase(vertex);
        }
    }
}

template <typename T>
void Graph<T>::removeEdge(const T& from, const T& to) {
    // Eliminar arista si existe
    if (adjList.find(from) != adjList.end()) {
        adjList[from].erase(to);
    }
}

template <typename T>
void Graph<T>::print() {
    for (const auto& pair : adjList) {
        std::cout << pair.first << ": ";
        for (const auto& vertex : pair.second) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
}
