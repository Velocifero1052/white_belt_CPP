//
// Created by Legion on 4/17/2023.
//

#include <string>
#include <algorithm>

class ReversibleString {
private:
    std::string field;
public:
    ReversibleString(){
        this->field = "";
    }
    explicit ReversibleString(std::string s){
        this->field = s;
    }
    std::string ToString() const{
        return field;
    }
    void Reverse() {
        std::reverse(field.begin(), field.end());
    }
};
