
//#include "headers/solutions.h"

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<string, vector<string>> stops_to_buses;
    int command_count;
    cin >> command_count;

    for (int i = 0; i < command_count; i++){
        string command;
        cin >> command;
        if(command == "NEW_BUS"){
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            for(int j = 0; j < stop_count; j++){
                string stop;
                cin >> stop;
                if(stops_to_buses.count(stop) == 0){
                    stops_to_buses[stop] = {};
                }
                stops_to_buses[stop].push_back(bus);
            }
        }
    }


    return 0;
}

