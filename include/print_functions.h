#include "types.h"
#include <stdio.h>
void printBmpInfos(BITMAP_METADATA meta);
void printColor(COLOR32 color32);
void printGBAData(FILE * stream, GBA_DATA dat, u32 size);
extern char * compressionMethod[14];
