#include "../includes/Arithmetic.h"
#include "../includes/utility.h"

Point Add(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();
    
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) + p2.get(i));
    }

    return Point(result);
}

Point Sub(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) - p2.get(i));
    }

    return Point(result);
}

Point Mul(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) * p2.get(i));
    }

    return Point(result);
}

Point Div(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        if(p2.get(i) == 0){
            throw std::invalid_argument("Division by zero");
        }
        result.push_back(p1.get(i) / p2.get(i));
    }

    return Point(result);
}

Point Mod(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        if(p2.get(i) == 0){
            throw std::invalid_argument("Modulo by zero");
        }
        result.push_back(std::fmod(p1.get(i), p2.get(i)));
    }

    return Point(result);
}
