#include <cassert>
#include <iostream>

#include "curves.hpp"
#include "random_filler.hpp"
#include "utility.hpp"


int main() {

    {
        Circle circle(1);
        assert(circle.getRadius() == 1);
        Point point = circle.getPoint(0);
        assert(point.x == 1);
        assert(point.y == 0);
        assert(point.z == 0);
        Point derivative = circle.getDerivativePoint(0);
        assert(derivative.x == 0);
        assert(derivative.y == 1);
        assert(derivative.z == 0);
        assert(circle.getPoint(M_PI*4).x == 1);
    }

    {
        Ellipse ellipse(2, 1);
        Point point = ellipse.getPoint(0);
        assert(std::round(point.x * roundPower) / roundPower == 2);
        assert(std::round(point.y * roundPower) / roundPower == 0);
        assert(std::round(point.z * roundPower) / roundPower == 0);
        point = ellipse.getPoint(M_PI_2);
        assert(std::round(point.x * roundPower) / roundPower == 0);
        assert(std::round(point.y * roundPower) / roundPower == 1);
        assert(std::round(point.z * roundPower) / roundPower == 0);
        Point derivative = ellipse.getDerivativePoint(0);
        assert(std::round(derivative.x * roundPower) / roundPower == 0);
        assert(std::round(derivative.y * roundPower) / roundPower == 1);
        assert(std::round(derivative.z * roundPower) / roundPower == 0);
        derivative = ellipse.getDerivativePoint(M_PI_2);
        assert(std::round(derivative.x * roundPower) / roundPower == -2);
        assert(std::round(derivative.y * roundPower) / roundPower == 0);
        assert(std::round(derivative.z * roundPower) / roundPower == 0);
    }

    {
        Helix helix(1, -2);
        Point point = helix.getPoint(0);
        assert(std::round(point.x * roundPower) / roundPower == 1);
        assert(std::round(point.y * roundPower) / roundPower == 0);
        assert(std::round(point.z * roundPower) / roundPower == 0);
        Point derivative = helix.getDerivativePoint(0);
        assert(std::round(derivative.x * roundPower) / roundPower == 0);
        assert(std::round(derivative.y * roundPower) / roundPower == 1);
        assert(std::round(derivative.z * roundPower) / roundPower == -2);
    }

    {
        std::list<std::shared_ptr<ICurve>> curves;
        populateWithRandom(100, curves);
        std::list<std::shared_ptr<Circle>> circles;
        populateWithCircles(curves, circles);
        circles.sort(isLessCirclePtr);
        std::cout << sumCirclesRadii(circles) << std::endl;
    }

    return EXIT_SUCCESS;
}
