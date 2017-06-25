#include "common.h"
#include "dvdInfo.h"
#include "cusInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"
#include "fileManager.h"



void RegistDvd() {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	printf("ISBN 입력: ");
	gets_s(ISBN, ISBN_LEN);
	if (IsRegistISBN(ISBN) != 0) {
		puts("해당 ISBN은 이미 등록되어있습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}


	printf("제목 입력:");
	gets_s(title, TITLE_LEN);
	
	printf("장르 입력 (액션 1. 코믹 2. SF 3. 로맨틱 4):");
	scanf_s("%d", &genre);
	while (getchar() != '\n');


	if (!AddDvdInfo(ISBN, title,genre)) {
		puts("정상적이 등록에 실패 하였습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	if (fileStore() != -1)
		puts("등록이 완료 되었습니다.");
	else
		puts("저장중 오류 발생");
	if (getchar() != '\n')while (getchar() != '\n');
}

void SearchDvdInfo() {
	char ISBN[ISBN_LEN];
	dvdInfo* dvd= NULL;
	printf("찾는 ISBN 입력: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("존재하지 않는 ISBN입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
	}
	else
		ShowDvdInfo(dvd);

}

char* getGenreName(int genre){
	char * genreName = NULL;

	switch (genre) {
	case ACTION:
		genreName = "액션";
		break;
	case COMIC:
		genreName = "코믹";
		break;
	case SF:
		genreName = "SF";
		break;
	case ROMANTIC:
		genreName = "로맨틱";
		break;
	}
	return genreName;
}

void DvdRent() {
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	dvdInfo* dvd = NULL;
	cusInfo* cus = NULL;
	unsigned int date;
	printf("DVD ISBM 입력: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("등록 되지 않은 ISBN입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (dvd->rentState == RENTED) {
		puts("이미 대여중인 DVD 입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	puts("대여가 가능합니다. 대여 과정을 진행 합니다.");
	printf("대여 고객 ID 입력 : ");
	gets_s(ID, ID_LEN);
	cus = GetCusPtrById(ID);
	if (cus == NULL) {
		puts("등록된 ID가 없습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("대여 날짜 입력 :");
	scanf("%u", &date);
	while (getchar() != '\n');
	AddRentList(ISBN, ID, date);
	dvd->rentState = RENTED;
	
	if (fileStore() != -1)
		puts("대여가 완료되었습니다.");
	else
		puts("저장중 오류 발생");

	if (getchar() != '\n')while (getchar() != '\n');
}

void DvdReturn() {
	char ISBN[ISBN_LEN];
	if (DvdRentcheck() == 0) {
		puts("대여된 DVD가 없습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("반납 DVD ISBM 입력: ");
	gets_s(ISBN, ISBN_LEN);
	if (IsRegistISBN(ISBN) == 0) {
		puts("등록되지 않은 ISBN입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	if (DvdReturnInfo(ISBN) == 0)
	{
		puts("반납중 오류가 발생 하였습니다.	");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (fileStore() != -1)
		puts("반납이 완료 되었습니다.");
	else
		puts("저장중 오류 발생");

	if (getchar() != '\n')while (getchar() != '\n');
	return;
}

void RentComstomerSearch() {
	char ISBN[ISBN_LEN];
	dvdInfo * dvd = NULL;
	cusInfo * cus = NULL;
	int rentCnt = 0;
	
	
	printf("찾는 ISBM 입력: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("등록 되지 않은 ISBN입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	PrintOutRentAllCusInfo(ISBN);

	/*rentCnt = dvd->numOfRentCus;
	if (rentCnt < 1) {
		puts("대여된 정보가 없습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	system("cls");
	for (i = 0; i < rentCnt; i++) {
		cus = GetCusPtrById(dvd->rentLst[i].cusID);
		ShowCustomerRentInfo(cus, dvd->rentLst[i].rentDay);

	}
	*/
}


void RegistCustomer() {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phone[PHONE_LEN];

	printf("아이디 입력: ");
	gets_s(ID, ID_LEN);
	if (IsRegistID(ID) != 0) {
		puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해 주세요");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}


	printf("이름 입력:");
	gets_s(name, NAME_LEN);
	printf("전화번호 입력:");
	gets_s(phone, PHONE_LEN);
	if (!AddCusInfo(ID, name, phone)) {
		puts("저상적인 데이터 저장에 실패하였습니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (fileStore() != -1)
		puts("가입이 완료 되었습니다.");
	else
		puts("저장중 오류 발생");

	if (getchar() != '\n')while (getchar() != '\n');
}

void SearchCusInfo() {
	char ID[ID_LEN];
	cusInfo* cus = NULL;
	printf("찾는 ID 입력: ");
	gets_s(ID, ID_LEN);
	cus = GetCusPtrById(ID);
	if (cus == NULL) {
		puts("존재하지 않는 ID입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
	}
	else
		ShowCustomerInfo(cus);

}

void CustomerRentDvdSearch() {

	char ID[ID_LEN];

	unsigned int start, end;
	printf("찾는 ID 입력: ");
	gets_s(ID, ID_LEN);
	if (IsRegistID(ID) == 0) {
		puts("존재하지 않는 ID입니다.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("대여 기간 입력 : ");
	scanf("%u %u", &start, &end);
	while (getchar() != '\n');

	PrintOutCusAllRentInfo(ID, start, end);

}
