#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX(a, b) ((a>b)?a:b)
#define MAX_DEGREE 101//���׽��� �ִ� ���� +1

typedef struct {//����ü �̸��� ������ �����ϴ�.
	int degree;//���׽��� ����
	float coef[MAX_DEGREE];//���׽��� ���
}polynomial;

polynomial a = { 5, {10, 0, 0, 0, 6, 3} };

//c=a+b, ���⼭ a�� b�� ���׽��̴�. ����ü�� ��ȯ�ȴ�.
polynomial poly_add1(polynomial a, polynomial b)
{
	polynomial c;//��� ���׽�
	int apos = 0, bpos = 0, cpos = 0;//�迭 �ε��� ���� 
	int degree_a = a.degree;
	int degree_b = b.degree;
	c.degree = MAX(a.degree, b.degree);//��� ���׽� ����

	while (apos <= a.degree && bpos <= b.degree) {
		if (degree_a > degree_b) {//a��>b��
			c.coef[cpos++] = a.coef[apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			c.coef[cpos++] = b.coef[bpos++];
			degree_a--, degree_b--;
		}
		else {
			c.coef[cpos++] = b.coef[bpos++];
			degree_b--;
		}
	}
	return c;
}

void print_poly(polynomial p)//���׽� ��� �Լ�
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}

int main()
{
	polynomial a = { 5, {3, 6, 0, 0, 0, 10} };
	polynomial b = { 4, {7, 0, 5, 0, 1} };
	polynomial c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	for (int i = 0; i < MAX_DEGREE; i++)
		printf("-");
	printf("\n");
	print_poly(c);
	return 0;
}