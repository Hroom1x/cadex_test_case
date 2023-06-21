#pragma once

#include <cmath>
#include <vector>


struct Point {
public:
    Point() : x(0), y(0), z(0) { }
    Point(double x, double y, double z) : x(x), y(y), z(z) { }

    double x;
    double y;
    double z;
};

class ICurve {
public:
    virtual Point getPoint(const double& t) const = 0;
    virtual Point getDerivativePoint(const double& t) const = 0;
};

class Circle : ICurve {
public:
    Circle(double radius) : radius_(radius) { }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
private:
    double radius_;
};

class Ellipse : ICurve {
public:
    Ellipse(double x_semi_radius, double y_semi_radius) :
        x_semi_radius_(x_semi_radius), y_semi_radius_(y_semi_radius) { }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
private:
    double x_semi_radius_;
    double y_semi_radius_;
};

class Helix : ICurve {
public:
    Helix(double radius, double step) : radius_(radius), step_(step) { }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
private:
    double radius_;
    double step_;
};
