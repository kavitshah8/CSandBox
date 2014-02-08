#include<stdio.h>
#include<math.h>

void test(int );

int main1()
{
	int a;
	int *ptr=NULL;
	test(&ptr);
	printf("Main : %d\n",ptr);
	return 0;
}

void test(int **ptr)
{
	int a;
	int *ptr_1;
	ptr_1 = &a;
	printf("%d\n",ptr_1);
	*ptr = ptr_1;
}
