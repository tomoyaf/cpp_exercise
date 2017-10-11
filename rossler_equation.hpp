#pragma once

#include <array>
#include <vector>

class RosslerEquation {
public:
    using unit_type = std::vector<float>;
    using return_type = std::array<unit_type, 3>;

    RosslerEquation(float a, float b, float c);

    float dx_dt(float x, float y, float z) const;
    float dy_dt(float x, float y, float z) const;
    float dz_dt(float x, float y, float z) const;

    float get_x() const;
    float get_y() const;
    float get_z() const;

    void set_x(float x);
    void set_y(float y);
    void set_z(float z);

private:
    const float _a;
    const float _b;
    const float _c;
};
