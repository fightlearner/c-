#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int n = 0;
	int ret = 0;
	int count = 0;
	scanf("%d", &n);
	while (n)
	{
		if (n % 2 == 0)
		{
			ret = ret + 0 * pow(10, count); //1+0=1
		}
		else
		{
			ret = ret + 1 * pow(10, count);  //1+100=101
		}
		n = n / 10;
		count++;
	}
	printf("%d", ret);
	return 0;
}