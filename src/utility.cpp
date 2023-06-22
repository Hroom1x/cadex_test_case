#include "utility.hpp"


std::string formatPointToStr(Point point)
{
    return ("(" + std::to_string(point.x) + "," + std::to_string(point.y) + "," + std::to_string(point.z) + ")");
}

void printCoordsAt(const double& t, const std::list<std::shared_ptr<ICurve>>& curves, std::ostream& output)
{
    std::size_t i = 0;
    std::for_each(curves.begin(), curves.end(), [&i, t, &output](const std::shared_ptr<ICurve>& curve)
    {
        output << ++i << " point: " << formatPointToStr(curve->getPoint(t));
        output << ", derivative: " << formatPointToStr(curve->getDerivativePoint(t)) << std::endl;
    });
}

void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::list<std::shared_ptr<Circle>>& circles)
{
    //
}

double sumRadii(const std::list<std::shared_ptr<ICurve>>& curves)
{
    //
}
