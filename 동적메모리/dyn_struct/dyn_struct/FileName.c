#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��ȭ�� ����ü�� ǥ��
struct movie {
	char title[100];//��ȭ ����
	double rating;//��ȭ ����
};

int main() {
	struct movie* ptr;
	int i, n;
	printf("��ȭ�� ����: ");
	scanf("%d", &n);
	getchar();//�ٹٲ� ���� ����

	ptr = (struct movie*)malloc(n * sizeof(struct movie));

	if (ptr == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		printf("��ȭ ����: ");
		gets_s(ptr[i].title, 100);//�߰��� ������ �ִ� ���� ���� �� �־�� �Ѵ�.
		printf("��ȭ ����: ");
		scanf("%lf", &ptr[i].rating);
	}

	printf("======================\n");
	for (i = 0; i < n; i++) {
		printf("��ȭ����: %s\n", ptr[i].title);
		printf("��ȭ ����: %lf\n", ptr[i].rating);
	}
	printf("=====================\n");

	free(ptr);
	return 0;
}