#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <map>
#include <string>
#include <algorithm>
#include <utility>


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
    
    // Look up the month in the hash table and return its value
    return month_map[month];
}

std::string Fix_date_format(std::string& input) 
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
    std::string result = year + month + day + new_hour;
    return result;
}

void ReadFile(const std::string& file, std::vector<std::pair<std::string, std::string>>& pairVector)
{
    std::ifstream infile(file);
    std::string line;

    if (infile.is_open()) 
    {
        while (getline(infile, line)) //Iterate line by line of the file
        { 
            std::istringstream iss(line);
            std::string word;
            int words = 0; //The "words" variable keeps track of the current word position in the line as we iterate over it using the loop
            std::string message = "";
            std::string date = "";
            while (iss >> word) 
            {
                if (words < 1) //The first word of each line will be passed through the Month_to_num function to convert it to a numerical month value
                {
                    std::string month = Month_to_Num(word);
                    date += month + " ";
                }
                else
                { 
                    date += word + " ";
                } 
                words++;
            }
            message += line;
            pairVector.push_back(std::make_pair(Fix_date_format(date), message));
        }
        infile.close();
    }
}

void QuickSort(std::vector<std::pair<std::string, std::string>>& data)
{
    if (data.size() <= 1)
    {
        return;
    }
    std::pair<std::string, std::string> pivot = data[0];
    std::vector<std::pair<std::string, std::string>> less, greater;
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i].first <= pivot.first) //Fill the less vector with all the elements that have a key value less than or equal to the pivot
        {
            less.push_back(data[i]);
        }
        else
        {
            greater.push_back(data[i]); //Fill the less vector with all the elements that have a key value greater than the pivot
        }  
    }
    // Repeat the step two
    QuickSort(less); 
    QuickSort(greater);
    //Time to concatenate the sorted less and greater vectors with the pivot in between to form the final sorted vector
    data.clear();
    data.reserve(less.size() + 1 + greater.size());
    data.insert(data.end(), less.begin(), less.end());
    data.push_back(pivot);
    data.insert(data.end(), greater.begin(), greater.end());

    std::ofstream outfile("output608.txt");
    if (outfile.is_open()) 
    {
        for (auto record : data) 
        {
            outfile << record.second << std::endl;
        }
        outfile.close();
    }
}

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

void Binary_search(std::vector<std::pair<std::string, std::string>> data, long long initial_date, long long final_date)
{
    std::vector<std::string> results;

    // Do binary search to find the first record in the date range
    int left = 0;
    int right = data.size() - 1;
    int initial_date_position = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long current_date = std::stoll(data[mid].first);

        if (current_date < initial_date)
        {
            left = mid + 1;
        }
        else if (current_date > initial_date)
        {
            right = mid - 1;
        }
        else
        {
            initial_date_position = mid;
            break;
        }
    }
    if (initial_date_position == -1)
    {
        initial_date_position = left;
    }

    // Iterate to find values within the given range
    for (int i = initial_date_position; i < data.size(); i++)
    {   
        long long index = std::stoll(data[i].first);
        if (index > final_date)
        {
            break;
        } 
        results.push_back(data[i].second);
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



int main()
{
    std::vector<std::pair<std::string, std::string>> data;
    ReadFile("log608.txt", data);
    QuickSort(data);
    
    int option = 99;
    while (option != 0)
    {
        std::cout << std::endl;
        std::cout << "Bienvenido al buscador de registros (PRESS 1 to continue | PRESS 0 to exit)... --->"; std::cin >> option;
        if (option == 0)
            break;
        std::cout << std::endl;

        std::string initial_date;
        long long initial_date_int = fill_date(initial_date);

        std::string final_date;
        long long final_date_int = fill_date(final_date);

        std::cout << "(PRESS 1 to search | PRESS 2 to enter new dates)... -->"; std::cin >> option;
        if (option == 1)
        {
            Binary_search(data,initial_date_int,final_date_int);
        }
        std::cout << std::endl;
    }
}
