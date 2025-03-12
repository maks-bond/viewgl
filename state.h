#pragma once

struct State {
    double x;   // Agent's x-position
    double y;   // Agent's y-position
    double vx;  // Agent's velocity in x-direction
    double vy;  // Agent's velocity in y-direction

    State(double x_ = 0.0, double y_ = 0.0, double vx_ = 0.0, double vy_ = 0.0)
        : x(x_), y(y_), vx(vx_), vy(vy_) {}
};