#include "parallel.hpp"


double sumCirclesRadiiParallel(const std::list<std::shared_ptr<Circle>>& circles)
{
    double result = 0;
    auto it = circles.cbegin();
    #pragma omp parallel for default(none) shared(circles, it) reduction(+:result)
    for (std::size_t i = 0; i < circles.size(); ++i)
    {
        result += (*it)->getRadius();
        #pragma omp critical
        {
            ++it;
        }
    }
    return result;
}
