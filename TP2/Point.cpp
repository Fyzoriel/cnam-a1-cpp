//
// Created by Fyzoriel on 11/10/2021.
//

#include <cmath>
#include "Point.h"

Point::Point(): x(), y() {}

Point::Point(float x, float y): x(x), y(y) {}

float Point::Distance(const Point &point1, const Point &point2)
{
    return sqrtf((powf((point1.x - point2.x), 2) + powf(point1.y - point2.y, 2)));
}
