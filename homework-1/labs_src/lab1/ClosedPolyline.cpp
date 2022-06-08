#include <iostream>
#include <stdexcept>
#include "ClosedPolyline.h"


ClosedPolyline::ClosedPolyline() {
    Polyline closedLine;
}

ClosedPolyline::ClosedPolyline(int n, Point *coordinates) : Polyline(n, coordinates) {
    if (coordinates[0].get_x() == coordinates[n-1].get_x() && coordinates[0].get_y() == coordinates[n-1].get_y())
    {
        Polyline closedLine(n, coordinates);
    }
    else{
        throw std::invalid_argument( "the first and the last coordinates do not match" );
    }
}

ClosedPolyline &ClosedPolyline::operator=(const ClosedPolyline &object) = default;

[[maybe_unused]] ClosedPolyline::ClosedPolyline(const ClosedPolyline &object) = default;

ClosedPolyline::~ClosedPolyline() = default;





