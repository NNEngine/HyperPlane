#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Point.h"

Point func_abs(const Point& p);
Point func_sqrt(const Point& p);
Point func_cbrt(const Point& p);
Point func_pow(const Point& p, double exponent);

Point func_exp(const Point& p);
Point func_log(const Point& p);
Point func_log10(const Point& p);

Point func_sin(const Point& p);
Point func_cos(const Point& p);
Point func_tan(const Point& p);

Point func_asin(const Point& p);
Point func_acos(const Point& p);
Point func_atan(const Point& p);

Point func_floor(const Point& p);
Point func_ceil(const Point& p);
Point func_round(const Point& p);

#endif
