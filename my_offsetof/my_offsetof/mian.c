#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define my_offsetof(type,m_name)  (int)&(((type *)0)->m_name)


struct S
{
	char a;
	int b;
	char c;
};


int main()
{
	struct S s = { 0 };
	int a = my_offsetof(struct S, c);
	printf("%d", a);
	return 0;
}

