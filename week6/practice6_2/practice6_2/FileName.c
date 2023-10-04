#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int add(int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int* num;
	num = (int*)malloc(sizeof(int) * 10);

	if (num == (int*)NULL) {
		fprintf(stderr, "malloc fail!\n");
		exit(1);
	}

	//1���� 100������ ������ ���� �Ҵ�
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 100 + 1;
	}

	//�迭�� ���� ���
	printf("�迭 ��: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	//add�Լ� ȣ���Ͽ� �迭�� �� ���ϱ�
	int result = add(num, 10);

	printf("�迭�� ��: %d\n", result);

	free(num);
	return 0;
}