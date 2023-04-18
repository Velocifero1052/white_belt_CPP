//
// Created by Legion on 4/18/2023.
//
#include <vector>
#include <algorithm>

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
    std::vector<FunctionPart> parts;
};


struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}
