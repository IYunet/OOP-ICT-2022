#include <iostream>
#include <vector>
#include "Polyline.h"
#include <cmath>


Polyline::Polyline() {
    nPoint.resize(n);
}

Polyline::Polyline(int n, Point *coordinates) {
    nPoint.resize(n);
    for (int i = 0; i < n; i++)
        nPoint[i] = coordinates[i];
}

[[maybe_unused]] vector<Point> Polyline::add_point_in_polyline(double x, double y) {
    Point a(x, y);
    nPoint.push_back(a);
    return nPoint;
}

double Polyline::get_current_point_x(int num) {
    double x = nPoint[num].get_x();
    return x;
}

double Polyline::get_current_point_y(int num) {
    double y = nPoint[num].get_y();
    return y;
}

double Polyline::polyline_lenght() {
    double p = 0;
    for (int i = 1; i < nPoint.size(); i++)
        p += sqrt(pow(nPoint[i - 1].get_x() - nPoint[i].get_x(), 2)
                + pow(nPoint[i - 1].get_y() - nPoint[i].get_y(), 2));
    return p;
}

int Polyline::get_count_points_polyline() {
    return nPoint.size();;
}

[[maybe_unused]] Polyline::Polyline(const Polyline &object)  : Point(object) {
    nPoint = object.nPoint;
}

Polyline &Polyline::operator=(const Polyline &object) {
    if (&object == this)
        return *this;
    for (int i = 0; i < nPoint.size(); i++)
        nPoint[i] = object.nPoint[i];
    return *this;
}

Polyline::~Polyline() = default;

