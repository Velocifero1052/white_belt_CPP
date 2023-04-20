#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::istringstream;
using std::ostringstream;
using std::istream;
using std::ostream;
using std::runtime_error;

void EnsureEqual(const string& left, const string& right){
    if(left != right){
        throw std::runtime_error(left + " != " + right);
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }


    return 0;
}

