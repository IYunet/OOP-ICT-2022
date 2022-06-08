#pragma once
#include "ClosedPolyline.h"

class Polygon : protected ClosedPolyline{
public:
    Polygon(); // конструктор по умолчанию

    [[maybe_unused]] Polygon(int n, Point *coordinates); // конструктор с парметрами

    static bool check_convex(Polygon name1); //проверка на выпуклость

    double perimetr();

    [[maybe_unused]] virtual double area();

    [[maybe_unused]] Polygon(const Polygon &p);

    Polygon &operator=(const Polygon &object);

    ~Polygon() override;
};


