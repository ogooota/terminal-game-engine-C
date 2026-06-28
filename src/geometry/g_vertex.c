#include "g_vertex.h"

#include <stdio.h>



vertex_t
G_VertexNew
( const double x, 
  const double y )
{
    return (vertex_t)
    {
        .x = x,
        .y = y
    };
}


void G_VertexDebug (vertex_t v)
{
    printf ( "X: %3.3f\n"
             "Y: %3.3f\n", 
             v.x, v.y );
}