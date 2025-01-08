#include "contact.h"
void menu()
{
	printf("*************通讯录************\n");
	printf("******** 1.增加联系人 **********\n");
	printf("******** 2.删除联系人 **********\n");
	printf("******** 3.查找联系人 **********\n");
	printf("******** 4.修改联系人 **********\n");
	printf("******** 5.按姓名排序 **********\n");
	printf("******** 6.显示通讯录 **********\n");
	printf("******** 7.退出 ****************\n");
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
				SearchContact(&con);
				break;
			case 4:
				ModifyContact(&con);
				break;
			case 5:
				SortContact(&con);
				break;
			case 6:
				ShowContact(&con);
				break;
			case 7:
				DestoryContact(&con);
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
			


	} while (input != 7);
	return 0;
}