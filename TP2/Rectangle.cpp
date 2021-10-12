/**
 * Rectangle class
 * @file Rectangle.cpp
 * @author Fyzoriel
 * @date 2021/10/11
 */

#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(): m_length(), m_width(){}

Rectangle::Rectangle(unsigned int length, unsigned int width): m_length(length), m_width(width) {}

unsigned int Rectangle::GetPerimeter() const
{
    return 2 * m_length + 2 * m_width;
}

unsigned int Rectangle::GetSurface() const
{
    return m_length * m_width;
}

bool Rectangle::HasGreaterPerimeter(const Rectangle& rectangle) const
{
    return GetPerimeter() > rectangle.GetPerimeter();
}

bool Rectangle::HasGreaterSurface(const Rectangle& rectangle) const
{
    return GetSurface() > rectangle.GetSurface();
}

void Rectangle::Display() const
{
    std::cout << "Length " << GetLength() << std::endl;
    std::cout << "Width " << GetWidth() << std::endl;
    std::cout << "Perimeter " << GetPerimeter() << std::endl;
    std::cout << "Surface " << GetSurface() << std::endl;
}

void Rectangle::SetLength(unsigned int length)
{
    m_length = length;
}
unsigned int Rectangle::GetLength() const
{
    return m_length;
}

void Rectangle::SetWidth(unsigned int width)
{
    m_width = width;
}
unsigned int Rectangle::GetWidth() const
{
    return m_width;
}

void Rectangle::SetPoint(const Point& point)
{
    upperLeftPoint = point;
}
const Point& Rectangle::GetPoint() const
{
    return upperLeftPoint;
}
