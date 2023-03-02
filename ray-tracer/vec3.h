#pragma once

#include <cmath>
#include <iostream>

class vec3 {
private:
	double e[3];
public:
	vec3() { e[0] = 0; e[1] = 0; e[2] = 0; }
	vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	double length() const { return std::sqrt(length_squared()); }
	double length_squared() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

	// Overloaded ops
	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v) {
		e[0] += v.x();
		e[1] += v.y();
		e[2] += v.z();
		return *this;
	}
	vec3& operator*=(const double t) { return *this *= t; }
	vec3& operator/=(const double t) { return *this *= 1/t; }
};

// Type aliases for vec3
using Point3 = vec3;   // 3D point
using Color = vec3;    // RGB color

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.x() + v.x(), u.y() + v.y(), u.y() + v.y());
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.x() * v.x()
		+ u.y() * v.y()
		+ u.z() * v.z();
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.y() * v.z() - u.z() * v.y(),
		u.z() * v.x() - u.x() * v.z(),
		u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}