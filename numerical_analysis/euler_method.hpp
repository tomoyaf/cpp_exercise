#pragma once

#include <vector>
#include "numerical_analysis.hpp"

template <class Eq>
class EulerMethod : public NumericalAnalysis<Eq> {
public:
    EulerMethod(Eq eq, typename Eq::unit_type p0, float dt, int n) : _p0(p0),
            NumericalAnalysis<Eq>(eq, dt, n) {}
    
    typename Eq::return_type solve() override {
        typename Eq::return_type p;

        for (auto&& i : p) {
            i.resize(NumericalAnalysis<Eq>::_n);
        }

        for (int i = 1; i < NumericalAnalysis<Eq>::_n; ++i) {
            float x = p[0][i - 1];
            float y = p[1][i - 1];
            float z = p[2][i - 1];
            
            float dx_dt = NumericalAnalysis<Eq>::_eq.dx_dt(x, y, z);
            float dy_dt = NumericalAnalysis<Eq>::_eq.dy_dt(x, y, z);
            float dz_dt = NumericalAnalysis<Eq>::_eq.dz_dt(x, y, z);

            p[0][i] = dx_dt * NumericalAnalysis<Eq>::_dt + x;
            p[1][i] = dy_dt * NumericalAnalysis<Eq>::_dt + y;
            p[2][i] = dz_dt * NumericalAnalysis<Eq>::_dt + z;
        }

        return p;
    }

private:
    typename Eq::unit_type _p0;
};
