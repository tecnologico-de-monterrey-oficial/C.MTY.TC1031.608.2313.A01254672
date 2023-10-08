#include <iostream>
#include "DoublyLinkedList-2.hpp"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;




std::string Month_to_Num(std::string month)
{
    std::map<std::string, std::string> month_map = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };
    
    // Search the month in the hash table and return its value
    return month_map[month];
}

void Fix_date_format(std::string& input) 
{
    std::istringstream iss(input);
    std::string month, day, year, hour;
    
    // Extract the four words from the input string
    iss >> month >> day >> year >> hour;
    
    // Remove double point from the hour format
    std::string new_hour = "";
    for (auto letter : hour)
    {
        if (letter != ':')
        {
            new_hour += letter;
        }
    }
    // Concatenate the word in the format of preference
    input = year + month + day + new_hour;
    //return result;
}

void ReadFile(const std::string& file, DoublylinkedList<std::string>& list) 
{
  std::ifstream infile(file);
  std::string line;

  if (infile.is_open())
  {
    while (getline(infile, line)) 
    {
      std::istringstream iss(line);
      std::string word; 
      int words = 0;
      std::string date = "";
      std::string message = "";

      while (iss >> word)  
      {
        if (words < 1) 
        {
          std::string month = Month_to_Num(word);
          date += month + " "; 
        }
        if (words > 0 && words < 4)
        {
          date += word + " ";
        }
        words++;
      }
      message += line;
      Fix_date_format(date);
      date += " " + message;
      list.addLast(date); 
    }
    infile.close();
  }
}
/*
void QuickSort(DoublyLinkedList<string>& myList) 
{

  if (myList.getSize() <= 1) {
    return;
  }

  std::pair<std::string, std::string> pivot = myList[0];

  DoublyLinkedList<std::string> less;
  DoublyLinkedList<std::string> greater;

  for (int i = 1; i < myList.getSize(); i++) {
    if (myList[i].first <= pivot.first) {
      less.addLast(myList[i]);
    }
    else {
      greater.addLast(myList[i]); 
    }
  }

  QuickSort(less);
  QuickSort(greater);

  myList.clear();
  
  // Concatenate the sorted lists 
  myList = less;
  myList.addLast(pivot);
  myList = greater;
  
  // Write sorted data to output file
  std::ofstream outfile("output602-1.out");
  if (outfile.is_open()) {
    for (int i = 0; i < myList.getSize(); i++) {
      outfile << myList[i].second << "\n";
    }
    outfile.close();
  }
  std::ofstream outfile("output602-1.out");
  if (outfile.is_open()) {
    for (int i = 0; i < myList.getSize(); i++) {
      outfile << myList[i].second << "\n";
    }
    outfile.close();
  }
}
*/
/*
long long fill_date(std::string date)
{
    std::string year, month, day, hour;
    
    //Enter date
    std::cout << "Año (YYYY) ----->"; std::cin >> year;
    std::cout << std::endl;
    std::cout << "mes {Jan},{Feb},{Mar},{Apr},{May},{Jun},{Jul},{Aug},{Sep},{Oct},{Nov},{Dec} ----->"; std::cin >> month;
    std::cout << std::endl;
    std::cout << "Día (DD) ----->"; std::cin >> day;
    std::cout << std::endl;
    std::cout << "Hora (HH:MM:SS) ----->"; std::cin >> hour;
    std::cout << std::endl;
    date = Month_to_Num(month) + " " + day  + " " + year + " " + hour;
    std::cout << std::endl;

    date = Fix_date_format(date);
    long long date_int = std::stoll(date);
    return date_int;
}

void Binary_search(DoublyLinkedList<std::string> list, long long initial_date, long long final_date) {

  DoublyLinkedList<std::string> results;

  int left = 0;
  int right = list.getSize() - 1;
  int initial_date_position = -1;

  while (left <= right) {

    int mid = left + (right - left) / 2;
    long long current_date = std::stoll(list[mid].first);

    if (current_date < initial_date) {
      left = mid + 1;
    }
    else if (current_date > initial_date) {
      right = mid - 1;   
    }
    else {
      initial_date_position = mid;
      break;
    }
  }

  if (initial_date_position == -1) {
    initial_date_position = left;
  }

  for (int i = initial_date_position; i < list.getSize(); i++) {

    long long index = std::stoll(list[i].first);
    
    if (index > final_date) {
      break;
    }

    results.addLast(list[i].second);
  }

  //Overwrite the file with the results
  std::ofstream outfile("range608.txt");
  if (outfile.is_open()) 
  {
      for (auto record : results) 
      {
          outfile << record << std::endl;
      }
      outfile.close();
  }

  //Display results in the terminal
  for (auto record : results) 
      {
          std::cout << record << std::endl;
      }
}
*/


int main(){
  DoublylinkedList<string> myList;
  ReadFile("log608-2.txt", myList);
  myList.swapSort(myList.getHead(), myList.getTail());
  myList.print();
  myList.print2Format();
  int choice;
  std::string firstValue, lastValue;
  bool success;

  do {
      cout << "\nBienvenido.." << endl;
      cout << "-----------------------" << endl;
      cout << "1. Rango de IP's" << endl;
      cout << "2. Salir" << endl;
      cin>>choice;
      switch(choice) {
            case 2:
                cout << "\nGracias por participar:)" << endl;
                break;
            case 1:
                cout << "\nIngrese el inicio del rango: ";
                cin >> firstValue;
                cout << "\nIngrese el fin del rango: ";
                cin >> lastValue;
                myList.showValues(firstValue, lastValue);
                myList.reverseIP();
                myList.SumOfData();
                break;
        }
  
  }while(choice != 2);
};
