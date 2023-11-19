#pragma once

#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <stack>

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
    void BFS(const T& startVertex);
    void DFS(const T& startVertex);
};

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(const T& vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = std::set<T>();
    }
}

template <typename T>
void Graph<T>::addEdge(const T& from, const T& to) {
    if (adjList.find(from) != adjList.end() && adjList.find(to) != adjList.end()) {
        adjList[from].insert(to);
    }
}

template <typename T>
void Graph<T>::removeVertex(const T& vertex) {
    if (adjList.find(vertex) != adjList.end()) {
        adjList.erase(vertex);
        for (auto& pair : adjList) {
            pair.second.erase(vertex);
        }
    }
}

template <typename T>
void Graph<T>::removeEdge(const T& from, const T& to) {
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

template <typename T>
void Graph<T>::BFS(const T& startVertex) {
    std::queue<T> queue;
    std::unordered_map<T, bool> visited;
    queue.push(startVertex);
    visited[startVertex] = true;

    while (!queue.empty()) {
        T current = queue.front();
        queue.pop();
        std::cout << current << " ";

        for (const T& neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    std::cout << std::endl;
}

template <typename T>
void Graph<T>::DFS(const T& startVertex) {
    std::stack<T> stack;
    std::unordered_map<T, bool> visited;
    stack.push(startVertex);

    while (!stack.empty()) {
        T current = stack.top();
        stack.pop();

        if (!visited[current]) {
            std::cout << current << " ";
            visited[current] = true;
        }

        for (const T& neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}