#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main()
{
	student* p;
	p = (student*)malloc(sizeof(student));
	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}
	strcpy(p->name, "Park");
	p->age = 20;
	free(p);
	return 0;
}