#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void move(char arr[], int k)
{
	int sz = strlen(arr);
	for (int j = 1;j <= k;j++)
	{
		for (int i = 0;i <= sz - 2;i++)
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
}
int isrotate(char arr1[], char arr2[])
{
	int sz1 = strlen(arr1);
	int sz2 = strlen(arr2);
	if (sz1 != sz2)
	{
		return 0;
	}
	else
	{
		for (int i = 1;i <= sz1;i++)
		{
			move(arr1, 1);
			if (strcmp(arr1, arr2) == 0)
			{
				return 1;
			}
		}
		return 0;
	}
}

//int main()
//{
//	char arr1[] = "ABCDEF";
//	char arr2[] = "ACDEFB";
//	int n = 0;
//	int ret = 0;
//	/*scanf("%d", &n);
//	move(arr1, n);*/
//	printf("%s\n", arr1);
//	ret = isrotate(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}
int highsort(int arr[], int n)
{
    int flag = 1;
    for (int i = 0;i < n - 1;i++)
    {
        if (arr[i] < arr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int lowsort(int arr[], int n)
{
    int flag = 1;
    for (int i = 0;i < n - 1;i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}


int main() {
    int arr[50] = { 0 };
    int n = 0;
    int ret = 0;
    scanf("%d", &n);
    for (int i = 1;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    ret = lowsort(arr, n) + highsort(arr, n);
    if (ret == 1 || ret == 2)
    {
        printf("sorted");
    }
    else
    {
        printf("unsorted");
    }
    return 0;
}