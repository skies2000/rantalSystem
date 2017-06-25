#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"

#define RENT_LEN 100
static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

void AddRentList(char * ISBN, char* cusID, int rentDay) {
	dvdRentInfo dvdr;
	strcpy(dvdr.ISBN, ISBN);
	strcpy(dvdr.cusID, cusID);
	dvdr.rentDay = rentDay;

	rentList[numOfRentCus++] = dvdr;

}

void PrintOutRentAllCusInfo(char * ISBM) {
	int i;
	cusInfo * cus = NULL;
	int shFlag = 0;
	if (numOfRentCus < 1) {
		puts("대여된 정보가 없습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	system("cls");
	for (i = 0; i < numOfRentCus; i++) {
		if (!strcmp(rentList[i].ISBN, ISBM)) {
			cus = GetCusPtrById(rentList[i].cusID);
			ShowCustomerRentInfo(cus, rentList[i].rentDay);
			shFlag++;
		}
	}
	if (shFlag != 0)
		puts("조회를 완료하였습니다.");
	else
		puts("대여 정보가 없습니다.");

	if (getchar() != '\n')while (getchar() != '\n');
	return;
}

void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end) {
	int i;
	dvdInfo * dvd = NULL;
	int shFlag = 0;
	int unsigned temp = 0;
	if (numOfRentCus < 1) {
		puts("대여된 정보가 없습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	for (i = 0; i < numOfRentCus; i++) {
		if (!strcmp(rentList[i].cusID, ID)) {
			dvd = GetDvdPtrByISBN(rentList[i].ISBN);
			temp = rentList[i].rentDay;
			if (temp >= start && temp <= end) {
				ShowDvdRentInfo(&(rentList[i]));
				puts("");
				shFlag++;

			} // end if(temp =>
		} // end if(!strcmp
	} // end for

	if (shFlag != 0)
		puts("조회를 완료하였습니다.");
	else
		puts("대여 정보가 없습니다.");

	if (getchar() != '\n')while (getchar() != '\n');
	return;

}

void rentInfoSore(FILE* fp) {
	int i;
	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	for (i = 0; i < numOfRentCus; i++) {
		fwrite(&(rentList[i]), sizeof(dvdRentInfo), 1, fp);
	}
}

void rentInfoLoad(FILE* fp) {
	int i;

	dvdRentInfo rent;
	fread(&numOfRentCus, sizeof(int), 1, fp);
	for (i = 0; i < numOfRentCus; i++) {
		fread(&rent, sizeof(dvdRentInfo), 1, fp);
		rentList[i] = rent;
	}
}

