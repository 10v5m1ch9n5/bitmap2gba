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
    free(infos);
	return 0;
}
