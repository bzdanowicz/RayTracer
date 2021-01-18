#pragma once
#include "scene.h"
#include "image.h"
#include "utils.h"

using Color = glm::vec3;

class Camera
{
public:
    Camera(Point origin, Point destination, float aspectRatio, float degrees, size_t samples);

    Color ray_color(const Ray& ray, const Scene& scene);

    template <typename T>
    void raytrace(Image<T>& image, const Scene& scene);

private:
    Point m_origin;
    Point m_destination;

    float m_aspectRatio;
    float m_fieldOfViewRadians;
    float m_focalLength = 1.0f;
    float m_widthFieldOfViewMultiplier;
    float m_heightFieldOfViewMultiplier;

    Point m_horizontal;
    Point m_vertical;
    Point m_lowerLeftCorner;

    size_t m_samplesPerPixel;
};

template <typename T>
void Camera::raytrace(Image<T>& image, const Scene& scene)
{
    for (int j = 0; j < image.height(); ++j) {
        for (int i = 0; i < image.width(); ++i) {

            Color pixelColor = {0, 0, 0};
            for(size_t s = 0; s < m_samplesPerPixel; ++s)
            {
                auto u = (i + random_float()) / (image.width()-1);
                auto v = (j + random_float()) / (image.height()-1);

                Ray ray(m_origin, m_lowerLeftCorner + u*m_horizontal + v*m_vertical - m_origin);
                pixelColor += ray_color(ray, scene);
            }

            image.at(i, j) = pixelColor / static_cast<float>(m_samplesPerPixel) * 255.0f;
        }
    }
}