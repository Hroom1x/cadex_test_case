#pragma once

#include <algorithm>
#include <memory>
#include <sstream>
#include <list>

#include "curves.hpp"

#define _USE_MATH_DEFINES


const double TASK_PARAMETER = M_PI_4;

std::string formatPointToStr(Point point);

void printCoordsAt(const double& t, const std::list<std::shared_ptr<ICurve>>& curves, std::ostream& output);

void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::list<std::shared_ptr<Circle>>& circles);

double sumRadii(const std::list<std::shared_ptr<ICurve>>& curves);
