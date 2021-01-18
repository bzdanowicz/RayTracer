#include <algorithm>

#include "scene.h"

void Scene::add_object(std::shared_ptr<SceneObject> object)
{
    m_objects.push_back(object);
}

std::optional<HitPoint> Scene::hit(const Ray& ray) const
{
    std::vector<HitPoint> hitPoints;
    for (const auto& object : m_objects)
    {
        auto hit = object->hit(ray);
        if(hit)
        {
            hitPoints.push_back(*hit);
        }
    }
    if(hitPoints.empty())
    {
        return {};
    }
    else
    {
        auto closestElement =  std::min_element(hitPoints.begin(), hitPoints.end(), [](const HitPoint& a, const HitPoint& b) {
            return a.t < b.t;
        });

        return *closestElement;
    }
}