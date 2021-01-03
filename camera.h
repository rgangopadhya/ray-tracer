#ifndef RAY_TRACER_CAMERA_H
#define RAY_TRACER_CAMERA_H

#include "rtweekend.h"

class camera {
    public:
        camera() {
            auto aspect_ratio = 16.0 / 9.0;
            auto viewport_height = 2.0;
            auto viewport_width = viewport_height * aspect_ratio;
            auto focal_length = 1.0;

            origin = point3(0, 0, 0);
            horizontal = vec3(viewport_width, 0, 0);
            vertical = vec3(0, viewport_height, 0);
            lower_left_corner = origin - vec3(0, 0, focal_length) - horizontal / 2 - vertical / 2;
        }

        ray get_ray(double u, double v) const {
            return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
        }
    private:
        point3 origin;
        point3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
};

#endif //RAY_TRACER_CAMERA_H
