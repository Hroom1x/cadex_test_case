#include <iostream>

#include "parallel.hpp"


int main() {
    // Populate a container of objects of curve types created in random manner with
    // random parameters.
    std::list<std::shared_ptr<ICurve>> curves;
    populateWithRandom(1000, curves);

    // Print coordinates of points and derivatives of all curves in the container at t=PI/4
    printCoordsAt(taskParameter, curves, std::cout);

    // Populate a second container that would contain only circles from the first container.
    std::list<std::shared_ptr<Circle>> circles;
    populateWithCircles(curves, circles);

    // Sort the second container in the ascending order of circles’ radii with comparator isLessCirclePtr
    circles.sort(isLessCirclePtr);

    // Compute and print the total sum of radii of all curves in the second container.
    std::cout << "The total sum of radii of all curves in the second container: "
    << sumCirclesRadiiParallel(circles) << std::endl;

    return EXIT_SUCCESS;
}
