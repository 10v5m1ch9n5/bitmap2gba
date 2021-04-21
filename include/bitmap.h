#include "types.h"
void getBmpInfos(BITMAP_METADATA* meta, FILE* bmp);
void printBmpInfos(BITMAP_METADATA meta);
void parseBmp(FILE* bmp, u32 offset, u32 width, u32 height, COLOR32** img);
extern char * compressionMethod[14];
