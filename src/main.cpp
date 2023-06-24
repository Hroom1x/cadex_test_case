#include <cassert>
#include <iostream>
#include <ctime>

#include "parallel.hpp"


int main() {
    /*
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
        printCoordsAt(taskParameter, curves, std::cout);
        std::cout << sumCirclesRadii(circles) << std::endl;
    }*/

    // Populate a container of objects of curve types created in random manner with
    // random parameters.
    std::list<std::shared_ptr<ICurve>> curves;
    populateWithRandom(10, curves);

    // Print coordinates of points and derivatives of all curves in the container at t=PI/4
    //printCoordsAt(taskParameter, curves, std::cout);

    // Populate a second container that would contain only circles from the first container.
    std::list<std::shared_ptr<Circle>> circles;
    populateWithCircles(curves, circles);

    // Sort the second container in the ascending order of circles’ radii with comparator isLessCirclePtr
    circles.sort(isLessCirclePtr);

    // Compute and print the total sum of radii of all curves in the second container.
    clock_t start = clock();
    std::cout << "The total sum of radii of all curves in the second container: "
    << sumCirclesRadii(circles) << std::endl;
    std::cout << "Parallel: " << sumCirclesRadiiParallel(circles) << std::endl;
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);

    return EXIT_SUCCESS;
}
