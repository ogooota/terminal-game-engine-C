#ifndef __GEOMETRY_VERTEX_H
#define __GEOMETRY_VERTEX_H


#include <stdint.h>



typedef struct 
{
    double x;
    double y;
} vertex_t;


vertex_t
G_VertexNew 
( const double x, 
  const double y );


void G_VertexDebug (vertex_t v);



#endif