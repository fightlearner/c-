#include <stdio.h>

int comp(void* e1, void* e2)
{
	return (*((int*)e2) - *((int*)e1));
}

void sweap(char* a, char* b, int width)
{
	for (int i = 0;i < width;i++)
	{
		char temp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp;
	}
}



void bubble(void* arr, int b, int width, int (*comp)(void* e1, void* e2))
{
	if (b > 1)
	{
		int temp = 0;
		int flag = 1;
		for (int i = 0;i < b - 1;i++)
		{
			if (comp((char*)arr + i * width, (char*)arr + (i + 1) * width))
			{
				sweap((char*)arr + i * width, (char*)arr + (i + 1) * width, width);
				flag = 0;
			}
			/*if (a[i] > a[i + 1])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				flag = 0;
			}*/
		}
		if (flag == 0)
		{
			bubble(arr, b - 1, width, comp);
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz, sizeof(arr[0]), comp);
	for (int i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}