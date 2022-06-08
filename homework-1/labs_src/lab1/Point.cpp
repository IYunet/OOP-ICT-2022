#include <iostream>
#include <vector>
#include "Point.h"

using std::vector;

Point::Point(double x, double y): _x(x), _y(y) {}

double Point::get_x() const { return _x;}
double Point::get_y() const {return _y;}

Point::Point(const Point &point) {
    this->_x = point._x;
    _y = point._y;
}

