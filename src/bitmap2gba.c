#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/bitmap.h"

int main(int argc, char* argv[])
{
	assert(argc == 2);
	printf("Selected file : %s\n", argv[1]);
	FILE* img = fopen(argv[1],"r");
	/*
	u8 img_ptr[10];
	fread(img_ptr, 4, 1, img);
	printf("octets lus :\n");
	for(int i = 0; i < 1; ++i)
	{
		printf("%X ",img_ptr[i] );
	}
	printf("\n");
	 */
	BITMAP_METADATA* infos = malloc(sizeof(BITMAP_METADATA));
    getBmpInfos(infos,img);
    printf("taille de l'image : %u\n", infos->size);
    printf("offset : %X\n", infos->offset);

	return 0;
}
