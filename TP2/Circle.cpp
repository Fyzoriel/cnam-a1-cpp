/**
 * Circle class
 * @file Circle.cpp
 * @author Fyzoriel
 * @date 2021/10/11
 */

#include <iostream>
#include <cmath>
#include "Circle.h"

Circle::Circle(): m_center(), m_diameter() {}

Circle::Circle(const Point& center, unsigned int diameter): m_center(center), m_diameter(diameter) {}

unsigned int Circle::GetPerimeter() const
{
    return M_PI * m_diameter;
}

unsigned int Circle::GetSurface() const
{
    return M_PI * pow(GetRadius(), 2);
}

bool Circle::isOnCircle(const Point &point)
{
    return Point::Distance(m_center, point) == GetRadius();
}

bool Circle::isInCircle(const Point &point)
{
    return Point::Distance(m_center, point) < GetRadius();
}

void Circle::Display() const
{
    std::cout << "Diameter " << GetDiameter() << std::endl;
    std::cout << "Radius" << GetRadius() << std::endl;
    std::cout << "Perimeter " << GetPerimeter() << std::endl;
    std::cout << "Surface " << GetSurface() << std::endl;
}

void Circle::SetDiameter(unsigned int diameter)
{
    m_diameter = diameter;
}
unsigned int Circle::GetDiameter() const
{
    return m_diameter;
}

float Circle::GetRadius() const
{
    return m_diameter / 2.0f;
}

void Circle::SetCenter(const Point& center)
{
    m_center = center;
}
const Point& Circle::GetCenter() const
{
    return m_center;
}
