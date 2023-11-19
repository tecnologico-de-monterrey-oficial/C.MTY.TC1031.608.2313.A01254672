#pragma once

#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <climits>


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
    void DijkstraShortestPath(const T& startVertex);
};

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(const T& vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex].insert(vertex);
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

template <typename T>
void Graph<T>::DijkstraShortestPath(const T& startVertex) {

  std::unordered_map<T, int> distances;
  std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<>> pq;
  std::unordered_map<T, T> previous;
  
  for (auto& vertex : adjList) {
    distances[vertex.first] = INT_MAX;
  }
  distances[startVertex] = 0;
  
  pq.push({0, startVertex});
  
  while(!pq.empty()) {
    T currentVertex = pq.top().second; 
    pq.pop();
    
    for(auto& neighbor : adjList[currentVertex]) {
      int distance = distances[currentVertex] + 1;
      
      if(distance < distances[neighbor]) {
        distances[neighbor] = distance;
        previous[neighbor] = currentVertex;
        pq.push({distance, neighbor});  
      }
    }
  }

  for (auto& distance : distances) {
    std::cout << "Distancia de " << startVertex << " a " << distance.first << " es " << distance.second << "\n"; 
  }
}

