#include "contact.h"
void menu()
{
	printf("*************ͨѶ¼************\n");
	printf("******** 1.������ϵ�� **********\n");
	printf("******** 2.ɾ����ϵ�� **********\n");
	printf("******** 3.������ϵ�� **********\n");
	printf("******** 4.���������� **********\n");
	printf("******** 5.��ʾͨѶ¼ **********\n");
	printf("******** 6.�˳� ****************\n");
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
				break;
			case 4:
				break;
			case 5:
				ShowContact(&con);
				break;
			case 6:
				break;
			default:
				printf("�����������������\n");
				break;
		}
			


	} while (input != 6);
	return 0;
}