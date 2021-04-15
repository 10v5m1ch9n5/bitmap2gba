#include <stdio.h>
#include <assert.h>

typedef unsigned int u32;
typedef unsigned char u8;

int main(int argc, char* argv[])
{
	assert(argc == 2);
	printf("Selected file : %s\n", argv[1]);
	FILE* img = fopen(argv[1],"rb");
	u8 img_ptr[10];
	fread(img_ptr, 4, 1, img);
	printf("octets lus :\n");
	for(int i = 0; i < 1; ++i)
	{
		printf("%X ",img_ptr[i] );
	}
	printf("\n");
	return 0;
}
