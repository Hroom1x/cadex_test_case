#pragma once

#include <parallel/algorithm>

#include "random_filler.hpp"


double sumCirclesRadiiParallel(const std::list<std::shared_ptr<Circle>>& circles);
