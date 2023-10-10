#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#define n_students 4

typedef struct student_info {
	char name[10];
	int height;
	float weight;
}element;

typedef struct {
	element* data;//data�� �����ͷ� ����
	int capacity;
	int top;
}StackType;

//���� ���� �Լ�
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return(s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

//���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
		//realloc: �޸� ���Ҵ�. size�� ������ �޸𸮰� Ŀ���� ����
	}
	s->data[++(s->top)] = item;
}

//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int i;
	element e;
	StackType s;
	init_stack(&s);

	for (i = 0; i < n_students; i++) {
		printf("�̸�: ");
		scanf("%s", e.name);
		printf("Ű: ");
		scanf("%d", &e.height);
		printf("������: ");
		scanf("%f", &e.weight);

		push(&s, e);
	}
	for (i = 0; i < n_students; i++) {
		e = pop(&s);
		printf("%s, %d, %f \n", e.name, e.height, e.weight);
	}
	return 0;
}