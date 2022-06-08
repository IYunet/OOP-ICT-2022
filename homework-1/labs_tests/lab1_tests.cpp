#include <gtest/gtest.h>
#include "lab1/Point.h"
#include "lab1/ClosedPolyline.h"
#include "lab1/Polygon.h"
#include "lab1/Trapeze.h"
#include "lab1/RegularPolygon.h"
#include "lab1/Triangle.h"

TEST(CreatePolygonalChain, PerimeterCalculatedCorrectly) {
    Point point1(1, 7);
    Point point2(2, 3);
    Point point3(4, 6);
    Point point4(1, 4);
    Point coll[4] = {point1, point2, point3, point4};
    Polyline bc(4, coll);
    double exp_lenght = 11.3342;
    ASSERT_NO_THROW(Polyline bc1(4, coll););
    ASSERT_NEAR(exp_lenght, bc.polyline_lenght(), 0.001 );
}

TEST(CreateClosedPlyChain, PerimeterAndCalculatedCorrectly) {
    Point point1(1, 7);
    Point point2(2, 3);
    Point point3(4, 6);
    Point point4(1, 7);
    Point point5(1,10);
    Point coll[4] = {point1, point2, point3, point4};
    Point coll_closed[4] = {point1, point2, point3, point5};
    ASSERT_ANY_THROW(ClosedPolyline a(4, coll_closed));
    Polyline bc(4, coll);
    double exp_lenght = 10.8909;
    ASSERT_NEAR(exp_lenght, bc.polyline_lenght(), 0.001 );
}

TEST(CreateSharpTriangle, TriangleCheckFailed_ThrowException) {
    Point point1(1, 7);
    Point point2(2, 3);
    Point point3(4, 6);
    Point point4(1, 7);
    Point point5(1, 100);
    Point coll[4] = {point1, point2, point3, point4};
    Point coll_incorrect[4] = {point1, point2, point3, point5};
    ASSERT_NO_THROW(Triangle a(4,coll));
    ASSERT_ANY_THROW(Triangle b(4,coll_incorrect));
}

TEST(CreateTrapezoid, PerimeterAndAreaCalculatedCorrectly){
    Point b1(0,0);
    Point b2(1,3);
    Point b3(3,3);
    Point b4(4,0);
    Point b5(0,0);
    Point tr[5] = {b1, b2, b3, b4,b5};
    Trapeze trap(5, tr);
    ASSERT_NO_THROW(Trapeze trap1(5, tr));
    double exp_perimetr = 12.3246;
    double exp_area = 9;
    ASSERT_NEAR(exp_perimetr, trap.perimetr(), 0.001);
    ASSERT_NEAR(exp_area, trap.area(), 0.001);
}

TEST(CreatePolygon, PerimeterAndAreaCalculatedCorrectly){
    Point b1(0,0);
    Point b2(1,2);
    Point b3(3,3);
    Point b4(4,0);
    Point b5(2,-1);
    Point b6(0,0);
    Point b7(1,4);
    Point five_points[6] = {b1, b2, b3, b4,b5, b6};
    Point five_points_inccorect[6] = {b1, b2, b3, b4,b5, b7};
    Polygon five_polygon(6, five_points);
    ASSERT_NO_THROW(Polygon five_polygon1(6, five_points));
    ASSERT_ANY_THROW(Polygon five_polygon2(6, five_points_inccorect));
    double exp_perimetr = 12.1065;
    double exp_area = 9.5;
    ASSERT_NEAR(exp_perimetr, five_polygon.perimetr(), 0.001);
    ASSERT_NEAR(exp_area, five_polygon.area(), 0.5);
}

TEST(CreatePoint, RetruntCorrectCoordinate){
    Point a1(1,2);
    ASSERT_NEAR(1, a1.get_x(), 0.001);
    ASSERT_NEAR(2, a1.get_y(), 0.001);
}

TEST(CreateRegularPolygon, ValidationPerimeterAndAreaCalculatedCorrectly){
    Point b1(0,0);
    Point b2(0,3);
    Point b3(3,3);
    Point b4(3,0);
    Point b5(0,0);
    Point b6(23,67);
    Point regPolygon[5] = {b1, b2, b3, b4,b5};
    Point regPolygon_incorrecct[5] = {b1, b2, b3, b4,b6};
    RegularPolygon kv(5,regPolygon);
    ASSERT_ANY_THROW(RegularPolygon a(5, regPolygon_incorrecct));
    double exp_perimetr = 12;
    double exp_area = 9;
    ASSERT_NEAR(exp_perimetr, kv.perimetr(), 0.001);
    ASSERT_NEAR(exp_area, kv.area(), 0.001);
}