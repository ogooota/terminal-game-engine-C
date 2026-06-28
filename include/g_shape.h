#ifndef __GEOMETRY_SHAPE_H
#define __GEOMETRY_SHAPE_H


#include "g_vector.h"



typedef enum
{
    /* Just some basic types to start */
    GEOMETRY_SHAPETYPE_SQUARE = 0,
    GEOMETRY_SHAPETYPE_RECTANGLE,
    GEOMETRY_SHAPETYPE_TRIANGLE,
    GEOMETRY_SHAPETYPE_CIRCLE,
} shapetype_t;


typedef struct 
{
    shapetype_t type;
    union 
    {
        struct 
        {
            double n;
        } square;

        struct 
        {
            double b;
            double h;
        } rectangle;

        struct 
        {
            vertex_t v1;
            vertex_t v2;
            vertex_t v3;
        } triangle;
        
        struct 
        {
            vertex_t c;
            double r;
        } circle;
    };
} shape_t;


shape_t G_ShapeNewSquare (double n);


shape_t 
G_ShapeNewRectangle 
( double b, 
  double h );


shape_t 
G_ShapeNewTriangle
( vertex_t v1,
  vertex_t v2,
  vertex_t v3 );


shape_t
G_ShapeNewCircle
( vertex_t c,
  double r );

#endif