#pragma once
#include "Polyline.h"

class ClosedPolyline : public Polyline {
public:
    ClosedPolyline(); // конструктор по умолчанию

    ClosedPolyline(int n, Point *coordinates); // конструктор с параметрами

    [[maybe_unused]] ClosedPolyline(const ClosedPolyline &object); // Конструктор копирования

    ClosedPolyline &operator=(const ClosedPolyline &object); // перегрузка оператора присваивания

   ~ ClosedPolyline() override; // деструктор
};
