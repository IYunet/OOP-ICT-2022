#include <iostream>
#include "Polygon.h"
#include <stdexcept>

Polygon::Polygon() {
    ClosedPolyline nPolygon;
}

[[maybe_unused]] Polygon::Polygon(int n, Point *coordinates) : ClosedPolyline(n, coordinates) {
    if (coordinates[0].get_x() == coordinates[n-1].get_x() && coordinates[0].get_y() == coordinates[n-1].get_y())
    {
        Polyline closedLine(n, coordinates);
    }
    else{
        throw std::invalid_argument( "the first and the last coordinates do not match" );
    }
}

bool Polygon::check_convex(Polygon name1) {
    if (name1.get_count_points_polyline() < 4) {return false;}
    int counter_positive = 0;
    int counter_negative = 0;
    for (int i = 0; i < name1.get_count_points_polyline() - 2; i++) {
        if ((name1.get_current_point_x(i + 1) - name1.get_current_point_x(i))  *
        (name1.get_current_point_y(i + 2) - name1.get_current_point_y(i + 1)) -
        (name1.get_current_point_x(i + 2) - name1.get_current_point_x(i + 1)) *
        (name1.get_current_point_y(i + 1) - name1.get_current_point_y(i)) > 0 )
        {
            counter_positive += 1;
        }
    }
    for (int i = 0; i < name1.get_count_points_polyline() - 2; i++) {
        if ((name1.get_current_point_x(i + 1) - name1.get_current_point_x(i))  *
            (name1.get_current_point_y(i + 2) - name1.get_current_point_y(i + 1)) -
            (name1.get_current_point_x(i + 2) - name1.get_current_point_x(i + 1)) *
            (name1.get_current_point_y(i + 1) - name1.get_current_point_y(i)) < 0 )
        {
            counter_negative += 1;
        }
    }
    if (counter_positive == name1.get_count_points_polyline() - 2){
        return true;
    }
    if (counter_negative == name1.get_count_points_polyline() - 2){
        return true;
    }
    return false;
    }

[[maybe_unused]] double Polygon::area() {
    double s = 0;
    if (this->check_convex(*this)){
        for (int i = 0; i < this->get_count_points_polyline() - 1; i++){
            s += 0.5*((this->get_current_point_x(i) + this->get_current_point_x(i+1))*
                    ((this->get_current_point_y(i+1) - this->get_current_point_y(i))));}
        s += 0.5*((this->get_current_point_x(0) +
                this->get_current_point_x(this->get_count_points_polyline() - 1))*
                  ((this->get_current_point_y(0) -
                  this->get_current_point_y(this->get_count_points_polyline() - 1))));
        return abs(s);
    }
    else{
        throw std::invalid_argument( "the polygon is not convex" );
    }
}

double Polygon::perimetr() {
    return this->polyline_lenght();
}


Polygon &Polygon::operator=(const Polygon &object) = default;

[[maybe_unused]] Polygon::Polygon(const Polygon &p) = default;

Polygon::~Polygon() = default;