#include "contact.h"
void menu()
{
	printf("*************通讯录************\n");
	printf("******** 1.增加联系人 **********\n");
	printf("******** 2.删除联系人 **********\n");
	printf("******** 3.查找联系人 **********\n");
	printf("******** 4.按姓名排序 **********\n");
	printf("******** 5.显示通讯录 **********\n");
	printf("******** 6.退出 ****************\n");
}
int main()
{
	Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请输入>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				AddContact(&con);
				break;
			case 2:
				DeleteContact(&con);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				ShowContact(&con);
				break;
			case 6:
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
			


	} while (input != 6);
	return 0;
}