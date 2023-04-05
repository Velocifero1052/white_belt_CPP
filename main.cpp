
//#include "headers/solutions.h"

#include <iostream>
#include <vector>

using namespace std;

void print_tasks(const vector<string>& tasks){
    cout << tasks.size();
    for(const auto & task : tasks){
        cout << " " << task;
    }
    cout << endl;
}

int main() {
    int number_of_month = 12;
    int current_position = 0;
    vector<vector<string>> tasks(31);
    vector<int> days_count(number_of_month);
    days_count[0] = 30;
    days_count[1] = 27;
    days_count[2] = 30;
    days_count[3] = 29;
    days_count[4] = 30;
    days_count[5] = 29;
    days_count[6] = 30;
    days_count[7] = 30;
    days_count[8] = 29;
    days_count[9] = 30;
    days_count[10] = 29;
    days_count[11] = 30;

    int command_count;
    cin >> command_count;

    for(int command_number = 0; command_number < command_count; command_number++){
        string command;

        cin >> command;
        if(command == "ADD"){
            int day;
            string task;
            cin >> day >> task;
            tasks[day - 1].push_back(task);
        }else if(command == "DUMP"){
            int day;
            cin >> day;
            print_tasks(tasks[day - 1]);
        }else if(command == "NEXT"){
            int prev_position = current_position;
            if(current_position == number_of_month - 1)
                current_position = 0;
            else
                current_position++;
            int prev_last_day = days_count[prev_position];
            int current_last_day = days_count[current_position];
            if(current_last_day < prev_last_day){
                for(int i = current_last_day + 1; i <= prev_last_day; i++){
                    tasks[current_last_day].insert(tasks[current_last_day].end(),
                                                tasks[i].begin(),
                                                tasks[i].end());
                    tasks[i].clear();
                }
            }
        }
    }

    return 0;
}

