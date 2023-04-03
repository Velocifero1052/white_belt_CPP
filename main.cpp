
//#include "headers/solutions.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> people;

    int number_of_commands;
    cin >> number_of_commands;
    int default_value = 1;
    int worry_value = -1;
    string command;
    for(int i = 0; i < number_of_commands; i++){
        cin >> command;
        if (command == "WORRY") {
            int index;
            cin >> index;
            people[index] = worry_value;
        }
        else if (command == "QUIET") {
            int index;
            cin >> index;
            people[index] = default_value;
        }
        else if (command == "COME") {
            int number;
            cin >> number;
            if(number > 0){
                for(int j = 0; j < number; j++){
                    people.push_back(default_value);
                }
            }else if(number < 0){
                number = -number;
                for(int j = 0; j < number; j++){
                    people.pop_back();
                }
            }
        }
        else if (command == "WORRY_COUNT") {
            cout << count(people.begin(), people.end(), worry_value) << endl;
        }
    }

    return 0;
}

