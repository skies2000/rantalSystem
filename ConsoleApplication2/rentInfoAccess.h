#pragma once


void AddRentList(char * ISBN, char* cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBM);
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);
void rentInfoSore(FILE* fp);
void rentInfoLoad(FILE* fp);
