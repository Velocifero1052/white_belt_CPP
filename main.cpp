#include <iostream>

//#include "headers/solutions.h"

using namespace std;

int main() {

    double n, a, b, x, y, final_price;
    cin >> n >> a >> b >> x >> y;
    final_price = n;
    if(n > a && n > b)
        final_price = n - n * (y / 100.0);
    else if(n > a && n <= b)
        final_price = n - n * (x / 100.0);

    cout << final_price;

    return 0;
}

