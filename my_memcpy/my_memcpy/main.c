#include <stdio.h>

void* my_memcpy(void* des, const void* sc, int num)
{
	char* sc1 = (char*)sc;
	char* des1 = (char*)des;
	for (int i = 0;i < num;i++)
	{
		*des1 = *sc1;
		des1++;
		sc1++;
	}
	return des;
}
void* my_memmove(void* des, const void* sc, int num)
{
	if (des > sc)
	{
		char* sc1 = (char*)sc + num - 1;
		char* des1 = (char*)des + num - 1;
		while (sc1 != sc)
		{
			*des1 = *sc1;
			des1--;
			sc1--;
		}
		*des1 = *sc1;
	}
	else
	{
		char* sc1 = (char*)sc;
		char* des1 = (char*)des;
		for (int i = 0;i < num;i++)
		{
			*des1 = *sc1;
			des1++;
			sc1++;
		}
	}
	return des;
}
//int my_memcmp(void* des, const void* sc, int num)
//{
//	int* sc1 = (int*)sc;
//	int* des1 = (int*)des;
//	for (int i = 0;i < num;i++)
//	{
//		if (*des1 > *sc1)
//		{
//			return 1;
//			break;
//		}
//		else if (*des1 <  *sc1)
//		{
//			return -1;
//			break;
//		}
//		des1++;
//		sc1++;
//	}
//	return 0;
//}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };//0-3 4-7 8-11 12-15 16-19
	int arr2[10] = { 1 };
	int* ret = (int*)my_memcpy(arr2, arr1, 28);
	int* ret1 = (int*)my_memmove(arr1, arr1+2, 8);
	//int  ret2 = my_memcmp(arr2, arr1, 1);
	printf("%p\n", ret);
	printf("%p\n", arr2);
	printf("%p\n", ret1 - 2);
	//printf("%d\n", ret2);
	return 0;
}