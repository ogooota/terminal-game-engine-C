#ifndef __RENDER_VERTEX_H
#define __RENDER_VERTEX_H

#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint16_t x;
    uint16_t y;
    char     view;
} vertex_t;

vertex_t R_VertexNew (const int x, const int y, const char view);
void R_VertexDebug (const vertex_t v);

#endif