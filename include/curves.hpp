#pragma once

#include <cmath>


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
    ~ICurve() = default;
    virtual Point getPoint(const double& t) const = 0;
    virtual Point getDerivativePoint(const double& t) const = 0;
};

class Circle : public ICurve {
public:
    Circle() : radius_(0) { }
    explicit Circle(double radius) : radius_(std::abs(radius)) { }
    Circle(const Circle &other) : radius_(other.radius_) { }

    Circle& operator=(const Circle& other) {
        if (&other != this) {
            radius_ = other.radius_;
        }
        return *this;
    }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
    double getRadius() const;
private:
    double radius_;
};

class Ellipse : public ICurve {
public:
    Ellipse() : x_semi_radius_(0), y_semi_radius_(0) { }
    Ellipse(double x_semi_radius, double y_semi_radius) :
        x_semi_radius_(std::abs(x_semi_radius)), y_semi_radius_(std::abs(y_semi_radius)) { }
    Ellipse(const Ellipse &other) : x_semi_radius_(other.x_semi_radius_), y_semi_radius_(other.y_semi_radius_) { }

    Ellipse& operator=(const Ellipse& other) {
        if (&other != this) {
            x_semi_radius_ = other.x_semi_radius_;
            y_semi_radius_ = other.y_semi_radius_;
        }
        return *this;
    }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
private:
    double x_semi_radius_;
    double y_semi_radius_;
};

class Helix : public ICurve {
public:
    Helix() : radius_(0), step_(0) { }
    Helix(double radius, double step) : radius_(std::abs(radius)), step_(step) { }
    Helix(const Helix &other) : radius_(other.radius_), step_(other.step_) { }

    Helix& operator=(const Helix& other) {
        if (&other != this) {
            radius_ = other.radius_;
            step_ = other.step_;
        }
        return *this;
    }

    Point getPoint(const double& t) const override;
    Point getDerivativePoint(const double& t) const override;
private:
    double radius_;
    double step_;
};
