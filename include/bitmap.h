#include "types.h"
void getBmpInfos(BITMAP_METADATA* meta, FILE* bmp);
void printBmpInfos(BITMAP_METADATA meta);
void parseBmp(FILE* bmp, u32 offset, u32 width, u32 height, BITMAP32 img);
BITMAP32 initBmp(u32 width, u32 height);
void deleteBmp(BITMAP32 bmp, u32 width, u32 height);
extern char * compressionMethod[14];
