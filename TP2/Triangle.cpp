/**
 * Triangle class
 * @file Triangle.cpp
 * @author Fyzoriel
 * @date 2021/10/11
 */

#include <cmath>
#include <vector>
#include <iostream>
#include "Triangle.h"

Triangle::Triangle(): A(), B(), C() {}

Triangle::Triangle(const Point &A, const Point &B, const Point &C): A(A), B(B), C(C) {}

std::vector<float> Triangle::GetLengths() const
{
    float AB = Point::Distance(A, B);
    float BC = Point::Distance(B, C);
    float AC = Point::Distance(A, C);

    return {AB, BC, AC};
}

float Triangle::GetBase() const
{
    std::vector<float> lengths = GetLengths();
    float AB = lengths[0];
    float BC = lengths[1];
    float AC = lengths[2];

    if (AB > AC && AB > BC)
    {
        return AB;
    }
    else if (AC > BC)
    {
        return AC;
    }
    return BC;
}

float Triangle::GetPerimeter() const
{
    std::vector<float> lengths = GetLengths();
    float AB = lengths[0];
    float BC = lengths[1];
    float AC = lengths[2];
    return AB + BC + AC;
}

float Triangle::GetSurface() const
{
    // Get the surface with Heron's formula
    std::vector<float> lengths = GetLengths();

    float p = GetPerimeter() / 2.0f;

    return sqrtf(p * (p - lengths[0]) * (p - lengths[1]) * (p - lengths[2]));
}

float Triangle::GetHeight() const
{
    return 2 * GetSurface() / GetBase();
}

bool Triangle::IsIsosceles() const
{
    if (IsEquilateral())
    {
        return false;
    }
    std::vector<float> lengths = GetLengths();

    return  lengths[0] == lengths[1] || lengths[1] == lengths[2] || lengths[0] == lengths[2];
}

bool Triangle::IsRectangle() const
{
    if (IsEquilateral())
    {
        return false;
    }

    std::vector<float> lengths = GetLengths();
    float hypotenuse = GetBase();

    // Remove Base (Potential hypotenuse) to obtain the 2 other segments
    lengths.erase(std::remove(lengths.begin(), lengths.end(), hypotenuse), lengths.end());

    // Round at 3 decimals places because cpp float round error
    double a = round(pow(lengths[0], 2) * 100.0) / 100.0;
    double b = round(pow(lengths[1], 2) * 100.0) / 100.0;
    double c = round(pow(hypotenuse, 2) * 100.0) / 100.0;

    return a + b == c;
}

bool Triangle::IsEquilateral() const
{
    std::vector lengths = GetLengths();
    float AB = lengths[0];
    float BC = lengths[1];
    float AC = lengths[2];
    return AB == BC && BC == AC;
}

void Triangle::Display() const
{
    std::cout << "Base " << GetBase() << std::endl;
    std::cout << "Perimeter " << GetPerimeter() << std::endl;
    std::cout << "Height " << GetHeight() << std::endl;
    std::cout << "Surface " << GetSurface() << std::endl;
    std::cout << "IsEquilateral  " << IsEquilateral() << std::endl;
    std::cout << "IsIsosceles  " << IsIsosceles() << std::endl;
    std::cout << "IsRectangle  " << IsRectangle() << std::endl;
}

const Point& Triangle::GetPointA() const
{
    return A;
}
void Triangle::SetPointA(const Point &point)
{
    A = point;
}

const Point& Triangle::GetPointB() const
{
    return B;
}
void Triangle::SetPointB(const Point &point)
{
    B = point;
}

const Point&  Triangle::GetPointC() const
{
    return C;
}
void Triangle::SetPointC(const Point &point)
{
    C = point;
}
