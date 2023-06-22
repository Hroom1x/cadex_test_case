#include <cstdlib>
#include <iostream>

#include "curves.hpp"
#include "utility.hpp"


int main() {
    Circle circle(10);
    Point point = circle.getPoint(M_PI);
    Point derivative = circle.getDerivativePoint(M_PI);
    std::cout << point.x << derivative.x << std::endl;

    return EXIT_SUCCESS;
}
