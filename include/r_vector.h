#ifndef __RENDER_VECTOR_H
#define __RENDER_VECTOR_H

#include "r_vertex.h"



typedef struct
{
    vertex_t start;
    vertex_t end;
    size_t   len;
} vector_t;



size_t 
R_VectorLength 
( vertex_t vec1,
  vertex_t vec2 );



vector_t 
R_VectorNew 
( uint16_t startvertx, uint16_t startverty, char startvertview,
  uint16_t endvertx,   uint16_t endverty,   char endvertview );



void R_VectorDebug (vector_t vec);



#endif