#ifndef DISTANCES_H
#define DISTANCES_H

#include "Point.h"

double P2PD(const Point& p1, const Point& p2);
double P2PManhattan(const Point& p1, const Point& p2);
double P2PChebyshev(const Point& p1, const Point& p2);
double P2PMinkowski(const Point& p1, const Point& p2, double p);

double P2OD(const Point& p);

double NormL1(const Point& p);
double NormL2(const Point& p);
double NormLInf(const Point& p);
double NormLp(const Point& p, double p_value);

double P2Hyperplane(const Point& p,
                    const Point& normal,
                    double c);

#endif
