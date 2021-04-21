#include <stdio.h>
#include "../include/print_functions.h"

void printBmpInfos(BITMAP_METADATA meta)
{
    printf("File size : %u bytes\n", meta.fileSize);
    printf("Image dimensions : %ux%ux%u\n", meta.width, meta.height, meta.bitDepth);
    printf("Compression method : %s\n", compressionMethod[meta.compressionMethod]);
    printf("Raw image size (without file headers) : %u bytes\n", meta.imageSize);
    // printf("Palette of %u colors\n", meta.bitDepth );
}

void printColor(COLOR32 color32)
{
    printf("r=%u ; g=%u ; b=%u ; a=%u\n", color32.r, color32.g, color32.b, color32.a);
}

void printGBAData(FILE * stream, GBA_DATA dat, u32 size)
{
    fprintf(stream, "const unsigned short data[%d] = {\n", size);
    for (int i = 0; i < size; ++i)
    {
        if(i && i % 20 == 0)
            fprintf(stream,"\n");
        if(i == size-1)
            fprintf(stream,"0x%X\n};\n", dat[i]);
        else
            fprintf(stream, "0x%X, ", dat[i]);
    }
}
