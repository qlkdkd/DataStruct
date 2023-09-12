#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//���丮�� ���α׷���1
int factorial1(int n)
{
	if (n <= 1) return 1;
	else return(n * factorial1(n - 1));
}


//���丮�� ���α׷���2
int factorial2(int n)
{
	if (n <= 1)return(1);
	else return (n * factorial2(n - 1));
}


//���丮���� �ݺ��� ����
int factorial_iter(int n)
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return v;
}


//�ŵ������� ���α׷���(x^n)
double slow_power(double x, int n)
{
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return result;
}

//�ŵ������� ��ȯ
double power_iter(double x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0)
		return power_iter(x * x, n / 2);
	else return x * power_iter(x * x, (n - 1) / 2);
}


//�Ǻ���ġ ������ ���1(��ȿ������ ��)
int fib(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	return (fib(n - 1) + fib(n - 2));
}


//�Ǻ���ġ ������ ���(�ݺ�����)
int fib_iter(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;

	int pp = 0;//������ ������
	int p = 1;//������
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}


int main()
{
	int num, num3;
	double num2;
	printf("����1 �Է�: ");
	scanf("%d", &num);
	printf("���� 2 �Է�: ");
	scanf("%lf", &num2);
	printf("����3 �Է�: ");
	scanf("%d", &num3);

	printf("���丮��1: %d\n", factorial1(num));
	printf("���丮��2: %d\n", factorial2(num));
	printf("���丮��_iter: %d\n", factorial_iter(num));
	printf("%lf�� %d����(slow_power): %lf\n", num2, num3, slow_power(num2, num3));
	printf("%lf�� %d����(power_iter): %lf\n", num2, num3, power_iter(num2, num3));
	printf("%d�� �Ǻ���ġ ����: %d\n", num, fib(num));
	printf("%d�� �Ǻ���ġ ����(�ݺ�����): %d\n", num, fib_iter(num));
	return 0;
}