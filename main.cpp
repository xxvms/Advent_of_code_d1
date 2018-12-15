#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

/* 1.create function that reads file
 * 2. read input and add to it to the local variable
 * 3. remember to add const
*/

void read_file(std::vector<int> &import_data);
void summary(const std::vector<int> &data_to_sum, std::vector<int> &bank);
//void twice(const std::vector<int> &data_to_find);


int main() {

    std::vector<int>data_file{}; // to keep all frequences from file
    std::vector<int>bank{};      // to keep summary of each iteration

    read_file(data_file);
    summary(data_file, bank);

    return 0;
}

// getting numbers from file
void read_file(std::vector<int> &import_data){

    std::ifstream file("data.txt");
    std::string data;
    while (std::getline(file, data)){
        int d = std::atoi(data.c_str());
        import_data.push_back(d);
    }
}

void summary(const std::vector<int> &data_to_sum, std::vector<int> &bank){

    int tmp = 0;
    bank.push_back(tmp);
    bool found = true;
    while (found) {
        for (auto a:data_to_sum) {
            tmp += a;
            auto result = std::find(bank.begin(), bank.end(), tmp);

            if (result == bank.end()) {
                bank.push_back(tmp);

            } else {
                std::cout << "Found a match " << *result << '\n';
                found = false;
                break;
            }
        }
    }
}

