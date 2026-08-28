#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "Point.h"

Point translate(const Point& p, const Point& translation);
Point scaleu(const Point& p, double factor);
Point scalenu(const Point& p, const Point& factors);
Point reflect_origin(const Point& p);
Point reflect_dimension(const Point& p, std::size_t dimension);
Point rotate(
    const Point& p,
    std::size_t dimension1,
    std::size_t dimension2,
    double angle
);


#endif
