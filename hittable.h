#ifndef RAY_TRACER_HITTABLE_H
#define RAY_TRACER_HITTABLE_H

#include "rtweekend.h"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        // they're in the same direction
        // this means the ray is hitting from within
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif //RAY_TRACER_HITTABLE_H
