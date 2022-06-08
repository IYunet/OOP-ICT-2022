#pragma once

class Point{
protected:
    double _x, _y;

public:
    explicit Point (double x = 0, double y = 0); // конструктор и с параметрами, и по умолчанию

    Point(const Point &point); // Конструктор копирования

    [[nodiscard]] double get_x () const;

    [[nodiscard]] double get_y () const;
};

