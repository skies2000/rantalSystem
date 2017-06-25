#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "blManager.h"
#include "rentInfo.h"


void ShowMenu() {
	system("cls");

	puts("�������������������������������޴�������������������������������");
	puts("1. �ű� ����");
	puts("2. �� �˻�");
	puts("��������������������������������������������������������������������");
	puts("3. DVD ���");
	puts("4. DVD �˻�");
	puts("��������������������������������������������������������������������");
	puts("5. DVD �뿩");
	puts("6. DVD �ݳ�");
	puts("��������������������������������������������������������������������");
	puts("7. DVD �뿩�� ��ü ��ȸ");
	puts("8. �� �뿩 DVD ��ü ��ȸ");
	puts("��������������������������������������������������������������������");
	puts("9. ����");

	printf("���� ->");

}

void ShowCustomerInfo(cusInfo * pCus) {
	system("cls");

	  puts("��������������������������������������������������");
	printf("�� �� ID : %s\n",pCus->ID);
	printf("�� �� �̸� : %s\n",pCus->name);
	printf("�� �� ��ȭ��ȣ : %s\n",pCus->phoneNum);
	  puts("��������������������������������������������������\n");

	if (getchar() != '\n')while (getchar() != '\n');
}

void ShowCustomerRentInfo(cusInfo * pCus, unsigned int date) {
	
	printf("�뿩�� : %u\n", date);
	  puts("��������������������������������������������������");
	printf("�� �� ID : %s\n",pCus->ID);
	printf("�� �� �̸� : %s\n",pCus->name);
	printf("�� �� ��ȭ��ȣ : %s\n",pCus->phoneNum);
	  puts("��������������������������������������������������\n");

}

void ShowDvdInfo(dvdInfo* pdvd) {
	system("cls");
	

	  puts("��������������������������������������������������");
	printf("�� �� ISBN : %s\n", pdvd->ISBM);
	printf("�� �� Ÿ��Ʋ : %s\n", pdvd->title );
	printf("�� �� ���� : %s\n", getGenreName(pdvd->genre));
	  puts("��������������������������������������������������\n");

	if (getchar() != '\n')while (getchar() != '\n');
}

void ShowDvdRentInfo(dvdRentInfo* rent) {
	
	  puts("��������������������������������������������������");
	printf("�� �� ISBN : %s\n", rent->ISBN);
	printf("�� �� �뿩�� : %u\n", rent->rentDay);
	  puts("��������������������������������������������������\n");
 }