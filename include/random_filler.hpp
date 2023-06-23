#pragma once

#include <random>

#include "curves.hpp"
#include "utility.hpp"


static constexpr int kRandomSeed = 1234567890;
static constexpr double minRadius = 0.01;
static constexpr double maxRadius = 100;
static constexpr double minHelixStep = -50;
static constexpr double maxHelixStep = 50;

enum class CurveType{
    circle = 0,
    ellipse,
    helix,
    number  // Number of curves
};

std::size_t randomUInt(const std::size_t& max = -1);

std::size_t randomUInt(const std::size_t& min, const std::size_t& max);

double randomDouble(const double& min, const double& max);

// Append random curves with random values to the curves list
void populateWithRandom(const int& number, std::list<std::shared_ptr<ICurve>>& curves);
