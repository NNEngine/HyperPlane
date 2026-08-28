#ifndef COORDINATE_H
#define COORDINATE_H

#include "Point.h"

Point append_coordinate(const Point& p, double value);
Point prepend_coordinate(const Point& p, double value);
Point insert_coordinate(const Point& p, std::size_t index, double value);
Point remove_coordinate(const Point& p, std::size_t index);
Point concatenate(const Point& p1, const Point& p2);

#endif
