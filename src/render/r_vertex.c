#include "r_vertex.h"

#include <stdio.h>
#include <string.h>





vertex_t 
R_VertexNew
( const int x, 
  const int y, 
  const char view)
{
    return (vertex_t) 
    {
        .x = x,
        .y = y,
        .view = view
    };
}





void R_VertexDebug (const vertex_t v)
{
    printf ( "\tVertex_x:    %2d\n"
             "\tVertex_t:    %2d\n"
             "\tVertex_view: %2c\n",
             v.x,
             v.y,
             v.view );
}



