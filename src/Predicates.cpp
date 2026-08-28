#include "../includes/Predicates.h"
#include "../includes/utility.h"
#include "../includes/Vectors.h"

bool is_zero(const Point& p){
    return magnitude(p) == 0;
}

bool is_unit(const Point& p){
    return magnitude(p) == 1;
}

bool is_parallel(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    double magnitude1 = magnitude(p1);
    double magnitude2 = magnitude(p2);

    if (magnitude1 == 0 || magnitude2 == 0){
        throw std::invalid_argument(
            "Zero vector cannot be parallel"
        );
    }

    return std::abs(dot(p1, p2)) == magnitude1 * magnitude2;
}

bool is_perpendicular(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    return dot(p1, p2) == 0;
}
