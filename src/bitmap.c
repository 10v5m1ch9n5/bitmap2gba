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

void printBmpInfos(BITMAP_METADATA meta)
{
    printf("File size : %u bytes\n", meta.fileSize);
    printf("Image dimensions : %ux%ux%u\n", meta.width, meta.height, meta.bitDepth);
    printf("Compression method : %s\n", compressionMethod[meta.compressionMethod]);
    printf("Raw image size (without file headers) : %u bytes\n", meta.imageSize);
    // printf("Palette of %u colors\n", meta.bitDepth );
}

char * compressionMethod[14] = {
        "None",
        "RLE 8-bit/pixel",
        "RLE 4-bit/pixel",
        "Huffman 1D",
        "RLE-24",
        "BI_PNG",
        "RGBA bit field masks",
        "","","","",
        "None",
        "RLE-8",
        "RLE-4"
};
