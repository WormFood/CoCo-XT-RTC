// This program was written to unscramble/scramble the OS-9 boot ROM used in
// Burke and Burke CoCo XT RTC card. This is an interface that allows you to
// plug in a regular WD HDD controller. The OS-9 boot ROM, plugged into the
// HDD's BIOS extension socket, allows the CoCo to boot directly from the HDD.
// The process of remapping the PC card to the CoCo inverts address lines
// A4, A5, and A6, which partly scramble the ROM's contents. This program will
// unscramble that ROM, so it can be examined. This is a symetrical process,
// so this will both scramble and unscramble the ROM image.
//
// Copyright (c)2024-2025 by WormFood

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define ROM_SIZE 8192

int main(int argc, char *argv[])
{
	int i;
	unsigned char d, in[ROM_SIZE], out[ROM_SIZE];

	FILE *fp, *wp;

	if (argc != 3){
		printf("Usage: unscramble in_file out_file\n");
		printf("scramble/unscramble Burke and Burke CoCo XT RTC OS-9 Boot ROM\n");
		return EXIT_FAILURE;
	}

//	printf("Opening file for reading %s\n", argv[1]);
	fp = fopen(argv[1], "rb");
	if(!fp){
		printf("ERROR: Can't open file %s for reading\n", argv[1]);
		return EXIT_FAILURE;
	}

//	printf("Opening file for writing %s\n", argv[2]);
// Check if file exists
	struct stat st;
	if (stat(argv[2], &st) == 0) {
	    printf("ERROR: Refusing to overwrite file %s\n", argv[2]);
  	  return EXIT_FAILURE;
	}

	wp = fopen(argv[2], "wb");
	if(!wp){
		printf("ERROR: Can't open file %s for writing\n", argv[2]);
		return EXIT_FAILURE;
	}

//	printf("Reading ROM into memory\n");
	i=fread(in,1,ROM_SIZE,fp);
	if(i != ROM_SIZE)
	{
		printf("ERROR: Problem reading ROM file (%u)\n",i);
		printf("       Wrong file size! Should be %u, but is actually %u\n",ROM_SIZE ,i);
		return EXIT_FAILURE;
	}

//	printf("Attempting to descramble ROM\n");
	for(i=0;i<ROM_SIZE;i++)
		out[i^0x70] = in[i];

	printf("Saving unscrambled file to %s\n", argv[2]);
	i=fwrite(out, 1, ROM_SIZE, wp);
	if(i != ROM_SIZE)
	{ 
		printf("ERROR: problem writing ROM file (%u)\n",i);
		printf("       Should have written %u bytes, but actually wrote %u bytes\n", ROM_SIZE, i);
		fclose(fp);
		return EXIT_FAILURE;
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
