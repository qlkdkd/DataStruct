#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//����ü ����
typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main()
{
	srand(time(NULL));

	//1���� �迭 ����
	int list1[6] = { 1,2, 3, 4, 5, 6 };
	for (int i = 0; i < 6; i++) {
		printf("%d ", list1[i]);
	}
	printf("\n\n");


	//2���� �迭 ����
	int list2[3][5];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			list2[i][j] = rand() % 100 + 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", list2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
	
	//����ü ���
	student s = { "�Ŵ���", 22, 3.1 };
	printf("%s, %d, %lf", s.name, s.age, s.gpa);

	return 0;
}