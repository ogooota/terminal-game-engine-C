#include "m_perimeters.h"

#include <math.h>

#define _USE_MATH_DEFINES

double M_PerimeterSquare (shape_t sq)
{
    return (double) (sq.square.n*4);
}


double M_PerimeterRectangle (shape_t rect)
{
    return (double) ((rect.rectangle.b*2)+(rect.rectangle.h*2));
}


double M_PerimeterTriangle (shape_t tri)
{
    return (double) ( G_VectorLength((vector_t) {tri.triangle.v1, tri.triangle.v2})+
                      G_VectorLength((vector_t) {tri.triangle.v1, tri.triangle.v3})+ 
                      G_VectorLength((vector_t) {tri.triangle.v2, tri.triangle.v3}) );
}


double M_PerimeterCircle (shape_t circle)
{
    return (double) (2*M_PI*circle.circle.r);
}