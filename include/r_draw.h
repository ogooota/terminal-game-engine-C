#ifndef __RENDER_DRAW_H
#define __RENDER_DRAW_H

#include "r_framebuffer.h"
#include "r_vertex.h"
#include "r_vector.h"
#include "r_shape.h"

/** 
 * Here are only the functions for drawing
 * things on a framebuffer_t.
 * All of them are going to be pointed to
 * by the renderer struct. 
 */
void 
R_DrawCharToFramebuffer 
( framebuffer_t* framebuffer, 
  uint16_t       x,
  uint16_t       y,
  char           c );



int
R_DrawStringToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       x,
  uint16_t       y,
  const char*    s );



void 
R_DrawVertexToFramebuffer
( framebuffer_t* framebuffer,
  vertex_t       v );



int 
R_DrawHorizontalVectorToFramebuffer
( framebuffer_t* framebuffer,
  vector_t       vec );



int
R_DrawVerticalVectorToFramebuffer
( framebuffer_t* framebuffer,
  vector_t       vec );



int
R_DrawShapeSquareToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       n );



int R_DrawShapeRectangleToFramebuffer
( framebuffer_t* framebuffer,
  uint16_t       b,
  uint16_t       h );



int
R_DrawShapeToFramebuffer
( framebuffer_t* framebuffer,
  shape_t        shape );



#endif