#pragma once
#include <optional>

#include "hit_point.h"
#include "ray.h"


class SceneObject
{
public:
    virtual std::optional<HitPoint> hit(const Ray& ray) const = 0;
};