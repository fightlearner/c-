#include <stdio.h>

void bubble(int a[], int b)
{
	if (b > 1)
	{
		int temp = 0;
		int flag = 1;
		for (int i = 0;i < b - 1;i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				flag = 0;
			}
		}
		if (flag == 0)
		{
			bubble(a, b - 1);
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,6,7567,2,4,3,24,56,7,8};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz);
	for (int i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}