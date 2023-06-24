#pragma once

#include <algorithm>
#include <memory>
#include <sstream>
#include <list>

#include "curves.hpp"

#define _USE_MATH_DEFINES


static constexpr double taskParameter = M_PI_4;
static constexpr int roundPower = 1000;  // Represents how many digits would be after comma in rounded number

// Comparator for sorting Circle object by radius
bool isLessCirclePtr(const std::shared_ptr<Circle>& l, const std::shared_ptr<Circle>& r);

// Converts Point to convenient string for output
std::string formatPointToStr(Point point);

void printCoordsAt(const double& t, const std::list<std::shared_ptr<ICurve>>& curves, std::ostream& output);

// Gets Circle objects from curves container and puts them into circles container
void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::list<std::shared_ptr<Circle>>& circles);

double sumCirclesRadii(const std::list<std::shared_ptr<Circle>>& circles);
