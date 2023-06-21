#pragma once

#include <sstream>
#include <vector>

#include "curves.hpp"

#define _USE_MATH_DEFINES


const double TASK_PARAMETER = M_PI_4;

void printCoordsAt(double t, std::vector<ICurve> curves, std::ostream output);

void populateWithCircles(std::vector<ICurve> curves, std::vector<Circle> circles);
