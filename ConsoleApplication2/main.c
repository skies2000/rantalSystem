// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"
#include "blManager.h"
#include "fileManager.h"
enum{CUS_REGIST=1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, DVD_RENT, DVD_RETURN, DVD_RENT_CUSTOMER, CUSTOMER_RENT_DVD, QUIT};

int main()
{
	int inputMenu = 0;
	if (fileLoad() == -1)
	{
		puts("불러오기중 오류가 발생하였습니다.");
		if (getchar() != '\n') while (getchar() != '\n');
	}
	while(1)
	{
		ShowMenu();
		scanf("%d", &inputMenu);
		while (getchar() != '\n');
		switch (inputMenu) {
		case CUS_REGIST:
			RegistCustomer();
			break;
		case CUS_SEARCH:
			SearchCusInfo();
			break;
		case DVD_REGIST:
			RegistDvd();
			break;
		case DVD_SEARCH:
			SearchDvdInfo();
			break;
		case DVD_RENT:
			DvdRent();
			break;
		case DVD_RETURN:
			DvdReturn();
			break;
		case DVD_RENT_CUSTOMER:
			RentComstomerSearch();
			break;
		case CUSTOMER_RENT_DVD:
			CustomerRentDvdSearch();
			break;
		}
			
		if (inputMenu == QUIT) {
			puts("이용해 주셔서 감사합니다.");
			break;
		}
	}
    return 0;
}

