#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/bitmap.h"

int main(int argc, char* argv[])
{
	assert(argc == 2);
	printf("Selected file : %s\n", argv[1]);
	FILE* img = fopen(argv[1],"r");
	BITMAP_METADATA* infos = malloc(sizeof(BITMAP_METADATA));
    getBmpInfos(infos,img);
    printBmpInfos(*infos);


    BITMAP32 bmp = initBmp(infos->width,infos->height);
    parseBmp(img,infos->offset, infos->width, infos->height, bmp);

    // Freeing memory
    deleteBmp(bmp,infos->width,infos->height);
    free(infos);
    fclose(img);
	return 0;
}
