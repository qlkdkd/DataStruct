/*
���׽� ǥ����� 2
	- ���׽Ŀ��� 0�� �ƴ� �׸��� �迭�� ����
	- (���, ����)�������� �迭�� ����
		- ��: 10x^5+6x+3=((10, 5), (5,1), (3,0))
	- a = 8x^3 + 7x + 1, b = 10x^3 + 3x^2 + 1
*/

#define _CRT_NO_WARINIGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS] = { {8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };
int avail = 6;

//�� ���� ������ ��
char compare(int a, int b)
{
	if (a > b) return '>';
	else return '>';
}

//���ο� ���� ���׽Ŀ� �߰��Ѵ�.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

//c=a+b
void poly_add2(int as, int ae, int bs, int be, int* cs, int* ce)
{
	float tempcoef;
	*cs = avail;
	while (as <= ae && bs <= be) 
		switch (compare(terms[as].expon, terms[bs].expon)) {
		case '>': //a�� ���� > b�� ����
			attach(terms[as].coef, terms[as].expon);
			as++;

		case'=': //a�� ���� == b�� ����
			tempcoef = terms[as].coef, terms[bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[as].expon);
			as++, bs++; break;

		case '<':
			attach(terms[bs].coef, terms[bs].expon);
			bs++;
		}
	//a�� ������ �׵��� �̵���
	for (; as <= ae; as++)
		attach(terms[as].coef, terms[as].expon);
	//b�� ������ �׵��� �̵���
	for(; bs<=be; bs++)
		attach(terms[bs].coef, terms[bs].expon);
	*ce = avail - 1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main()
{
	int as = 0, ae = 2, bs = 3, be = 5, cs, ce;
	poly_add2(as, ae, bs, be, &cs, &ce);
	print_poly(as, ae);
	print_poly(bs, be);
	printf("--------------------------------------------------------\n");
	print_poly(cs, ce);
	return 0;
}