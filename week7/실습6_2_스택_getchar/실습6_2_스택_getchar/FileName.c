#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<malloc.h>

typedef char element;
typedef struct {
	element* data;//data�� ������
	int capacity;
	int top;
}StackType;

//���� ���� �Լ�
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = -1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

//�����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity * 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {
	int i, j;
	element e;
	StackType s;
	init_stack(&s);

	for (i = 0; ; i++) {
		e = getchar();
		if (e == '\n') break;
		push(&s, e);
	}
	printf("-----------------\n");
	for (j = 0; j < i; j++) {
		e = pop(&s);
		putchar(e);
	}
	return 0;
}