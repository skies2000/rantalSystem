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

	printf("ISBN �Է�: ");
	gets_s(ISBN, ISBN_LEN);
	if (IsRegistISBN(ISBN) != 0) {
		puts("�ش� ISBN�� �̹� ��ϵǾ��ֽ��ϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}


	printf("���� �Է�:");
	gets_s(title, TITLE_LEN);
	
	printf("�帣 �Է� (�׼� 1. �ڹ� 2. SF 3. �θ�ƽ 4):");
	scanf_s("%d", &genre);
	while (getchar() != '\n');


	if (!AddDvdInfo(ISBN, title,genre)) {
		puts("�������� ��Ͽ� ���� �Ͽ����ϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	if (fileStore() != -1)
		puts("����� �Ϸ� �Ǿ����ϴ�.");
	else
		puts("������ ���� �߻�");
	if (getchar() != '\n')while (getchar() != '\n');
}

void SearchDvdInfo() {
	char ISBN[ISBN_LEN];
	dvdInfo* dvd= NULL;
	printf("ã�� ISBN �Է�: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("�������� �ʴ� ISBN�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
	}
	else
		ShowDvdInfo(dvd);

}

char* getGenreName(int genre){
	char * genreName = NULL;

	switch (genre) {
	case ACTION:
		genreName = "�׼�";
		break;
	case COMIC:
		genreName = "�ڹ�";
		break;
	case SF:
		genreName = "SF";
		break;
	case ROMANTIC:
		genreName = "�θ�ƽ";
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
	printf("DVD ISBM �Է�: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("��� ���� ���� ISBN�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (dvd->rentState == RENTED) {
		puts("�̹� �뿩���� DVD �Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	puts("�뿩�� �����մϴ�. �뿩 ������ ���� �մϴ�.");
	printf("�뿩 �� ID �Է� : ");
	gets_s(ID, ID_LEN);
	cus = GetCusPtrById(ID);
	if (cus == NULL) {
		puts("��ϵ� ID�� �����ϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("�뿩 ��¥ �Է� :");
	scanf("%u", &date);
	while (getchar() != '\n');
	AddRentList(ISBN, ID, date);
	dvd->rentState = RENTED;
	
	if (fileStore() != -1)
		puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	else
		puts("������ ���� �߻�");

	if (getchar() != '\n')while (getchar() != '\n');
}

void DvdReturn() {
	char ISBN[ISBN_LEN];
	if (DvdRentcheck() == 0) {
		puts("�뿩�� DVD�� �����ϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("�ݳ� DVD ISBM �Է�: ");
	gets_s(ISBN, ISBN_LEN);
	if (IsRegistISBN(ISBN) == 0) {
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	if (DvdReturnInfo(ISBN) == 0)
	{
		puts("�ݳ��� ������ �߻� �Ͽ����ϴ�.	");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (fileStore() != -1)
		puts("�ݳ��� �Ϸ� �Ǿ����ϴ�.");
	else
		puts("������ ���� �߻�");

	if (getchar() != '\n')while (getchar() != '\n');
	return;
}

void RentComstomerSearch() {
	char ISBN[ISBN_LEN];
	dvdInfo * dvd = NULL;
	cusInfo * cus = NULL;
	int rentCnt = 0;
	
	
	printf("ã�� ISBM �Է�: ");
	gets_s(ISBN, ISBN_LEN);
	dvd = GetDvdPtrByISBN(ISBN);
	if (dvd == NULL) {
		puts("��� ���� ���� ISBN�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}

	PrintOutRentAllCusInfo(ISBN);

	/*rentCnt = dvd->numOfRentCus;
	if (rentCnt < 1) {
		puts("�뿩�� ������ �����ϴ�.");
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

	printf("���̵� �Է�: ");
	gets_s(ID, ID_LEN);
	if (IsRegistID(ID) != 0) {
		puts("�ش� ID�� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� ������ �ּ���");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}


	printf("�̸� �Է�:");
	gets_s(name, NAME_LEN);
	printf("��ȭ��ȣ �Է�:");
	gets_s(phone, PHONE_LEN);
	if (!AddCusInfo(ID, name, phone)) {
		puts("�������� ������ ���忡 �����Ͽ����ϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	if (fileStore() != -1)
		puts("������ �Ϸ� �Ǿ����ϴ�.");
	else
		puts("������ ���� �߻�");

	if (getchar() != '\n')while (getchar() != '\n');
}

void SearchCusInfo() {
	char ID[ID_LEN];
	cusInfo* cus = NULL;
	printf("ã�� ID �Է�: ");
	gets_s(ID, ID_LEN);
	cus = GetCusPtrById(ID);
	if (cus == NULL) {
		puts("�������� �ʴ� ID�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
	}
	else
		ShowCustomerInfo(cus);

}

void CustomerRentDvdSearch() {

	char ID[ID_LEN];

	unsigned int start, end;
	printf("ã�� ID �Է�: ");
	gets_s(ID, ID_LEN);
	if (IsRegistID(ID) == 0) {
		puts("�������� �ʴ� ID�Դϴ�.");
		if (getchar() != '\n')while (getchar() != '\n');
		return;
	}
	printf("�뿩 �Ⱓ �Է� : ");
	scanf("%u %u", &start, &end);
	while (getchar() != '\n');

	PrintOutCusAllRentInfo(ID, start, end);

}
