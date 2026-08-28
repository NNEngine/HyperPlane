#ifndef PREDICATES_H
#define PREDICATES_H

#include "Point.h"

bool is_zero(const Point& p);
bool is_unit(const Point& p);
bool is_parallel(const Point& p1, const Point& p2);
bool is_perpendicular(const Point& p1, const Point& p2);

#endif
