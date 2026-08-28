#include "../includes/Vectors.h"
#include "../includes/utility.h"
#include "../includes/Scalar.h"
#include "../includes/Arithmetic.h"

double dot(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    double sum = 0;
    for(std::size_t i=0; i<dimension; i++){
        sum += (p1.get(i) * p2.get(i));
    }
    return sum;
}

double magnitude(const Point& p){
    double sum = 0;
    size_t dimension  = p.dimensions();
    
    for(std::size_t i=0; i<dimension; i++){
        sum += pow(p.get(i), 2);
    }
    return std::sqrt(sum);
}

Point normalization(const Point& p){
    double magnitude_ = magnitude(p);
    
    if(magnitude_ == 0){
        throw std::invalid_argument(
            "Division by Zero"
        );
    }

    std::size_t dimension = p.dimensions();

    std::vector<double> result;
    result.reserve(dimension);

    for(std::size_t i=0; i<dimension; i++){
        result.push_back(p.get(i) / magnitude_);
    }
    
    return Point(result);
}

double angle(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    double dot_ = dot(p1, p2);
    double magnitude1 = magnitude(p1);
    double magnitude2 = magnitude(p2);

    if (magnitude1 == 0 || magnitude2 == 0){
        throw std::invalid_argument(
            "Angle is undefined for the zero vector"
        );
    }

    double cosine = dot_ / (magnitude1 * magnitude2);
    cosine = std::max(-1.0, std::min(1.0, cosine));
    
    return std::acos(cosine);
}

Point projection(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    double p2_magnitude = magnitude(p2);
    if (p2_magnitude == 0){
        throw std::invalid_argument(
            "Cannot project onto the zero vector"
        );
    }

    double p1_p2 = dot(p1, p2);
    double first = p1_p2 / (p2_magnitude * p2_magnitude);

    return Muls(p2, first);
}

Point rejection(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    Point projections_ = projection(p1, p2);

    std::size_t dimension = p1.dimensions();

    return Sub(p1, projections_);
}

Point direction(const Point& p1, const Point& p2){
    Point difference = Sub(p2, p1);

    double magnitude_ = magnitude(difference);
    if (magnitude_ == 0)
    {
        throw std::invalid_argument(
            "Direction is undefined for identical points"
        );
    }
    return Divs(difference, magnitude_);
}
