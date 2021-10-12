/**
 * Circle header
 * @file Circle.h
 * @author Fyzoriel
 * @date 2021/10/11
 */

#ifndef TP2_CIRCLE_H
#define TP2_CIRCLE_H


#include "Point.h"

class Circle
{
private:
    Point m_center;
    unsigned int m_diameter;

public:

    /**
     * Default circle constructor
     */
    Circle();

    /**
     * Circle constructor
     * @param center The center of the circle
     * @param diameter The diameter of the circle
     */
    Circle(const Point& center, unsigned int diameter);

    /**
     * Get the perimeter of the circle
     * @return the perimeter of the circle
     */
    unsigned int GetPerimeter() const;

    /**
     * Get the surface of the circle
     * @return the surface of the circle
     */
    unsigned int GetSurface() const;

    /**
     * Check if the point passed as parameter is on the circle but not in
     * @param point The point to check
     * @return true if the point is on the circle
     */
    bool isOnCircle(const Point& point);

    /**
     * Check if the point passed as parameter is in the circle but not on
     * @param point The point to check
     * @return true if the point is in the circle
     */
    bool isInCircle(const Point& point);

    /**
     * Provide the information given by the different methods and functions
     */
    void Display() const;

    /**
     * Set the diameter of the circle
     * @param diameter The new diameter
     */
    void SetDiameter(unsigned int diameter);

    /**
     * Get the diameter of the circle
     * @return the diameter of the circle
     */
    unsigned int GetDiameter() const;

    /**
     * Get the radius of the circle
     * @return the radius of the circle
     */
    float GetRadius() const;

    /**
     * Set the center of the circle
     * @param center The new center
     */
    void SetCenter(const Point& center);

    /**
     * Get the center of the circle
     * @return the center of the circle
     */
    const Point& GetCenter() const;
};


#endif //TP2_CIRCLE_H
