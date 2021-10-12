/**
 * The main file
 * @file Main.cpp
 * @author Fyzoriel
 * @date 2021/10/11
 */

#include <iostream>
#include <cmath>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

int main()
{
    Point pointRectangle = Point(0, 0);
    Rectangle rectangle = Rectangle(2,3);
    rectangle.SetPoint(pointRectangle);
    rectangle.Display();

    Rectangle rectangle2 = Rectangle(4,6);
    rectangle.SetPoint(pointRectangle);
    std::cout << "Perimetre plus grand ? " << (rectangle.HasGreaterPerimeter(rectangle2) ? "Vrai" : "Faux") << std::endl;
    std::cout << "Aire plus grande ? " << (rectangle.HasGreaterSurface(rectangle2) ? "Vrai" : "Faux") << std::endl << std::endl;

    Point pointCircle = Point(0, 0);
    Circle circle = Circle(pointCircle, 4);
    circle.Display();

    std::cout << "Sur cercle " << (circle.isOnCircle(Point(0, 2)) ? "Vrai" : "Faux") << std::endl;

    std::cout << "Dans cercle " << (circle.isInCircle(Point(0, 1)) ? "Vrai" : "Faux") << std::endl;
    std::cout << "Dans cercle " << (circle.isInCircle(Point(0, 3)) ? "Vrai" : "Faux") << std::endl << std::endl;


    // Isosceles rectangle triangle
    Point trianglePoint1 = Point(0, 0);
    Point trianglePoint2 = Point(0, 1);
    Point trianglePoint3 = Point(1, 0);
    Triangle triangle = Triangle(trianglePoint1, trianglePoint2, trianglePoint3);
    triangle.Display();
    std::cout << std::endl;

    // Equilateral triangle
    Point equilateralTrianglePoint1 = Point(0, 0);
    Point equilateralTrianglePoint2 = Point(4, 2 * sqrt(3));
    Point equilateralTrianglePoint3 = Point(-1, 3 * sqrt(3));
    Triangle equilateralTriangle = Triangle(equilateralTrianglePoint1, equilateralTrianglePoint2, equilateralTrianglePoint3);
    equilateralTriangle.Display();

    return 0;
}
