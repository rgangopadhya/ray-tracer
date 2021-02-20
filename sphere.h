#ifndef RAY_TRACER_SPHERE_H
#define RAY_TRACER_SPHERE_H

#include "rtweekend.h"
#include "hittable.h"

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r, shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {}
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    public:
        point3 center;
        double radius;
        shared_ptr<material> mat_ptr;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    /*
     * Determines if, given a range of parameters (t_min, t_max),
     * there is a solution for the ray r. If there is, mutate the hit_record rec
     * with the solution for t and the point that was hit.
     * also, calculate the normal from the point on the sphere that was hit,
     * making sure to orient it so that it opposes the ray direction (?)
     * With the material, we need to pass that in so we know how to handle the
     * reflection of the hit
     */
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || root > t_max) return false;
    }

    rec.t = root;
    rec.p = r.at(root);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}

#endif //RAY_TRACER_SPHERE_H
