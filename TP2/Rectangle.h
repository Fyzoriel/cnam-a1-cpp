/**
 * Rectangle header
 * @file Rectangle.h
 * @author Fyzoriel
 * @date 2021/10/11
 */

#ifndef TP2_RECTANGLE_H
#define TP2_RECTANGLE_H

#include "Point.h"

class Rectangle
{
private:
    unsigned int m_length, m_width;
    Point upperLeftPoint;

public:

    /**
     * Default rectangle constructor
     */
    Rectangle();

    /**
     * Rectangle constructor
     * @param length the length of the rectangle
     * @param width the width of the rectangle
     */
    Rectangle(unsigned int length, unsigned int width);

    /**
    * Get the perimeter of the rectangle
    * @return the perimeter of the rectangle
    */
    unsigned int GetPerimeter() const;

    /**
     * Get the surface of the rectangle
     * @return the surface of the rectangle
     */
    unsigned int GetSurface() const;

    /**
     * Compare the perimeter of this rectangle and the one passed as parameter
     * @param rectangle Another rectangle to compare
     * @return true if the perimeter of this rectangle is bigger than the one passed as parameter
     */
    bool HasGreaterPerimeter(const Rectangle& rectangle) const;

    /**
     * Compare the surface of this rectangle and the one passed as parameter
     * @param rectangle Another rectangle to compare
     * @return true if the surface of this rectangle is bigger than the one passed as parameter
     */
    bool HasGreaterSurface(const Rectangle& rectangle) const;

    /**
     * Provide the information given by the different methods and functions
     */
    void Display() const;

    /**
     * Set the length of the rectangle
     * @param length The new length
     */
    void SetLength(unsigned int length);

    /**
     * Get the length of the rectangle
     * @return the length of the rectangle
     */
    unsigned int GetLength() const;

    /**
     * Set the width of the rectangle
     * @param width The new width
     */
    void SetWidth(unsigned int width);

    /**
     * Get the width of the rectangle
     * @return the width of the rectangle
     */
    unsigned int GetWidth() const;

    /**
     * Set the upper left point of the rectangle
     * @param point The new upper left point
     */
    void SetPoint(const Point& point);

    /**
     * Get the upper left point of the rectangle
     * @return the upper left point of the rectangle
     */
    const Point& GetPoint() const;
};

#endif //TP2_RECTANGLE_H
