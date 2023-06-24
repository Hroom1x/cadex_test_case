#include "parallel.hpp"


double sumCirclesRadiiParallel(const std::list<std::shared_ptr<Circle>>& circles)
{
    double result = 0;
    __gnu_parallel::for_each(circles.begin(), circles.end(), [&result](const std::shared_ptr<Circle>& circle)
    {
        result += circle->getRadius();
    });
    return result;
}
