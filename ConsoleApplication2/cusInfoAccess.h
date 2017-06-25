#pragma once

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo* GetCusPtrById(char * ID);
int IsRegistID(char * ID);
void cusInfoSore(FILE* fp);
void cusInfoLoad(FILE* fp);