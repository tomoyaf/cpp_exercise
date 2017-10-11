#pragma once

#include <vector>
#include "numerical_analysis.hpp"

template <class Eq>
class RungeKuttaMethod : public NumericalAnalysis<Eq> {
public:
    RungeKuttaMethod(Eq eq, typename Eq::unit_type p0, float dt, int n) : _p0(p0),
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
            
            float ax = NumericalAnalysis<Eq>::_eq.dx_dt(x, y, z);
            float ay = NumericalAnalysis<Eq>::_eq.dy_dt(x, y, z);
            float az = NumericalAnalysis<Eq>::_eq.dz_dt(x, y, z);

            float h = NumericalAnalysis<Eq>::_dt;

            float px = x + 0.5f * h * ax;
            float py = y + 0.5f * h * ay;
            float pz = z + 0.5f * h * az;
            
            float bx = NumericalAnalysis<Eq>::_eq.dx_dt(px, py, pz);
            float by = NumericalAnalysis<Eq>::_eq.dy_dt(px, py, pz);
            float bz = NumericalAnalysis<Eq>::_eq.dz_dt(px, py, pz);

            px = x + 0.5f * h * bx;
            py = y + 0.5f * h * by;
            pz = z + 0.5f * h * bz;
            
            float cx = NumericalAnalysis<Eq>::_eq.dx_dt(px, py, pz);
            float cy = NumericalAnalysis<Eq>::_eq.dy_dt(px, py, pz);
            float cz = NumericalAnalysis<Eq>::_eq.dz_dt(px, py, pz);
            
            px = x + h * cx;
            py = y + h * cy;
            pz = z + h * cz;
            
            float dx = NumericalAnalysis<Eq>::_eq.dx_dt(px, py, pz);
            float dy = NumericalAnalysis<Eq>::_eq.dy_dt(px, py, pz);
            float dz = NumericalAnalysis<Eq>::_eq.dz_dt(px, py, pz);

            p[0][i] = x + (ax + 2.0f * bx + 2.0f * cx + dx) * h / 6.0f;
            p[1][i] = y + (ay + 2.0f * by + 2.0f * cy + dy) * h / 6.0f;
            p[2][i] = z + (az + 2.0f * bz + 2.0f * cz + dz) * h / 6.0f;
        }

        return p;
    }
private:
    typename Eq::unit_type _p0;
};
