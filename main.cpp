
//#include "headers/solutions.h"

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int size_of_vector;
    cin >> size_of_vector;
    vector<int> temps(size_of_vector);

    for(int i = 0; i < size_of_vector; i++){
        int temp;
        cin >> temp;
        temps[i] = temp;
    }

    int common_value = accumulate(temps.begin(), temps.end(), 0) / temps.size();
    vector<int>higher_that_average;

    for(int i = 0; i < size_of_vector; i++){
        if(temps[i] > common_value)
            higher_that_average.push_back(i);
    }


    cout << higher_that_average.size() << endl;
    bool first = true;
    for(auto elem: higher_that_average){
        if(first){
            cout << elem;
            first = false;
        }else{
            cout << " " << elem;
        }
    }

    return 0;
}

