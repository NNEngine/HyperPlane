#include "../includes/utility.h"

void  check_dimensions(const Point& p1, const Point& p2){
    if(p1.dimensions() != p2.dimensions()){
        throw std::invalid_argument("Dimensions are not equal");
    }
}
