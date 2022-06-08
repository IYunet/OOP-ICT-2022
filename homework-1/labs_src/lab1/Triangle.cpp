#include "Triangle.h"
#include <stdexcept>
#include <cmath>

Triangle::Triangle() {
    Polygon triangle;
}

[[maybe_unused]] Triangle::Triangle(int n, Point *coordinates) : Polygon(n, coordinates) {
    if (n == 4){
        Polygon triangle(n, coordinates);
    }
    else{
        throw std::invalid_argument( "it is not triangle");
    }
}

double Triangle::area() {
    double s = 1;
    double poly = this->perimetr()/2;
    for (int i =1; i < 4; i++){
        s *= (poly - sqrt(pow(this->get_current_point_x(i - 1) - this->get_current_point_x(i),2) +
                          pow(this->get_current_point_y(i - 1) - this->get_current_point_y(i),2)));
    }
    s = sqrt(s*poly);
    return s;
}

Triangle &Triangle::operator=(const Triangle &object) = default;

[[maybe_unused]] Triangle::Triangle(const Triangle &object) = default;


Triangle::~Triangle() = default;
