#pragma once

#include "types.h"

class Ray
{
public:
    Ray(const Point& point, const Direction& direction) : m_origin(point), m_direction(direction) {}

    Point at(float t) const
    {
        return m_origin + t * m_direction;
    }

    Direction direction() const
    {
        return m_direction;
    }

    Point origin() const
    {
        return m_origin;
    }

private:
    Point m_origin;
    Direction m_direction;
};