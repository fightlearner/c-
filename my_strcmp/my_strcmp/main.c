#include <stdio.h>
#include<string.h>
#include<assert.h>
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while (((*(arr1)) == (*(arr2))) && (*(arr1)) != '\0')
	{
		arr1++;
		arr2++;
	}
	/*for (int i = 0;((*(arr1 + i)) == (*(arr2 + i))) && (*(arr1 + i)) != '\0';i++)
	{
		arr1 + i;
		arr2 + i;
	}*/
	return(*arr1 - *arr2);
}
char* my_strstr(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	const char* s1 = arr1;
	const char* p = arr1;
	const char* s2 = arr2;
	while (*p)
	{
		s1 = p;
		s2 = arr2;
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '/0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;

}
int main()
{
	char arr1[] = "bbbcdf";
	char arr2[] = "abcd";
	int ret = 0;
	char* ret1 = 0;
	ret = my_strcmp(arr1, arr2);
	if (ret > 0)
	{
		printf(">\n");
	}
	else if (ret < 0)
	{
		printf("<\n");
	}
	else
	{
		printf("=\n");
	}
	ret1 = my_strstr(arr1, "cdf");
	printf("%s\n", ret1);
	return 0;
}