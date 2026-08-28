#include "../includes/Scalar.h"

Point Adds(const Point& p, double value){
    std::size_t dimension = p.dimensions();
    
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p.get(i) + value);
    }

    return Point(result);
}

Point Subs(const Point& p, double value){
    std::size_t dimension = p.dimensions();
    
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p.get(i) - value);
    }

    return Point(result);
}

Point Muls(const Point& p, double value){
    std::size_t dimension = p.dimensions();
    
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p.get(i) * value);
    }

    return Point(result);
}

Point Divs(const Point& p, double value){
    if(value == 0){
        throw std::invalid_argument("Division by zero");
    }
    
    std::size_t dimension = p.dimensions();
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p.get(i) / value);
    }

    return Point(result);
}

Point Mods(const Point& p, double value){
    if(value == 0){
        throw std::invalid_argument("Modulo by zero");
    }
    
    std::size_t dimension = p.dimensions();
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(std::fmod(p.get(i),  value));
    }

    return Point(result);
}
