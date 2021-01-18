#include "sphere.h"


Sphere::Sphere(const Point& center, float radius) : m_center(center), m_radius(radius)
{
}

std::optional<HitPoint> Sphere::hit(const Ray& ray) const
{
    glm::vec3 oc = ray.origin() - m_center;
    auto a = dot(ray.direction(), ray.direction());
    auto b = 2.0 * dot(oc, ray.direction());
    auto c = dot(oc, oc) - m_radius*m_radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) 
    {
        return {};
    } 
    else 
    {
        float t = (-b - sqrt(discriminant)) / (2.0*a);
        if(t > 0)
        {
            auto hitPoint = ray.at(t);
            auto normal = glm::normalize(hitPoint - m_center);
            return HitPoint{hitPoint, normal, t};
        }
        t = (-b + sqrt(discriminant)) / (2.0*a);
        if(t > 0)
        {
            auto hitPoint = ray.at(t);
            auto normal = glm::normalize(hitPoint - m_center);
            return HitPoint{hitPoint, normal, t};
        }
    }
    return {};
}