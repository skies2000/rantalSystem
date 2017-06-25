#include "common.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfoAccess.h"

#define FILE_NAME "C:/upload/DvdRentalSystem.dat"

int fileStore() {
	FILE* fp = fopen(FILE_NAME, "wb");
	if (fp == NULL) return -1;

	cusInfoSore(fp);
	dvdInfoSore(fp);
	rentInfoSore(fp);
	fclose(fp);
	return 1;
}

int fileLoad() {
	FILE* fp = fopen(FILE_NAME, "rb");
	if (fp == NULL) return -1;
	
	cusInfoLoad(fp);
	dvdInfoLoad(fp);
	rentInfoLoad(fp);
	fclose(fp);

	return 1;
}