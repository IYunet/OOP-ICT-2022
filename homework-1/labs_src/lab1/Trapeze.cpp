#include <iostream>
#include "Trapeze.h"
#include <stdexcept>
#include <cmath>

Trapeze::Trapeze() {
    Polygon trap;
}

Trapeze::Trapeze(int n, Point *coordinates) : Polygon(n, coordinates) {
    if (n != 5) {throw std::invalid_argument( "it is not trapeze");}
    Polyline coor;
    for (int i = 0; i < n - 1; i++){
        coor.add_point_in_polyline(coordinates[i + 1].get_x() - coordinates[i].get_x(),
                                   coordinates[i + 1].get_y() - coordinates[i].get_y() );
    }
    if (coor.get_current_point_x(0) * coor.get_current_point_y(2) ==
        coor.get_current_point_y(0) * coor.get_current_point_x(2)  )
    {
        Polygon trapez;
    }
    else if (coor.get_current_point_x(1) * coor.get_current_point_y(3) ==
             coor.get_current_point_y(3) * coor.get_current_point_x(1)  )
    {
        Polygon trapez;
    }
    else{
        throw std::invalid_argument( "it is not trapeze");
    }
}

Trapeze &Trapeze::operator=(const Trapeze &object) = default;

[[maybe_unused]] Trapeze::Trapeze(const Trapeze &object) = default;

Trapeze::~Trapeze() = default;



