#pragma once

#include <omp.h>

#include "random_filler.hpp"


double sumCirclesRadiiParallel(const std::list<std::shared_ptr<Circle>>& circles);
