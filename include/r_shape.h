#ifndef __RENDER_SHAPE_H
#define __RENDER_SHAPE_H



#include "r_vertex.h"



typedef enum 
{
    SHAPETYPE_SQUARE,
    SHAPETYPE_RECTANGLE,
} shapetype_t;



typedef struct 
{
    shapetype_t shapetype;
    union 
    {
        struct 
        {
            uint16_t n;
        } square;

        struct 
        {
            uint16_t b;
            uint16_t h;
        } rectangle;
    };
} shape_t;



shape_t R_ShapeNewSquare (uint16_t n);



shape_t 
R_ShapeNewRectangle 
( uint16_t b, 
  uint16_t h );



shape_t 
R_ShapeNew 
( shapetype_t type,
  ... );

/**
 * Debugging functions 
 */
void R_ShapeDebugSquare (uint16_t n);



void 
R_ShapeDebugRectangle 
( uint16_t b,
  uint16_t h );



void R_ShapeDebug (shape_t shape);



#endif