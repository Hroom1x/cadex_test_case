#include <cstdlib>
#include <iostream>

#include "curves.hpp"
#include "utility.hpp"


int main() {
    Ellipse ellipse(-10, 5);
    Point point = ellipse.getPoint(TASK_PARAMETER);
    Point derivative = ellipse.getDerivativePoint(TASK_PARAMETER);
    std::cout << point.x << derivative.x << formatPointToStr(derivative) << std::endl;

    return EXIT_SUCCESS;
}
