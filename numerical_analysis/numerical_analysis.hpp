#pragma once

#include <functional>

template <class Eq>
class NumericalAnalysis {
public:
    NumericalAnalysis(Eq eq, float dt, int n) : _eq(eq), _dt(dt), _n(n) {}

    virtual typename Eq::return_type solve() = 0;

protected:
    Eq _eq;
    const float _dt;
    const int _n;
};
