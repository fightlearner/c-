#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int StudyCard = 0;
	double cprogram = 0;
	double maths = 0;
	double english = 0;
	scanf("%d;%lf,%lf,%lsf", &StudyCard, &cprogram,&maths,&english);
	cprogram = (int)(cprogram * 100 + 0.5) / 100.0;
	maths = (int)(maths * 100 + 0.5) / 100.0;
	english = (int)(english * 100 + 0.5) / 100.0;
	printf("The each subject score of No. %d is %.2lf, %.2lf, %.2lf.", StudyCard, cprogram, maths,english);
	return 0;
}