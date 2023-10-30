#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <queue>

struct LogData {
    std::string date;
    std::string ip;
    std::string event;
};

std::vector<LogData> readLogFile(const std::string& fileName) {
    std::vector<LogData> data;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        LogData log;
        std::istringstream iss(line);

        // Read date, time and IP
        iss >> log.date;
        std::string time;
        iss >> time;
        log.date += " " + time; // append time to date
        iss >> log.ip;

        // Read the rest of the line into event
        std::getline(iss, log.event);
        // Remove leading spaces from event
        log.event = log.event.substr(log.event.find_first_not_of(" "));
        
        data.push_back(log);
    }
    return data;
}


void writeToFile(const std::string& fileName, const std::vector<LogData>& data) {
    std::ofstream file(fileName);
    for (const auto& log : data) {
        file << log.date << " " << log.ip << " " << log.event << "\n";
    }
}

void heapify(std::vector<LogData>& data, int n, int i, bool ascending) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    auto comparator = [ascending](const LogData& a, const LogData& b) {
        if (a.ip == b.ip) {
            return ascending ? a.date < b.date : a.date > b.date;
        }
        return ascending ? a.ip < b.ip : a.ip > b.ip;
    };

    if (left < n && comparator(data[largest], data[left])) {
        largest = left;
    }

    if (right < n && comparator(data[largest], data[right])) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest, ascending);
    }
}

void heapSort(std::vector<LogData>& data, bool ascending=true) {
    int n = data.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(data, n, i, ascending);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0, ascending);
    }
}


void getTopIPs(const std::vector<LogData>& data) {
    
    std::map<std::string, int> counts;
    for (const auto& log : data) {
        std::istringstream iss(log.event);
        std::string time, ip, error;
        std::getline(iss, time, ' ');
        std::getline(iss, ip, ' ');
        std::getline(iss, error);
        counts[ip]++;
    }

    auto cmp = [](const std::pair<std::string, int>& left, const std::pair<std::string, int>& right) {
        return left.second > right.second;
    };

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(cmp)> queue(cmp);

    for (const auto& count : counts) {
        queue.push(count);
        if (queue.size() > 10) {
            queue.pop();
        }
    }

    while (!queue.empty()) {
        std::pair<std::string, int> top = queue.top();
        std::cout << "IP: " << top.first << ", Repeticiones: " << top.second << "\n";
        queue.pop();
    }
}


bool searchIP(const std::vector<LogData>& data, const std::string& IP) {
    for (const auto& log : data) {
        std::istringstream iss(log.event);
        std::string time, ip, error;
        std::getline(iss, time, ' ');
        std::getline(iss, ip, ' ');
        std::getline(iss, error);
        std::cout << ip << std::endl;
        if (ip == IP) {
            return true;
        }
    }
    return false;
}


int main() {
    std::vector<LogData> data = readLogFile("log608-3.txt");
    int choice;
    std::string targetIP;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Ordena los datos por IP, fecha y hora de mayor a menor.\n";
        std::cout << "2. Ordena los datos por IP, fecha y hora de menor a mayor.\n";
        std::cout << "3. Despliega en pantalla cuales son las 10 ip's con mayor número de registros.\n";
        std::cout << "4. Búsqueda de una ip en un árbol binario de búsqueda.\n";
        std::cout << "5. Salir.\n";
        std::cout << "-------->: ";
        std::cin >> choice;

        switch(choice) {
           case 1:
                heapSort(data, false);
                writeToFile("output608-1.out", data);
                std::cout << "Listo.\n";
                break;
            case 2:
                heapSort(data, true);
                writeToFile("output608-2.out", data);
                std::cout << "Listo.\n";
                break;
            case 3: {
                getTopIPs(data);
                std::cout << "Listo.\n";
                break;
            }
            case 4:
                std::cout << "Enter the IP: ";
                std::cin >> targetIP;
                if (searchIP(data, targetIP)) {
                    std::cout << "IP si está!\n";
                } else {
                    std::cout << "IP no está.\n";
                }
                break;
            case 5:
                return 0;
            default:
                std::cout << "No Valido.\n";
        }
    }

    return 0;
}
