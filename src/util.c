#include "util.h"

#ifdef __unix__
#include <sys/ioctl.h>

int 
U_GetTermSize 
( uint16_t* cols, 
  uint16_t* rows )
{
    struct winsize w;
    if (ioctl (0, TIOCGWINSZ, &w) != 0)
    {
    return -1;
    }
    *cols = (uint16_t)w.ws_col;
    *rows = (uint16_t)w.ws_row;
    return 0;
}

#elif defined (_WIN32) || defined (WIN32)
#include <windows.h>

int 
U_GetTermSize 
( uint16_t* cols, 
  uint16_t* rows )
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &csbi);
    *cols = (uint16_t) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    *rows = (uint16_t) (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    return 0;
}

#endif