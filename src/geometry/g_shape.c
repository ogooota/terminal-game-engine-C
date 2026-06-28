#include "g_shape.h"

#include <stdarg.h>
#include <stdio.h>


/* Lookup table for debugging */
const char* shapetypelabels[] = 
{    
    "GEOMETRY_SHAPETYPE_SQUARE",
    "GEOMETRY_SHAPETYPE_RECTANGLE", 
    "GEOMETRY_SHAPETYPE_TRIANGLE",
    "GEOMTRY_SHAPETYPE_CIRCLE",
};


shape_t G_ShapeNewSquare (double n)
{
    return (shape_t)
    {
        .type   = GEOMETRY_SHAPETYPE_SQUARE,
        .square = {n}
    };
}


shape_t 
G_ShapeNewRectangle 
( double b, 
  double h )
{
    return (shape_t)
    {
        .type      = GEOMETRY_SHAPETYPE_RECTANGLE,
        .rectangle = {b, h}
    };
}


shape_t 
G_ShapeNewTriangle
( vertex_t v1,
  vertex_t v2,
  vertex_t v3 )
{
    return (shape_t)
    {
        .type     = GEOMETRY_SHAPETYPE_TRIANGLE,
        .triangle = {v1, v2, v3}
    };
}


shape_t
G_ShapeNewCircle
( vertex_t c,
  double   r )
{
    return (shape_t)
    {
        .type   = GEOMETRY_SHAPETYPE_CIRCLE,
        .circle = {c, r}
    };
}


/* @TODO */
void G_ShapeDebugSquare (shape_t sq);


/* @TODO */
void G_ShapeDebugRectangle (shape_t rect);


/* @TODO */
void G_ShapeDebugTriangle (shape_t tri);


/* @TODO */
void G_ShapeDebugCircle (shape_t circle);