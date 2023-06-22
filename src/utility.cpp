#include "utility.hpp"


std::string formatPointToStr(Point point)
{
    return (
            "(" + std::to_string(std::round(point.x * ROUND_POWER) / ROUND_POWER) +
            "," + std::to_string(std::round(point.y * ROUND_POWER) / ROUND_POWER)) +
            "," + std::to_string(std::round(point.z * ROUND_POWER) / ROUND_POWER)) + ")"
            );
}

void printCoordsAt(const double& t, const std::list<std::shared_ptr<ICurve>>& curves, std::ostream& output)
{
    if (curves.empty())
        return;
    output << "(Point), (Derivative)" << std::endl;
    std::for_each(curves.begin(), curves.end(), [t, &output](const std::shared_ptr<ICurve>& curve)
    {
        output << formatPointToStr(curve->getPoint(t));
        output << ", " << formatPointToStr(curve->getDerivativePoint(t)) << std::endl;
    });
}

void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::list<std::shared_ptr<Circle>>& circles)
{
    std::for_each(curves.begin(), curves.end(), [&circles](const auto& curve){
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
            circles.push_back(circle);
    });
}

double sumCirclesRadii(const std::list<std::shared_ptr<Circle>>& circles)
{
    double result = 0;
    std::for_each(circles.begin(), circles.end(), [&result](const std::shared_ptr<Circle>& circle)
    {
        result += circle->getRadius();
    });
    return result;
}
