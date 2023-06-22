#include "utility.hpp"


std::string formatPointToStr(Point point) {
    return ("(" + std::to_string(point.x) + "," + std::to_string(point.y) + "," + std::to_string(point.z) + ")");
}

void printCoordsAt(const double& t, const std::list<ICurve>& curves, std::ostream& output) {
    for (std::size_t i = 0; i < curves.size(); ++i) {
        output << i + 1 << " point: " << formatPointToStr(curves[i].getPoint(t));
        output << ", derivative: " << formatPointToStr(curves[i].getDerivativePoint(t)) << std::endl;
    }
}

void populateWithCircles(const std::list<std::shared_ptr<ICurve>>& curves, std::vector<Circle>& circles) {
    //
}

double sumRadii(const std::list<ICurve>& curves) {
    //
}
