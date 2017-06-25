#pragma once
#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

void ShowMenu();
void ShowCustomerInfo(cusInfo * pCus);
void ShowDvdInfo(dvdInfo* pdvd);
void ShowCustomerRentInfo(cusInfo * pCus, unsigned int date);
void ShowDvdRentInfo(dvdRentInfo* rent);