#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "blManager.h"
#include "rentInfo.h"


void ShowMenu() {
	system("cls");

	puts("───────────────메뉴───────────────");
	puts("1. 신규 가입");
	puts("2. 고객 검색");
	puts("──────────────────────────────────");
	puts("3. DVD 등록");
	puts("4. DVD 검색");
	puts("──────────────────────────────────");
	puts("5. DVD 대여");
	puts("6. DVD 반납");
	puts("──────────────────────────────────");
	puts("7. DVD 대여고객 전체 조회");
	puts("8. 고객 대여 DVD 전체 조회");
	puts("──────────────────────────────────");
	puts("9. 종료");

	printf("선택 ->");

}

void ShowCustomerInfo(cusInfo * pCus) {
	system("cls");

	  puts("┌────────────────────────");
	printf("│ ▶ ID : %s\n",pCus->ID);
	printf("│ ▶ 이름 : %s\n",pCus->name);
	printf("│ ▶ 전화번호 : %s\n",pCus->phoneNum);
	  puts("└────────────────────────\n");

	if (getchar() != '\n')while (getchar() != '\n');
}

void ShowCustomerRentInfo(cusInfo * pCus, unsigned int date) {
	
	printf("대여일 : %u\n", date);
	  puts("┌────────────────────────");
	printf("│ ▶ ID : %s\n",pCus->ID);
	printf("│ ▶ 이름 : %s\n",pCus->name);
	printf("│ ▶ 전화번호 : %s\n",pCus->phoneNum);
	  puts("└────────────────────────\n");

}

void ShowDvdInfo(dvdInfo* pdvd) {
	system("cls");
	

	  puts("┌────────────────────────");
	printf("│ ▶ ISBN : %s\n", pdvd->ISBM);
	printf("│ ▶ 타이틀 : %s\n", pdvd->title );
	printf("│ ▶ 쟝르 : %s\n", getGenreName(pdvd->genre));
	  puts("└────────────────────────\n");

	if (getchar() != '\n')while (getchar() != '\n');
}

void ShowDvdRentInfo(dvdRentInfo* rent) {
	
	  puts("┌────────────────────────");
	printf("│ ▶ ISBN : %s\n", rent->ISBN);
	printf("│ ▶ 대여일 : %u\n", rent->rentDay);
	  puts("└────────────────────────\n");
 }