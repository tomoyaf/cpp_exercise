#include "rossler_equation.hpp"

RosslerEquation::RosslerEquation(float a, float b, float c) : _a(a), _b(b), _c(c) {}

float RosslerEquation::dx_dt(float x, float y, float z) const {
    return -y - z;
}

float RosslerEquation::dy_dt(float x, float y, float z) const {
    return x + _a * y;
}

float RosslerEquation::dz_dt(float x, float y, float z) const {
    return _b + z * (x - _c);
}
