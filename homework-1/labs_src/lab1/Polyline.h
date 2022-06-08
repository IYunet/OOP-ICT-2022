#pragma once
#include <vector>
#include "Point.h"
using std::vector;


class Polyline : public Point{
protected:
    int n = 1;
    vector<Point> nPoint;

public:
    Polyline(); // конструктор по умолчанию

    Polyline(int n, Point *coordinates); // конструктор с параметрами

    double get_current_point_x(int num);

    double get_current_point_y(int num);

    [[maybe_unused]] vector<Point> add_point_in_polyline(double x, double y);

    virtual double polyline_lenght();

    int get_count_points_polyline();

    [[maybe_unused]] Polyline(const Polyline &object); // Конструктор копирования

    Polyline &operator=(const Polyline &object); // перегрузка оператора присваивания

    virtual ~Polyline();
};