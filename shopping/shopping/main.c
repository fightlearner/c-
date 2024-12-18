#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float price = 0;
	int month = 0;
	int date = 0;
	int coupon = 0;
	scanf("%f %d %d %d", &price, &month, &date, &coupon);
	if (month == 11 && date == 11)
	{
		price = price * 0.7;
		if (coupon == 1)
		{
			price = price - 50;
		}
	}
	else if (month == 12 && date == 12)
	{
		price = price * 0.8;
		if (coupon == 1)
		{
			price = price - 50;
		}
	}
	printf("%.2f", price);
	return 0;
}