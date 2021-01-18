#pragma once
#include <glm/vec3.hpp> 
#include <glm/geometric.hpp>

using Point = glm::vec3;
using Direction = glm::vec3;

struct HitPoint
{
    Point point;
    Direction normal;
    float t;
};