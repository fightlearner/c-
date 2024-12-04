#include <stdio.h>
int my_strlen(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}
int my_strlen1(char a[])
{
	int count = 0;
	for (int i = 0;a[i] != '\0';i++)
	{
		count++;
	}
	return count;
}
int my_strlen2(char* a)
{
	int count = 0;
	if(*a != '\0')
	{
		count = my_strlen2(a + 1) + 1;
	}
	return count;
}
int main()
{
	char a[] = "aasdwdqwdsadsadadsasxsaadweqsfaaswefsadfsadfdscsacasdfasdfxsasaf";
	int num = my_strlen(a);
	int num1 = my_strlen1(a);
	int num2 = my_strlen2(a);
	printf("%d\n", num);
	printf("%d\n", num1);
	printf("%d\n", num2);
	return 0;
}