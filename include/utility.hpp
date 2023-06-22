#pragma once

#include <memory>
#include <sstream>
#include <vector>

#include "curves.hpp"

#define _USE_MATH_DEFINES


const double TASK_PARAMETER = M_PI_4;

std::string formatPointToStr(Point point);

void printCoordsAt(const double& t, const std::vector<ICurve>& curves, std::ostream& output);

void populateWithCircles(const std::vector<std::shared_ptr<ICurve>>& curves, std::vector<Circle>& circles);

double sumRadii(const std::vector<ICurve>& curves);
