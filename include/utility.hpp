#pragma once

#include <algorithm>
#include <memory>
#include <sstream>
#include <list>

#include "curves.hpp"

#define _USE_MATH_DEFINES


constexpr double TASK_PARAMETER = M_PI_4;
constexpr int ROUND_POWER = 1000;  // Represents how many digits would be after comma in rounded number

std::string formatPointToStr(Point point);

void printCoordsAt(const double& t, const std::list<std::shared_ptr<ICurve>>& curves, std::ostream& output);

void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::list<std::shared_ptr<Circle>>& circles);

double sumCirclesRadii(const std::list<std::shared_ptr<Circle>>& circles);
