#include <stdio.h>

#include "g_vector.h"
#include "g_shape.h"
#include "m_areas.h"
#include "m_perimeters.h"

void MAIN_ShapeTests ()
{
    shape_t sq     = G_ShapeNewSquare (5);
    shape_t rect   = G_ShapeNewRectangle (5., 10.);
    shape_t tri    = G_ShapeNewTriangle ((vertex_t) {5., 5.}, (vertex_t) {5., 10.}, (vertex_t) {10., 7.});
    shape_t circle = G_ShapeNewCircle ((vertex_t) {0., 0.}, 3.);

    printf ("Square Area: %.2f\n", M_AreaSquare (sq));
    printf ("Rectangle Area: %.2f\n", M_AreaRectangle(rect));
    printf ("Triangle Area: %.2f\n", M_AreaTriangle (tri));
    printf ("Circle Area: %.2f\n", M_AreaCircle (circle));
    printf ("\n"); 
    printf ("Square Perimeter: %.2f\n", M_PerimeterSquare (sq));
    printf ("Rectangle Perimeter: %.2f\n", M_PerimeterRectangle(rect));
    printf ("Triangle Perimeter: %.2f\n", M_PerimeterTriangle (tri));
    printf ("Circle Perimeter: %.2f\n", M_PerimeterCircle (circle));
}

int main (void)
{
    MAIN_ShapeTests ();
    return 0;
}