#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::string;
using std::reverse;
using std::cout;
using std::endl;
using std::map;
using std::vector;

class FunctionPart{
public:
    FunctionPart(char new_operation, double new_value){
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if(operation == '*'){
            return source_value * value;
        }else if(operation == '/'){
            return source_value / value;
        } else if(operation == '+'){
            return source_value + value;
        }else{
            return source_value - value;
        }
    }
    void Invert(){
        if(operation == '*'){
            operation = '/';
        }else if(operation == '/'){
            operation = '*';
        } else if(operation == '+'){
            operation = '-';
        }else {
            operation = '+';
        }
    }
private:
    char operation;
    double value;
};

class Function{
public:
    void AddPart(char operation, double value){
        parts.push_back({operation, value});
    }
    void Invert(){
        for(FunctionPart& part: parts){
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    }
    double Apply(double value) const{
        for(const FunctionPart& part: parts){
            value = part.Apply(value);
        }
        return value;
    }
private:
    vector<FunctionPart> parts;
};



int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}

