/**
 * Triangle header
 * @file Triangle.h
 * @author Fyzoriel
 * @date 2021/10/11
 */

#ifndef TP2_TRIANGLE_H
#include "Point.h"

class Triangle
{
private:
    Point A, B, C;

public:

    /**
     * The default triangle constructor
     */
    Triangle();

    /**
     * Triangle constructor
     * @param A The point of the first triangle vertex
     * @param B The point of the second triangle vertex
     * @param C The point of the last triangle vertex
     */
    Triangle(const Point& A, const Point& B, const Point& C);

    /**
     * Get the lengths of each sides
     * @return a vector with the lengths of each sides
     */
    std::vector<float> GetLengths() const;

    /**
     * Get the base (the longest side) of the triangle
     * @return the base of the triangle
     */
    float GetBase() const;

    /**
     * Get the perimeter of the triangle
     * @return the perimeter of the triangle
     */
    float GetPerimeter() const;

    /**
     * Get the height of the triangle
     * @return the height of the triangle
     */
    float GetHeight() const;

    /**
     * Get the surface of the triangle
     * @return the surface of the triangle
     */
    float GetSurface() const;

    /**
     * Check if the triangle is equilateral
     * @return true if the triangle is equilateral
     */
    bool IsEquilateral() const;

    /**
     * Check if the triangle is isosceles
     * @return true if the triangle is isosceles
     */
    bool IsIsosceles() const;
    /**
     * Check if the triangle is rectangle
     * @return true if the triangle is rectangle
     */
    bool IsRectangle() const;

    /**
     * Provide the information given by the different methods and functions
     */
    void Display() const;

    /**
     * Get the point of the first triangle vertex
     * @return the point of the first triangle vertex
     */
    const Point& GetPointA() const;

    /**
     * Set the point of the first triangle vertex
     * @param point the new point
     */
    void SetPointA(const Point& point);

    /**
     * Get the point of the second triangle vertex
     * @return the point of the second triangle vertex
     */
    const Point& GetPointB() const;

    /**
     * Set the point of the second triangle vertex
     * @param point the new point
     */
    void SetPointB(const Point& point);

    /**
     * Get the point of the last triangle vertex
     * @return the point of the last triangle vertex
     */
    const Point& GetPointC() const;

    /**
     * Set the point of the last triangle vertex
     * @param point the new point
     */
    void SetPointC(const Point& point);
};

#endif //TP2_TRIANGLE_H
