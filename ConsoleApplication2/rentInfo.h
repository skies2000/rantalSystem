#pragma once
#include "cusInfo.h"
#include "dvdInfo.h"


typedef struct __dvdRentInfo {
	char cusID[ID_LEN];
	char ISBN[ISBN_LEN];
	unsigned int rentDay;

} dvdRentInfo;