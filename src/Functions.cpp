#include "../includes/Functions.h"

Point func_abs(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::fabs(p.get(i)));
    }

    return Point(result);
}


Point func_sqrt(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::sqrt(p.get(i)));
    }

    return Point(result);
}


Point func_cbrt(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::cbrt(p.get(i)));
    }

    return Point(result);
}


Point func_pow(const Point& p, double exponent){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::pow(p.get(i), exponent));
    }

    return Point(result);
}


Point func_exp(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::exp(p.get(i)));
    }

    return Point(result);
}


Point func_log(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::log(p.get(i)));
    }

    return Point(result);
}


Point func_log10(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::log10(p.get(i)));
    }

    return Point(result);
}


Point func_sin(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::sin(p.get(i)));
    }

    return Point(result);
}


Point func_cos(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::cos(p.get(i)));
    }

    return Point(result);
}


Point func_tan(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::tan(p.get(i)));
    }

    return Point(result);
}


Point func_asin(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::asin(p.get(i)));
    }

    return Point(result);
}


Point func_acos(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::acos(p.get(i)));
    }

    return Point(result);
}


Point func_atan(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::atan(p.get(i)));
    }

    return Point(result);
}


Point func_floor(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::floor(p.get(i)));
    }

    return Point(result);
}


Point func_ceil(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::ceil(p.get(i)));
    }

    return Point(result);
}


Point func_round(const Point& p){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(std::round(p.get(i)));
    }

    return Point(result);
}
