#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo* dvdList[MAX_DVD];
static int numOfDvd = 0;


int AddDvdInfo(char * ISBN, char * title, int genre) {
	dvdInfo* dvd = NULL;

	if (numOfDvd >= MAX_DVD)
		return 0;

	dvd = (dvdInfo*)malloc(sizeof(dvdInfo));
	strcpy(dvd->ISBM,ISBN);
	strcpy(dvd->title, title);
	dvd->genre = genre;
	dvd->rentState = RETURENED;
	
	

	dvdList[numOfDvd++] = dvd;
	return numOfDvd;

}

dvdInfo* GetDvdPtrByISBN(char * ISBN) {

	int i;
	for (i = 0; i < numOfDvd; i++) {
		if (!strcmp(dvdList[i]->ISBM, ISBN))
			return dvdList[i];
	}
	return NULL;

}

int IsRegistISBN(char * ISBN) {

	if (GetDvdPtrByISBN(ISBN) == NULL)
		return 0;
	return 1;

}
/*
int AddDvdRentInfo(dvdInfo* dvd, dvdInfo* cus, unsigned int date) {
	
	int i = dvd->numOfRentCus;
	if (i >= RENT_LEN) {
		return 0;
	}
	dvd->rentState = RENTED;

	strcpy(dvd->rentLst[i].cusID, cus->ID);
	dvd->rentLst[i].rentDay = date;
	dvd->numOfRentCus++;
	return 1;
}
*/
int DvdRentcheck() {
	int i;
	for (i = 0; i < numOfDvd; i++) {
		if (dvdList[i]->rentState == RENTED) {
			return 1;
		}
	}
	return 0;

}

int DvdReturnInfo(char* ISBN) {
	dvdInfo* dvd = NULL;
	dvd = GetDvdPtrByISBN(ISBN);

	if (dvd == NULL)
		return 0;
	dvd->rentState = RETURENED;
	return 1;
}

void dvdInfoSore(FILE* fp) {
	int i;
	fwrite(&numOfDvd, sizeof(int), 1, fp);
	for (i = 0; i < numOfDvd; i++) {
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
	}
}

void dvdInfoLoad(FILE* fp) {
	int i;

	dvdInfo * dvd = NULL;
	fread(&numOfDvd, sizeof(int), 1, fp);
	for (i = 0; i < numOfDvd; i++) {
		dvd = (dvdInfo*)malloc(sizeof(dvdInfo));
		fread(dvd, sizeof(dvdInfo), 1, fp);
		dvdList[i] = dvd;
	}
}

