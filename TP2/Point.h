/**
 * Point structure
 * @file Point.h
 * @author Fyzoriel
 * @date 2021/10/11
 */

#ifndef TP2_POINT_H
#define TP2_POINT_H

struct Point
{
    float x, y;

    /**
     * Default point constructor
     */
    Point();

    /**
     * Point constructor
     * @param x, y the coordinates of the point
     */
    Point(float x, float y);

    /**
     * Static method to get the distance between two points
     * @param point1 The first point
     * @param point2 The second point
     * @return the distance between the two points passed as parameters
     */
    static float Distance(const Point& point1, const Point& point2);
};

#endif //TP2_POINT_H
