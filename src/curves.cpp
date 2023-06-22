#include "curves.hpp"


Point Circle::getPoint(const double &t) const
{
    return {radius_ * cos(t), radius_ * sin(t), 0};
}

Point Circle::getDerivativePoint(const double &t) const
{
    return {-radius_ * sin(t), radius_ * cos(t), 0};
}

Point Ellipse::getPoint(const double &t) const
{
    return {x_semi_radius_ * cos(t), y_semi_radius_ * sin(t), 0};
}

Point Ellipse::getDerivativePoint(const double &t) const
{
    return {-x_semi_radius_ * sin(t), y_semi_radius_ * cos(t), 0};
}

Point Helix::getPoint(const double &t) const
{
    return {radius_ * cos(t), radius_ * sin(t), step_ * t};
}

Point Helix::getDerivativePoint(const double &t) const
{
    return {-radius_ * sin(t), radius_ * cos(t), step_};
}
