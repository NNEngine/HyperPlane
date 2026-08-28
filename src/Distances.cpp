#include "../includes/Distances.h"
#include "../includes/utility.h"

double P2PD(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    double distance = 0;
    for (std::size_t i = 0; i < dimension; i++){
        double difference = p1.get(i) - p2.get(i);
        distance += std::pow(difference, 2);
    }
    return std::sqrt(distance);
}


double P2PManhattan(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    double distance = 0;
    for (std::size_t i = 0; i < dimension; i++){
        distance += std::abs(p1.get(i) - p2.get(i));
    }
    return distance;
}


double P2PChebyshev(const Point& p1, const Point& p2){
    check_dimensions(p1, p2);

    std::size_t dimension = p1.dimensions();

    double distance = 0;
    for (std::size_t i = 0; i < dimension; i++){
        double difference = std::abs(p1.get(i) - p2.get(i));

        if (difference > distance){
            distance = difference;
        }
    }
    return distance;
}


double P2PMinkowski(const Point& p1, const Point& p2, double p){
    check_dimensions(p1, p2);

    if (p < 1)
    {
        throw std::invalid_argument(
            "Minkowski parameter must be >= 1"
        );
    }

    std::size_t dimension = p1.dimensions();

    double distance = 0;
    for (std::size_t i = 0; i < dimension; i++)
    {
        distance += std::pow(
            std::abs(p1.get(i) - p2.get(i)),
            p
        );
    }
    return std::pow(distance, 1.0 / p);
}


double P2OD(const Point& p){
    return NormL2(p);
}


double NormL1(const Point& p){
    std::size_t dimension = p.dimensions();

    double norm = 0;
    for (std::size_t i = 0; i < dimension; i++)
    {
        norm += std::abs(p.get(i));
    }
    return norm;
}


double NormL2(const Point& p){
    std::size_t dimension = p.dimensions();

    double norm = 0;
    for (std::size_t i = 0; i < dimension; i++)
    {
        norm += std::pow(p.get(i), 2);
    }
    return std::sqrt(norm);
}


double NormLInf(const Point& p){
    std::size_t dimension = p.dimensions();

    double norm = 0;
    for (std::size_t i = 0; i < dimension; i++){
        double value = std::abs(p.get(i));

        if (value > norm){
            norm = value;
        }
    }
    return norm;
}


double NormLp(const Point& p, double p_value){
    if (p_value < 1){
        throw std::invalid_argument(
            "Norm parameter must be >= 1"
        );
    }

    std::size_t dimension = p.dimensions();

    double norm = 0;
    for (std::size_t i = 0; i < dimension; i++){
        norm += std::pow(
            std::abs(p.get(i)),
            p_value
        );
    }
    return std::pow(norm, 1.0 / p_value);
}


double P2Hyperplane(const Point& p, const Point& normal, double c){
    check_dimensions(p, normal);

    double numerator = 0;
    double denominator = 0;

    std::size_t dimension = p.dimensions();

    for (std::size_t i = 0; i < dimension; i++){
        numerator += normal.get(i) * p.get(i);
        denominator += std::pow(normal.get(i), 2);
    }

    numerator += c;

    if (denominator == 0)
    {
        throw std::invalid_argument(
            "Hyperplane normal cannot be zero"
        );
    }

    return std::abs(numerator) / std::sqrt(denominator);
}
