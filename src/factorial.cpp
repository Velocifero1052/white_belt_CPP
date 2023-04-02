//
// Created by comme on 4/2/2023.
//
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