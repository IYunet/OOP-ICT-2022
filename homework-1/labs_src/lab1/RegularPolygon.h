#pragma once
#include "Polygon.h"

class RegularPolygon : public Polygon{
public:
    RegularPolygon(); //конструктор по умолчанию

    RegularPolygon(int n, Point *coordinates);

    [[maybe_unused]] RegularPolygon(const RegularPolygon &object); // Конструктор копирования

    RegularPolygon &operator=(const RegularPolygon &object); // перегрузка оператора присваивания

    ~RegularPolygon() override;
};



