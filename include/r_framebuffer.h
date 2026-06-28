#ifndef __RENDER_FRAMEBUFFER_H
#define __RENDER_FRAMEBUFFER_H

#include <stdint.h>



typedef struct 
{
    uint16_t   width;
    uint16_t   height;
    uint32_t** logicbuffer;
    uint32_t*  renderbuffer;
} framebuffer_t;


void R_FramebufferInit (framebuffer_t* fb);


void R_FramebufferUpdate (framebuffer_t* fb);


void R_FramebufferDestroy (framebuffer_t* fb);



#endif