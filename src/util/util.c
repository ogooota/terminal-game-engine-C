#include "util.h"



#ifdef __unix__
#include <unistd.h>
#include <sys/ioctl.h>


int 
U_GetTermSize
( uint16_t* width,
  uint16_t* height )
{
    struct winsize w;
    if (ioctl (STDIN_FILENO, TIOCGWINSZ, &w) != 0)
    {
        return -1;
    }
    *width = w.ws_row;
    *height = w.ws_row;
    return 0;
}


#endif


#if defined (_WIN32) || defined (WIN32)
#include <windows.h>


int 
U_GetTermSize
( uint16_t* width,
  uint16_t* height )
{
    return 0;
} 


#endif