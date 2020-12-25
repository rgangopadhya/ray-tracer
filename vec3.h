#ifndef RAY_TRACER_VEC3_H
#define RAY_TRACER_VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {};

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return {-e[0], -e[1], -e[2]}; }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3 &v) {
            e[0] += v.x();
            e[1] += v.y();
            e[2] += v.z();
            return *this;
        }

        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
           return x() * x() + y() * y() + z() * z();
        }
public:
        double e[3];
};

// type aliases for vec3
using point3 = vec3; // 3D point
using color = vec3; // RGB color

// vec3 utility functions
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return {u.x() + v.x(), u.y() + v.y(), u.z() + v.z()};
}
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return {u.x() - v.x(), u.y() - v.y(), u.z() - v.z()};
}
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return {u.x() * v.x(), u.y() * v.y(), u.z() * v.z()};
}

inline vec3 operator*(const vec3 &v, double t) {
    return {v.x() * t, v.y() * t, v.z() * t};
}

inline vec3 operator*(double t, const vec3 &v) {
    return v * t;
}

inline vec3 operator/(const vec3 &v, double t) {
    return v * (1/t);
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return {
        u.y() * v.z() - u.z() * v.y(),
        u.x() * v.z() - u.z() * v.x(),
        u.x() * v.y() - u.y() * v.x()
    };
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}
#endif //RAY_TRACER_VEC3_H