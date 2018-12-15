#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

/* 1.create function that reads file
 * 2. read input and add to it to the local variable
 * 3. remember to add const
*/

void read_file_int(std::vector<int> &import_data);
void read_file_str(std::vector<std::string> &import_data_str);
void finding_summary(const std::vector<int> &data_to_sum, std::vector<int> &bank);
void finding_letters(const std::vector<std::string> &import_dataSTR);


int main() {

    //std::vector<int>data_file{}; // to keep all frequences from file
    //std::vector<int>bank{};      // to keep summary of each iteration
    //read_file(data_file);
    //finding_summary(data_file, bank);

    // reading string from the file
    std::vector<std::string> letters{};
    read_file_str(letters);
    finding_letters(letters);



    return 0;
}

//getting letters from file STRING
void read_file_str(std::vector<std::string> &import_data_str){
    std::ifstream file("day2.txt");
    std::string data;
    while (std::getline(file, data)){
        import_data_str.push_back(data);
    }

}

void finding_letters(const std::vector<std::string> &import_dataSTR){

    int count2 = 0;
    int count3 = 0;
    bool three = true;
    bool two = true;


    for (auto a: import_dataSTR){

        std::sort(a.begin(), a.end());

        for (auto item: a){

            auto result = std::count(a.begin(), a.end(), item);

            if (result > 1 && result < 4)
            {
                if (result == 3){
                    if (three){
                        count3++;
                        three = false;
                    }
                } else if (result == 2){
                    if (two){
                        count2++;
                        two = false;
                    }
                }
            }
        }
        two = true;
        three = true;
    }

    std::cout << "Pairs of 2: " << count2 << " & Pairs of 3: " << count3 << '\n';
    std::cout << "Score " << count2 * count3;
}


// getting numbers from file INT
void read_file_int(std::vector<int> &import_data){

    std::ifstream file("data.txt");
    std::string data;
    while (std::getline(file, data)){
        int d = std::atoi(data.c_str());
        import_data.push_back(d);
    }
}

void finding_summary(const std::vector<int> &data_to_sum, std::vector<int> &bank){

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

