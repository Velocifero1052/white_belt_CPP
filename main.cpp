
//#include "headers/solutions.h"

#include <iostream>

int Factorial(int a){
    if(a < 0){
        return 1;
    }
    int res = 1;
    for(int i = 1; i <= a; i++){
        res *= i;
    }
    return res;
}


int main() {


    return 0;
}

