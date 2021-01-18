#pragma once
#include <vector>
#include <memory>

#include "scene_object.h"

class Scene
{
public:
    void add_object(std::shared_ptr<SceneObject> object);
    std::optional<HitPoint> hit(const Ray& ray) const;

private:
    std::vector<std::shared_ptr<SceneObject>> m_objects;
};