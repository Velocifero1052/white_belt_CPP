
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::sort;
using std::vector;
using std::string;
using std::tolower;
using std::transform;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](string x, string y) {
        transform(x.begin(), x.end(), x.begin(),
                                         [](unsigned char c){ return std::tolower(c); });
        transform(y.begin(), y.end(), y.begin(),
                                         [](unsigned char c){ return std::tolower(c); });
        return x < y;
    });

    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (first) {
            cout << v[i];
            first = false;
        }else {
            cout << " " << v[i];
        }
    }

    return 0;
}

