#include "r_shape.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>



shape_t R_ShapeNewSquare (uint16_t n)
{
    shape_t sq = {0};
    memset (&sq, 0, sizeof(shape_t));
    sq.shapetype = SHAPETYPE_SQUARE;
    sq.square.n  = n;
    return sq;
}



shape_t 
R_ShapeNewRectangle 
( uint16_t b, 
  uint16_t h )
{
    shape_t rect = {0};
    memset (&rect, 0, sizeof(shape_t));
    rect.shapetype   = SHAPETYPE_RECTANGLE;
    rect.rectangle.b = b;
    rect.rectangle.h = h;
    return rect;
}



shape_t 
R_ShapeNew 
( shapetype_t type, 
  ... )
{
    va_list args;
    va_start (args, type);
    switch (type)
    {
    case SHAPETYPE_SQUARE:
        uint16_t n = (uint16_t) va_arg (args, int);
        va_end (args);
        return R_ShapeNewSquare (n);
    case SHAPETYPE_RECTANGLE:
        uint16_t b = (uint16_t) va_arg (args, int);
        uint16_t h = (uint16_t) va_arg (args, int);
        va_end (args);
        return R_ShapeNewRectangle (b, h);
    }
    va_end (args);
    return (shape_t) {0};
}



void R_ShapeDebugSquare (uint16_t n)
{
    printf ("Square Area: %d\n", n*n);
}



void 
R_ShapeDebugRectangle 
( uint16_t b,
  uint16_t h )
{
    printf ("Rectangle Area: %d\n", b*h);
}



void R_ShapeDebug (shape_t shape)
{
    switch (shape.shapetype)
    {
    case SHAPETYPE_SQUARE:
        R_ShapeDebugSquare (shape.square.n);
        break;
    case SHAPETYPE_RECTANGLE:
        R_ShapeDebugRectangle (shape.rectangle.b, shape.rectangle.h);
        break;
    default:
        break;
    }
}