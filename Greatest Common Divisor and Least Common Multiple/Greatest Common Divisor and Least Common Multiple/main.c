#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int CommonDivisor(int a, int b)
{
	int ret = 1;
	for (int i = min(a, b);;i--)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			ret = i;
			return ret;
		}
	}
}

int CommonMultiple(int a, int b)                         
{
	int ret = max(a, b);
	for (int i = max(a, b);;i++)
	{
		if ((i % a == 0) && (i % b == 0))
		{
			ret = i;
			return ret;
		}
	}
}


int main()
{
	int D = 0;
	int M = 0;
	int ret = 0;
	scanf("%d %d", &D, &M);
	//int x = CommonMultiple(D, M);
	printf("%d\n", CommonDivisor(D, M));
	printf("%d\n", CommonMultiple(D, M));
	ret = CommonDivisor(D, M) + CommonMultiple(D, M);
	printf("%d", ret);
	return 0;
}