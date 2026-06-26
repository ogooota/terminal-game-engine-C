#include <stdio.h>
#include <unistd.h>

#include "r_shape.h"
#include "r_framebuffer.h"
#include "r_draw.h"
#include "util.h"



int main (void)
{
    framebuffer_t fb = {0};
    R_FramebufferInit (&fb);
    // vertex_t v = R_VertexNew (6, 7, '+');                  @OK
    // R_DrawCharToFramebuffer (&fb, 5, 5, '-');              @OK
    // R_DrawStringToFramebuffer (&fb, 5, 5, "Hello world!"); @OK
    // R_DrawVertexToFramebuffer (&fb, v);                    @OK
    // vector_t hor = R_VectorNew ( 6, 5, '-',
    //                             15, 5, '-' );              @OK
    // vector_t vert = R_VectorNew ( 5, 5, '|',
    //                              5, 15, '|' );             @OK
    // int horsize = R_DrawHorizontalVectorToFramebuffer (&fb, hor);
    // int vertsize = R_DrawVerticalVectorToFramebuffer (&fb, vert);

    R_FramebufferUpdate (&fb);
    while (1)
    {
        write (1, "\x1b[H", 4);
        write (1, fb.renderbuffer, (fb.cols*fb.rows));
    }
    // printf ("horsize: %d\n", horsize);
    // printf ("vertsize: %d\n", vertsize);
    R_FramebufferDestroy (&fb);
    return 0;
}