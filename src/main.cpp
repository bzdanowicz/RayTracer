#include <iostream>

#include "sphere.h"
#include "camera.h"

int main()
{
    Image<glm::vec3> image(600, 600);
    Scene scene;
    scene.add_object(std::make_shared<Sphere>(Point(0.75, 0.75, -1), 0.3));
    scene.add_object(std::make_shared<Sphere>(Point(-0.5, -0.25, -1), 0.3));
    scene.add_object(std::make_shared<Sphere>(Point(0.25, 0.25, -1.5), 0.3));
    scene.add_object(std::make_shared<Sphere>(Point(0,-101,-1), 100));
    
    Camera camera(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1), static_cast<float>(image.width()/image.height()), 60.0f, 5);
    camera.raytrace(image, scene);

    std::cout << image.get_ppm_format();
    return 0;
}