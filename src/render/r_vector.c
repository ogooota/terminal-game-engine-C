#include "r_vector.h"

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>



size_t 
R_VectorLength 
( vertex_t vec1,
  vertex_t vec2 )
{
    return (size_t) sqrt ( pow ((vec2.x-vec1.x), 2) +
                           pow ((vec2.y-vec1.y), 2) );
}

vector_t 
R_VectorNew 
( uint16_t startvertx, uint16_t startverty, char startvertview,
  uint16_t endvertx,   uint16_t endverty,   char endvertview )
{
    vertex_t start    = R_VertexNew (startvertx, startverty, startvertview);
    vertex_t end      = R_VertexNew (endvertx, endverty, endvertview);
    size_t   distance = R_VectorLength (start, end);
    return (vector_t)
    {
        .start = start,
        .end   = end,
        .len   = distance
    };
}





void R_VectorDebug (vector_t vec)
{
    printf ("Vector_Start: {\n");
    R_VertexDebug (vec.start);
    write (1, "}\n", 2);
    printf ("Vector_End: {\n");
    R_VertexDebug (vec.end);
    write (1, "}\n", 2);
    printf ("Vector_Length: %ld\n", vec.len);
}