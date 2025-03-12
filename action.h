#pragma once

struct Action {
    double fx;  // Force in x-direction
    double fy;  // Force in y-direction

    Action(double fx_ = 0.0, double fy_ = 0.0) : fx(fx_), fy(fy_) {}
};