#include "r_framebuffer.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int R_FramebufferInit (framebuffer_t* framebuffer)
{
    uint16_t cols = 0;
    uint16_t rows = 0;
    memset (framebuffer, 0, sizeof(framebuffer_t));
    if (U_GetTermSize (&cols, &rows) < 0)
    {
    /**
     * @TODO:
     * Make a decent error handling system.
     */
    printf ("R_FramebufferInit: Could not get terminal size\n");
    return -1;
    }
    framebuffer->cols = cols;
    framebuffer->rows = rows;
    framebuffer->logicbuffer = malloc (sizeof(char*)*rows);
    if (!framebuffer->logicbuffer)
    {
    printf ("R_FramebufferInit: Could not malloc logicbuffer rows\n");
    return -1;
    }
    for (uint16_t i=0 ; i<rows ; i++)
    {
        framebuffer->logicbuffer[i] = malloc ((sizeof(char)*cols)+1);
        if (!framebuffer->logicbuffer[i])
        {
        printf ("R_FramebufferInit: Could not malloc logicbuffer cols\n");
        free (framebuffer->logicbuffer);
        return -1;    
        }
        memset (framebuffer->logicbuffer[i], ' ', (cols+1));
    }
    framebuffer->renderbuffer = malloc ((sizeof(char)*(cols*rows))+1);
    if (!framebuffer->renderbuffer)
    {
    for (uint16_t i=0 ; i<rows ; i++)
        free (framebuffer->logicbuffer[i]);
    free (framebuffer->logicbuffer);
    printf ("R_FramebufferInit: Could not malloc renderbuffer\n");
    return -1;
    }
    memset (framebuffer->renderbuffer, ' ', (cols*rows));
    return 0;
}



void R_FramebufferUpdate (framebuffer_t* framebuffer)
{
    for (uint16_t i=0 ; i<framebuffer->rows ; i++)
        for (uint16_t j=0 ; j<framebuffer->cols ; j++)
            framebuffer->renderbuffer
            [(i*framebuffer->cols)+j] 
            = 
            framebuffer->logicbuffer
            [i][j];
}



void R_FramebufferDestroy (framebuffer_t* framebuffer)
{
    for (uint16_t i=0 ; i<framebuffer->rows ; i++)
        free (framebuffer->logicbuffer[i]);
    free (framebuffer->logicbuffer);
    free (framebuffer->renderbuffer);
}