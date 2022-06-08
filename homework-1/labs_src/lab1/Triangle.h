#pragma once
#include "Polygon.h"


class Triangle : public  Polygon {
public:
    Triangle(); // по умолчанию

    [[maybe_unused]] Triangle(int n, Point *coordinates); // констурктор с параметрами

    double area() override;

    [[maybe_unused]] Triangle(const Triangle &object); // Конструктор копирования

    Triangle &operator=(const Triangle &object); // перегрузка оператора присваивания

    ~Triangle() override;

};


