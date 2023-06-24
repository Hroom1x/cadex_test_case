#include "random_filler.hpp"


std::size_t randomUInt(const std::size_t& max) {
    static std::mt19937 rand(kRandomSeed);

    std::uniform_int_distribution<std::size_t> dist{0, max};
    return dist(rand);
}

std::size_t randomUInt(const std::size_t& min, const std::size_t& max) {
    return min + randomUInt(max - min);
}

double randomDouble(const double& min, const double& max) {
    static std::mt19937 rand(kRandomSeed);
    std::uniform_real_distribution<double> dis(min, max);
    return dis(rand);
}

void populateWithRandom(const int& number, std::list<std::shared_ptr<ICurve>>& curves)
{
    if (number < 1)
        return;
    CurveType type = CurveType::circle;
    for (int i = 0; i < number; ++i) {
        // Get random curve type
        type = static_cast<CurveType>(randomUInt(std::size_t(CurveType::number) - 1));
        switch (type) {
            case CurveType::circle:
                curves.push_back(std::make_shared<Circle>(randomDouble(minRadius, maxRadius)));
                break;
            case CurveType::ellipse:
                curves.push_back(std::make_shared<Ellipse>(
                        randomDouble(minRadius, maxRadius),
                        randomDouble(minRadius, maxRadius)
                        ));
                break;
            case CurveType::helix:
                curves.push_back(std::make_shared<Helix>(
                        randomDouble(minRadius, maxRadius),
                        randomDouble(minHelixStep, maxHelixStep)
                ));
                break;
            default:
                break;
        }
    }
}
