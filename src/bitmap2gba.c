#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/bitmap.h"
#include "../include/print_functions.h"

int main(int argc, char* argv[])
{
	assert(argc == 2);
	printf("Selected file : %s\n", argv[1]);
	FILE* img = fopen(argv[1],"r");
	BITMAP_METADATA* infos = malloc(sizeof(BITMAP_METADATA));
    getBmpInfos(infos,img);
    printBmpInfos(*infos);


    u32 w = infos->width, h = infos->height;
    BITMAP32 bmp = initBmp(w,h);
    parseBmp(img,infos->offset, w, h, bmp);
    GBA_DATA dat = convertToGBA(bmp, w, h);

    FILE * output = fopen("output/title.c","w");
    printGBAData(output, dat,w*h);
    fclose(output);

    // Freeing memory
    deleteBmp(bmp,infos->width,infos->height);
    free(infos);
    fclose(img);
	return 0;
}
