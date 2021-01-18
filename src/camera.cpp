#include <glm/geometric.hpp>

#include "camera.h"

Camera::Camera(Point origin, Point destination, float aspectRatio, float degrees, size_t samples) : m_origin(origin), m_destination(destination),
m_aspectRatio(aspectRatio), m_samplesPerPixel(samples)
{
    m_aspectRatio =  aspectRatio;
    m_fieldOfViewRadians = degrees_to_radians(degrees);
    m_samplesPerPixel = samples;

    m_heightFieldOfViewMultiplier = tanf(m_fieldOfViewRadians / 2) * 2;
    m_widthFieldOfViewMultiplier = m_heightFieldOfViewMultiplier * m_aspectRatio;

    auto forward = glm::normalize(m_origin - m_destination);
    auto right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), forward));
    auto up = glm::cross(forward, right);

    m_horizontal = m_widthFieldOfViewMultiplier * right;
    m_vertical = m_heightFieldOfViewMultiplier * up;

    m_lowerLeftCorner = m_origin - m_horizontal/2.0f - m_vertical/2.0f - forward;
}

Color Camera::ray_color(const Ray& ray, const Scene& scene) 
{
    auto hit = scene.hit(ray);
    if (hit)
    {
        return 0.5f * glm::vec3(hit->normal.x + 1, hit->normal.y + 1, hit->normal.z + 1);
    }
    return Point(1.0, 1.0, 1.0);
    auto unit_direction = glm::normalize(ray.direction());
    float t = 0.5*(unit_direction.y + 1.0);
    return (1.0f-t)*Point(1.0, 1.0, 1.0) + t*Point(0.5, 0.7, 1.0);
}