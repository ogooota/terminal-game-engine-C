#ifndef __RENDER_FRAMBUFFER_H
#define __RENDER_FRAMBUFFER_H

#include <stdint.h>

typedef struct 
{
    uint16_t cols;
    uint16_t rows;
    char**   logicbuffer;
    char*    renderbuffer;
} framebuffer_t;



int R_FramebufferInit (framebuffer_t* framebuffer);
void R_FramebufferUpdate (framebuffer_t* framebuffer);
void R_FramebufferDestroy (framebuffer_t* framebuffer);



#endif