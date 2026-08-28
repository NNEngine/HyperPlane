#ifndef VECTORS_H
#define VECTORS_H

#include "Point.h"

double dot(const Point& p1, const Point& p2);
double magnitude(const Point& p);
Point normalization(const Point& p);
double angle(const Point& p1, const Point& p2);
Point projection(const Point& p1, const Point& p2);
Point rejection(const Point& p1, const Point& p2);
Point direction(const Point& p1, const Point& p2);

#endif
