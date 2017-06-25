#pragma once
#include "dvdInfo.h"

int AddDvdInfo(char * ISBN, char * title, int genre);
dvdInfo* GetDvdPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);
//int AddDvdRentInfo(dvdInfo* dvd, cusInfo* cus, unsigned int date);
int DvdRentcheck();
int DvdReturnInfo(char* ISBN);
void dvdInfoSore(FILE* fp);
void dvdInfoLoad(FILE* fp);
