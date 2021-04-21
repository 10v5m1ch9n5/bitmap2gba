#include <stdio.h>
#include <stdlib.h>
#include "../include/bitmap.h"

void getBmpInfos(BITMAP_METADATA* meta, FILE* bmp)
{
    // File Header
    fseek(bmp,2,SEEK_SET);
    fread(&meta->fileSize,4,1,bmp);
    fseek(bmp,4,SEEK_CUR);
    fread(&meta->offset,4,1,bmp);
    // DIB Header
    fread(&meta->headerSize,4,1,bmp);
    fread(&meta->width,4,1,bmp);
    fread(&meta->height,4,1,bmp);
    fread(&meta->nbPlanes,2,1,bmp);
    fread(&meta->bitDepth,2,1,bmp);
    fread(&meta->compressionMethod,4,1,bmp);
    fread(&meta->imageSize,4,1,bmp);
    // Not working
    fread(&meta->horizontalResolution,4,1,bmp);
    fread(&meta->verticalResolution,4,1,bmp);
    fread(&meta->paletteSize,4,1,bmp);
    rewind(bmp);
}

void parseBmp(FILE* bmp, u32 offset, u32 width, u32 height, COLOR32** img)
{
    fseek(bmp,offset,SEEK_SET);
    for (int l = 0; l < height; ++l)
    {
        for (int c = 0; c < width; ++c)
        {
            fread(&(img[l][c].b),1,1,bmp);
            fread(&(img[l][c].g),1,1,bmp);
            fread(&(img[l][c].r),1,1,bmp);
            fread(&(img[l][c].a),1,1,bmp);
        }
    }
    rewind(bmp);
}

