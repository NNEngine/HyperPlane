#ifndef POINT_H
#define POINT_H

#include "libs.h"

class Point {
private:
    std::vector<double> coordinates;

public:
    Point(std::initializer_list<double> values);
    Point(const std::vector<double>& values);

    void print_point() const;

    double get(std::size_t index) const;
    std::size_t dimensions() const;

    // Point arithmetic
    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator/(const Point& other) const;
    Point operator%(const Point& other) const;

    // Scalar arithmetic
    Point operator+(double value) const;
    Point operator-(double value) const;
    Point operator*(double value) const;
    Point operator/(double value) const;
    Point operator%(double value) const;

    // Comparisons
    Point operator>(const Point& other) const;
    Point operator<(const Point& other) const;
    Point operator==(const Point& other) const;
    Point operator!=(const Point& other) const;
    Point operator>=(const Point& other) const;
    Point operator<=(const Point& other) const;

    // Indexing
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;

    // Iterators
    std::vector<double>::iterator begin();
    std::vector<double>::iterator end();

    std::vector<double>::const_iterator begin() const;
    std::vector<double>::const_iterator end() const;

    // Unary operators
    Point operator-() const;
    Point operator+() const;

    // Compound assignment
    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
    Point& operator*=(const Point& other);
    Point& operator/=(const Point& other);
    Point& operator%=(const Point& other);

    Point& operator+=(double value);
    Point& operator-=(double value);
    Point& operator*=(double value);
    Point& operator/=(double value);
    Point& operator%=(double value);

};

#endif
