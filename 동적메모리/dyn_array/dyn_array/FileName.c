#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p;
	int i, items;

	printf("�׸� ���� �Է�: ");
	scanf("%d", &items);
	p = (int*)malloc(sizeof(int) * items);

	for (i = 0; i < items; i++) {
		printf("�׸� �Է�: ");
		scanf("%d", &p[i]);
	}

	printf("�Էµ� �׸��\n");
	for (i = 0; i < items; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p);

	return 0;
}