#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMMER  100

static cusInfo * cusList[MAX_CUSTOMMER];
static int numOfCustomer = 0;

int AddCusInfo(char * ID, char * name, char * num) {
	cusInfo* cus = NULL;
	
	if (numOfCustomer >= MAX_CUSTOMMER)
		return 0;

	cus = (cusInfo*)malloc(sizeof(cusInfo));
	strcpy(cus->ID, ID);
	strcpy(cus->name, name);
	strcpy(cus->phoneNum, num);

	cusList[numOfCustomer++] = cus;
	return numOfCustomer;
	
}

cusInfo* GetCusPtrById(char * ID) {

	int i;
	for (i = 0; i < numOfCustomer; i++) {
		if (!strcmp(cusList[i]->ID, ID))
			return cusList[i];
	}
	return NULL;

}

int IsRegistID(char * ID) {
	
	if (GetCusPtrById(ID) == NULL)
		return 0;
	return 1;

}

void cusInfoSore(FILE* fp) {
	int i;
	fwrite(&numOfCustomer,sizeof(int),1,fp);
	for (i = 0; i < numOfCustomer; i++) {
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);
	}
}

void cusInfoLoad(FILE* fp) {
	int i;

	cusInfo * cus = NULL;
	fread(&numOfCustomer, sizeof(int), 1, fp);
	for (i = 0; i < numOfCustomer; i++) {
		cus = (cusInfo*)malloc(sizeof(cusInfo));
		fread(cus, sizeof(cusInfo), 1, fp);
		cusList[i] = cus;
	}
}