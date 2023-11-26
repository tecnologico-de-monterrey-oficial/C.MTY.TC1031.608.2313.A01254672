#pragma once

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

class HashMatriculas {
private:
    std::vector<std::list<std::string>> table;
    int hashFunction(const std::string& matricula);

public:
    HashMatriculas(int size = 10);
    void insert(const std::string& matricula);
    bool remove(const std::string& matricula);
    int findData(const std::string& matricula);
    void display();
};

void loadMatriculasFromFile(const std::string& filename, HashMatriculas& hm);

HashMatriculas::HashMatriculas(int size) : table(size) {}

int HashMatriculas::hashFunction(const std::string& matricula) {
    int hash = 0;
    for (char c : matricula) {
        hash = hash * 31 + c;
    }
    return hash % table.size();
}

void HashMatriculas::insert(const std::string& matricula) {
    int index = hashFunction(matricula);
    table[index].push_back(matricula);
}

bool HashMatriculas::remove(const std::string& matricula) {
    int index = hashFunction(matricula);
    auto& list = table[index];
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == matricula) {
            list.erase(it);
            return true;
        }
    }
    return false;
}

int HashMatriculas::findData(const std::string& matricula) {
    int index = hashFunction(matricula);
    auto& list = table[index];
    for (const auto& item : list) {
        if (item == matricula) {
            return index;
        }
    }
    return -1;
}

void HashMatriculas::display() {
    for (int i = 0; i < table.size(); ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& matricula : table[i]) {
            std::cout << matricula << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }
}

void loadMatriculasFromFile(const std::string& filename, HashMatriculas& hm) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        hm.insert(line);
    }
}

