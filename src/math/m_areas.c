#include "m_areas.h"

#include <math.h>

#define _USE_MATH_DEFINES



double M_AreaSquare (shape_t sq)
{
    return (double) (sq.square.n*sq.square.n);
}


double M_AreaRectangle (shape_t rect)
{
    return (double) (rect.rectangle.b*rect.rectangle.h);
}

double M_AreaTriangle (shape_t tri)
{
    double area = ( (tri.triangle.v1.x*(tri.triangle.v2.y - tri.triangle.v3.y)) +
                    (tri.triangle.v2.x*(tri.triangle.v3.y - tri.triangle.v1.y)) +
                    (tri.triangle.v3.x*(tri.triangle.v1.y - tri.triangle.v2.y)) )/2;
    return (double) ((area > 0) ? area : area*-1);
}


double M_AreaCircle (shape_t circle)
{
    return (double) (M_PI*circle.circle.r*circle.circle.r);
}