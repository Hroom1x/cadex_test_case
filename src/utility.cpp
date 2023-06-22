#include "utility.hpp"


std::string formatPointToStr(Point point)
{
    return ("(" + std::to_string(point.x) + "," + std::to_string(point.y) + "," + std::to_string(point.z) + ")");
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
    std::copy_if(curves.begin(), curves.end(), std::back_inserter(circles),
                 [](const std::shared_ptr<ICurve>& curve)
   {
        return std::dynamic_pointer_cast<Circle>(curve);
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
