#include "RegularPolygon.h"
#include <stdexcept>
#include <cmath>

RegularPolygon :: RegularPolygon()= default;

RegularPolygon::RegularPolygon(int n, Point *coordinates) : Polygon(n, coordinates) {

    Polyline coor;
    for (int i = 0; i < n - 1; i++){
        coor.add_point_in_polyline(coordinates[i + 1].get_x() - coordinates[i].get_x(),
                                   coordinates[i + 1].get_y() - coordinates[i].get_y() );
    }
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        if (pow(coor.get_current_point_x(i),2) +
        pow(coor.get_current_point_y(i),2)  ==
            pow(coor.get_current_point_x(i + 1),2) +
            pow(coor.get_current_point_y(i+1),2)) {
            counter += 1;
        }
    }
    if (counter == n - 2){
        RegularPolygon RegularPolygon;
    }
    else{
        throw std::invalid_argument( "it is not regularpolygon");
    }
}

RegularPolygon &RegularPolygon::operator=(const RegularPolygon &object) = default;

[[maybe_unused]] RegularPolygon::RegularPolygon(const RegularPolygon &object) = default;


RegularPolygon::~RegularPolygon() = default;


