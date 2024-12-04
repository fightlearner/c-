#include <stdio.h>
#include <assert.h>
char* my_strcpy(char* arr2, char* arr1)
{
	assert(arr2);
	assert(arr1);
	char* ret = arr2;
	while (*arr1 != '\0')
	{
		*arr2 = *arr1;
		arr1++;
		arr2++;
	}
	*arr2 = *arr1;
	return ret;
}

char* my_strcat(char* arr1, char* arr2)
{
	assert(arr2);
	assert(arr1);
	char* ret = arr1;
	while (*arr1 != '\0')
	{
		arr1++;
	}
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = *arr2;
	return ret;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	char arr3[20] = "hello ";
	my_strcpy(arr2, arr1);
	my_strcat(arr3, arr3);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
	return 0;
}