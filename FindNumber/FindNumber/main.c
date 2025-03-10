#include <stdio.h>

void Find(int a[], int sz, int* b, int* c)
{
	int ret[2] = { 0 };
	int flag = 0;
	int k = 0;
	for (int j = 0;j < sz;j++)
	{
		flag = 0;

		for (int i = 0;i < sz;i++)
		{
			if (i == j)
			{
				continue;
			}
			if (a[j] == a[i])
			{
				flag = 1;
				continue;
			}
		}
		if (flag == 0)
		{
			ret[k] = a[j];
			k++;
		}
	}
	*b = ret[0];
	*c = ret[1];
}

int main()
{
	int a[10] = { 1,2,3,1,2,3,4,4,5,6 };
	int sz = sizeof(a) / sizeof(a[0]);
	int b = 0;
	int c = 0;
	Find(a, sz, &b, &c);
	printf("%d %d", b, c);
	return 0;
}