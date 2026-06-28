#ifndef __GEOMETRY_VECTOR_H
#define __GEOMETRY_VECTOR_H

#include "g_vertex.h"



typedef struct
{
    vertex_t start;
    vertex_t end;
} vector_t;


vector_t 
G_VectorNew 
( const vertex_t v1, 
  const vertex_t v2 );


double G_VectorLength (vector_t vec);


void G_VectorDebug (vector_t vec);



#endif