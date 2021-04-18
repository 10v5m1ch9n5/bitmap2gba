#ifndef TYPES_H
#define TYPES_H

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

typedef struct _BITMAP_METADATA
{
    // File infos
    u32 fileSize;
    u32 offset;
    // DIB Header infos
    u32 headerSize;
    u32 width;
    u32 height;
    u16 nbPlanes;
    u16 bitDepth;
    u32 compressionMethod;
    u32 imageSize;
    s32 horizontalResolution;
    s32 verticalResolution;
    u32 paletteSize;
} BITMAP_METADATA;

#endif
