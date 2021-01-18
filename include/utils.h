#pragma once

inline float random_float() {
    return rand() / (RAND_MAX + 1.0);
}

inline float degrees_to_radians(float degrees) {
    return degrees * M_PI / 180.0;
}