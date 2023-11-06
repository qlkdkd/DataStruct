#include<stdio.h>
#include<stdlib.h>
#define size 100

int main() {
	int* p = NULL;
	int i = 0;

	p = (int*)malloc(sizeof(int) * size);

	if (p == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	for (i = 0; i < size; i++) {
		p[i] = rand();
	}

	int max = p[0];
	for (i = 0; i < size; i++) {
		if (p[i] > max)
			max = p[i];
	}

	printf("�ִ�: %d\n", max);
	free(p);

	return 0;
}