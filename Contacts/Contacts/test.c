#include "contact.h"
void menu()
{
	printf("*************ͨѶ¼************\n");
	printf("******** 1.������ϵ�� **********\n");
	printf("******** 2.ɾ����ϵ�� **********\n");
	printf("******** 3.������ϵ�� **********\n");
	printf("******** 4.�޸���ϵ�� **********\n");
	printf("******** 5.���������� **********\n");
	printf("******** 6.��ʾͨѶ¼ **********\n");
	printf("******** 7.�˳� ****************\n");
}
int main()
{
	Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("������>");
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
				printf("�����������������\n");
				break;
		}
			


	} while (input != 7);
	return 0;
}