#pragma once
#include "cusInfo.h"

#define ISBN_LEN	30
#define TITLE_LEN	30



enum{ACTION=1, COMIC, SF, ROMANTIC};
enum{RENTED, RETURENED};	



typedef struct __dvdInfo {
	char ISBM[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;
} dvdInfo;