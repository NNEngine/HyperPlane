#include "../includes/Aggregate.h"

double aggr_sum(const Point& p){
    std::size_t length = p.dimensions();

    if(length == 0){
        throw std::invalid_argument(
            "Dimension is zero"
        );
    }

    double sum = 0;
    for(std::size_t i=0; i<length; i++){
        sum += p.get(i);
    }
    return sum;
}

double aggr_product(const Point& p){
    std::size_t length = p.dimensions();

    if(length == 0){
        throw std::invalid_argument(
            "Dimension is zero"
        );
    }

    double product = 1;
    for(std::size_t i=0; i<length; i++){
        product *= p.get(i);
    }
    return product;
}

double aggr_min(const Point& p){
    std::size_t length = p.dimensions();

    if(length == 0){
        throw std::invalid_argument(
            "Dimension is zero"
        );
    }

    double min_val = p.get(0);
    for(std::size_t i=1; i<length; i++){
        min_val = std::min(min_val, p.get(i));
    }
    return min_val;
}

double aggr_max(const Point& p){
    std::size_t length = p.dimensions();

    if(length == 0){
        throw std::invalid_argument(
            "Dimension is zero"
        );
    }

    double max_val = p.get(0);
    for(std::size_t i=1; i<length; i++){
        max_val = std::max(max_val, p.get(i));
    }
    return max_val;
}

double aggr_mean(const Point& p){
    std::size_t length = p.dimensions();

    if(length == 0){
        throw std::invalid_argument(
            "Dimension is zero"
        );
    }

    double sum = 0;
    for(std::size_t i=0; i<length; i++){
        sum += p.get(i);
    }
    return sum / length;
}
