#include "g_vector.h"


#include <stdio.h>
#include <math.h>



vector_t 
G_VectorNew 
( const vertex_t v1, 
  const vertex_t v2 )
{
    return (vector_t)
    {
        .start = v1,
        .end   = v2
    };
}


double G_VectorLength (vector_t vec)
{
    return (double) sqrt ( pow ((vec.end.x-vec.start.x), 2) + 
                           pow ((vec.end.y-vec.start.y), 2) );
}


void G_VectorDebug (vector_t vec)
{
    printf ("Vector Start:\n");
    G_VertexDebug (vec.start);
    printf ("Vector End:\n");
    G_VertexDebug (vec.end);
}