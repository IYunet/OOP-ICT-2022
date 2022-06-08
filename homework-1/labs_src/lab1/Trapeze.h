#pragma once
#include "Polygon.h"

class Trapeze : public Polygon {
public:
    Trapeze(); // конструктор по умолчанию

    Trapeze(int n, Point *coordinates); //  конструктор с параметрами

    [[maybe_unused]] Trapeze(const Trapeze &object); // Конструктор копирования

    Trapeze &operator=(const Trapeze &object); // перегрузка оператора присваивания

    ~Trapeze() override;

};

