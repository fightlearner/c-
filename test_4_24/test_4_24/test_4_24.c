#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int input = 0;
    int arr[31][31] = { 0 };
    scanf("%d", &input);
    for (int i = 1;i <= input;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    for (int i = 1;i <= input;i++)
    {
        for (int j = 1;j <= i;j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}