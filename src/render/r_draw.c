#include "r_draw.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void 
R_DrawCharToFramebuffer 
( framebuffer_t* framebuffer, 
  uint16_t       x,
  uint16_t       y,
  char           c )
{
    framebuffer->logicbuffer[y][x] = c;
}



int
R_DrawStringToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       x,
  uint16_t       y,
  const char*    s )
{
    uint16_t        i  = x;
    const char*     ch = s;
    while (*ch)
        R_DrawCharToFramebuffer (framebuffer, i++, y, *ch++);
    return (int) i;
}



void
R_DrawVertexToFramebuffer
( framebuffer_t* framebuffer,
  vertex_t       v )
{
    R_DrawCharToFramebuffer (framebuffer, v.x, v.y, v.view);
}



int 
R_DrawHorizontalVectorToFramebuffer
( framebuffer_t* framebuffer,
  vector_t       vec )
{
    uint16_t i    = vec.start.x;
    vertex_t vert = vec.start;
    while (i<vec.end.x)
    {
        R_DrawVertexToFramebuffer (framebuffer, vert);
        vert.x = ++i;
    }
    return (int) i-vec.start.x;
}



int
R_DrawVerticalVectorToFramebuffer
( framebuffer_t* framebuffer,
  vector_t       vec )
{
    uint16_t j    = vec.start.y;
    vertex_t vert = vec.start;
    while (j<vec.end.y)
    {
        R_DrawVertexToFramebuffer (framebuffer, vert);
        vert.y = ++j;
    }
    return (int) j-vec.start.y;
}



int
R_DrawShapeSquareToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       n )
{
    return 0;
}



int R_DrawShapeRectangleToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       b,
  uint16_t       h )
{
    return 0;
}



int
R_DrawShapeToFramebuffer
( framebuffer_t* framebuffer,
  shape_t        shape )
{
    return 0;
}