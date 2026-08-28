#include "../includes/Arithmetic.h"
#include "../includes/utility.h"

Point gt(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();
    
    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) > p2.get(i));
    }

    return Point(result);
}

Point lt(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) < p2.get(i));
    }

    return Point(result);
}

Point et(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) == p2.get(i));
    }

    return Point(result);
}

Point net(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) != p2.get(i));
    }

    return Point(result);
}

Point gte(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) >= p2.get(i));
    }

    return Point(result);
}

Point lte(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p1.get(i) <= p2.get(i));
    }

    return Point(result);
}
