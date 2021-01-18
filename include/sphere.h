#pragma once
#include "scene_object.h"

class Sphere : public SceneObject
{
public:
    Sphere(const Point& center, float radius);
    std::optional<HitPoint> hit(const Ray& ray) const override;

private:
    float m_radius;
    Point m_center;
};