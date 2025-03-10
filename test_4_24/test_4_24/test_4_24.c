#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int score[7] = { 0 };
    int input = 0;
    int max = 0;
    int min = 100;
    float mean = 0;
    int i = 0;
    while (scanf("%d", &input) != EOF) {
        score[i] = input;
        if (score[i] >= max) {
            max = score[i];
        }
        if (score[i] <= min) {
            min = score[i];
        }
        mean = mean + score[i];
        i++;
        if (i == 6)
        {
            mean = (mean - max - min) / 5;
            printf("%.2f", mean);
            i = 0;
            mean = 0;
            max = 0;
            min = 100;
        }
    }


    return 0;
}