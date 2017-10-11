#include <iostream>
#include "matplotlibcpp.h"

#include "./numerical_analysis/euler_method.hpp"
#include "./numerical_analysis/runge_kutta_method.hpp"
#include "rossler_equation.hpp"

//  -std=c++1z -I/usr/include/python2.7 -lpython2.7

namespace plt = matplotlibcpp;

int main() {
    RosslerEquation rossler_equation(/* a= */0.2, /* b= */0.2, /* c= */5.7);
    std::vector<float> p0{0.1, 0.2, 0.3};
    float dt = 0.05;
    int n = 10000;
    EulerMethod<RosslerEquation> euler_method(rossler_equation, p0, dt, n);
    RungeKuttaMethod<RosslerEquation> runge_kutta_method(rossler_equation, p0, dt, n);

    auto p1 = euler_method.solve();
    auto p2 = runge_kutta_method.solve();

    plt::named_plot("Euler method", p1[0], p1[1], "-r");
    plt::named_plot("RK4", p2[0], p2[1], "-b");
    
    plt::legend();

    plt::show();

}
