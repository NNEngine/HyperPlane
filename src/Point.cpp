#include "../includes/Point.h"
#include "../includes/Arithmetic.h"
#include "../includes/Scalar.h"
#include "../includes/Comparison.h"

Point::Point(std::initializer_list <double> values)
    :coordinates(values)
{}

Point::Point(const std::vector <double>& values)
    :coordinates(values)
{}

void Point::print_point() const{
    std::cout << "(";
    
    std::size_t length = coordinates.size();
    for(std::size_t i = 0; i < length; i++){
        std::cout << coordinates[i];

        if ( i < length - 1){
            std:: cout << ", ";
        }
    }

    std::cout <<")\n";
}

double Point::get(std::size_t index) const{
    if(index < 0 || index >= coordinates.size()){
        throw std::out_of_range("Point coordinate is out of range");
    }
    return coordinates[index];
}

std::size_t Point::dimensions() const{
    return coordinates.size();
}

Point Point::operator+(const Point& other) const{
    return Add(*this, other);
}

Point Point::operator-(const Point& other) const{
    return Sub(*this, other);
}

Point Point::operator*(const Point& other) const{
    return Mul(*this, other);
}

Point Point::operator/(const Point& other) const{
    return Div(*this, other);
}

Point Point::operator%(const Point& other) const{
    return Mod(*this, other);
}

Point Point::operator+(double value) const{
    return Adds(*this, value);
}

Point Point::operator-(double value) const{
    return Subs(*this, value);
}

Point Point::operator*(double value) const{
    return Muls(*this, value);
}

Point Point::operator/(double value) const{
    return Divs(*this, value);
}

Point Point::operator%(double value) const{
    return Mods(*this, value);
}


Point Point::operator>(const Point& other) const{
    return gt(*this, other);
}

Point Point::operator<(const Point& other) const{
    return lt(*this, other);
}

Point Point::operator==(const Point& other) const{
    return et(*this, other);
}

Point Point::operator!=(const Point& other) const{
    return net(*this, other);
}

Point Point::operator>=(const Point& other) const{
    return gte(*this, other);
}

Point Point::operator<=(const Point& other) const{
    return lte(*this, other);
}


double& Point::operator[](std::size_t index){
    if (index >= coordinates.size()){
        throw std::out_of_range("Coordinate index out of range");
    }

    return coordinates[index];
}


const double& Point::operator[](std::size_t index) const{
    if (index >= coordinates.size()){
        throw std::out_of_range("Coordinate index out of range");
    }

    return coordinates[index];
}

std::vector<double>::iterator Point::begin(){
    return coordinates.begin();
}

std::vector<double>::iterator Point::end(){
    return coordinates.end();
}

std::vector<double>::const_iterator Point::begin() const{
    return coordinates.begin();
}

std::vector<double>::const_iterator Point::end() const{
    return coordinates.end();
}

Point& Point::operator+=(const Point& other){
    *this = Add(*this, other);
    return *this;
}

Point& Point::operator-=(const Point& other){
    *this = Sub(*this, other);
    return *this;
}

Point& Point::operator*=(const Point& other){
    *this = Mul(*this, other);
    return *this;
}

Point& Point::operator/=(const Point& other){
    *this = Div(*this, other);
    return *this;
}

Point& Point::operator%=(const Point& other){
    *this = Mod(*this, other);
    return *this;
}


Point& Point::operator+=(double value){
    *this = Adds(*this, value);
    return *this;
}

Point& Point::operator-=(double value){
    *this = Subs(*this, value);
    return *this;
}

Point& Point::operator*=(double value){
    *this = Muls(*this, value);
    return *this;
}

Point& Point::operator/=(double value){
    *this = Divs(*this, value);
    return *this;
}

Point& Point::operator%=(double value){
    *this = Mods(*this, value);
    return *this;
}


Point Point::operator-() const{
    return Muls(*this, -1);
}

Point Point::operator+() const{
    return *this;
}
