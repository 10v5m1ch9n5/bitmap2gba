#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"

void getBmpInfos(BITMAP_METADATA* meta, FILE* bmp)
{
    fseek(bmp,2,SEEK_SET);
    fread(&meta->size,4,1,bmp);
    fseek(bmp,4,SEEK_CUR);
    fread(&meta->offset,4,1,bmp);
    rewind(bmp);
}
