#include "../includes/Transformations.h"
#include "../includes/utility.h"
#include "../includes/Arithmetic.h"
#include "../includes/Scalar.h"


Point translate(const Point& p, const Point& translation){
    return Add(p, translation);
}

Point scaleu(const Point& p, double factor){
    return Muls(p, factor);
}

Point scalenu(const Point& p, const Point& factors){
    return Mul(p, factors);
}

Point reflect_origin(const Point& p){
    return Muls(p, -1);
}

Point reflect_dimension(const Point& p, std::size_t dimension){
    std::size_t dimensions = p.dimensions();
    if (dimension >= dimensions){
        throw std::out_of_range("Dimension out of range");
    }

    std::vector<double> result;
    result.reserve(dimensions);

    for (std::size_t i = 0; i < dimensions; i++){
        if (i == dimension){
            result.push_back(-p.get(i));
        }else{
            result.push_back(p.get(i));
        }
    }
    return Point(result);
}


Point rotate(
    const Point& p,
    std::size_t dimension1,
    std::size_t dimension2,
    double angle
){

    std::size_t dimension = p.dimensions();

    if (dimension1 >= dimension || dimension2 >= dimension){
        throw std::out_of_range(
            "Dimension out of range"
        );
    }

    if (dimension1 == dimension2){
        throw std::invalid_argument(
            "Rotation requires two different dimensions"
        );
    }

    std::vector<double> result;
    result.reserve(dimension);

    double c = std::cos(angle);
    double s = std::sin(angle);

    for (std::size_t i = 0; i < dimension; i++){
        result.push_back(p.get(i));
    }

    double x = p.get(dimension1);
    double y = p.get(dimension2);

    result[dimension1] = x * c - y * s;
    result[dimension2] = x * s + y * c;

    return Point(result);
}
