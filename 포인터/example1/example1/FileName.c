#include<stdio.h>
int main() {
	int number = 10;
	int* p;
	p = &number;

	printf("���� number�� �ּ�: %u\n", &number);
	printf("�������� ��: %u\n", p);
	printf("���� number�� ��: %d\n", number);
	printf("�����Ͱ� ����Ű�� ��: %d\n", *p);

	return 0;
}