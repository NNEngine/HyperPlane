#include "../includes/Coordinates.h"

Point append_coordinate(const Point& p, double value){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension + 1);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(p.get(i));
    }

    result.push_back(value);

    return Point(result);
}


Point prepend_coordinate(const Point& p, double value){
    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension + 1);

    result.push_back(value);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(p.get(i));
    }

    return Point(result);
}


Point insert_coordinate(const Point& p,std::size_t index,double value){
    std::size_t dimension = p.dimensions();

    if (index > dimension){
        throw std::out_of_range(
            "Coordinate index out of range"
        );
    }

    std::vector<double> result;
    result.reserve(dimension + 1);

    for (std::size_t i = 0; i < dimension; i++){
        if (i == index){
            result.push_back(value);
        }

        result.push_back(p.get(i));
    }
    if (index == dimension){
        result.push_back(value);
    }

    return Point(result);
}


Point remove_coordinate(const Point& p,std::size_t index){
    std::size_t dimension = p.dimensions();

    if (index >= dimension){
        throw std::out_of_range(
            "Coordinate index out of range"
        );
    }

    std::vector<double> result;
    result.reserve(dimension - 1);

    for (std::size_t i = 0; i < dimension; i++){
        if (i != index){
            result.push_back(p.get(i));
        }
    }

    return Point(result);
}


Point concatenate(const Point& p1, const Point& p2){
    std::size_t dimension1 = p1.dimensions();
    std::size_t dimension2 = p2.dimensions();

    std::vector<double> result;
    result.reserve(dimension1 + dimension2);

    for (std::size_t i = 0; i < dimension1; i++){
        result.push_back(p1.get(i));
    }

    for (std::size_t i = 0; i < dimension2; i++){
        result.push_back(p2.get(i));
    }

    return Point(result);
}
