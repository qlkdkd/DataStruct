#include<stdio.h>

int main() {
	int a[] = { 10, 20, 30, 40, 50 };
	int* p;

	p = a;
	printf("�迭�� ��: \n");
	for (int i = 0; i < 5; i++) {
		printf("a[%d]=%d ", i, a[i]);
	}
	printf("\n");

	printf("�迭�� �ּ�: \n");
	for (int i = 0; i < 5; i++) {
		printf("p[%d]=%d ", i, p[i]);
	}
	printf("\n");

	return 0;
}