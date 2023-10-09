#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����ť �ڵ� ����
#define max_queue_size 5
typedef int element;
typedef struct {//ťŸ��
	element data[max_queue_size];
	int front, rear;
}QueueType;

//�����Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//���� ���� ���� �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�(���� ����: front==rear)
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�(front%M==(rear+1)%M
int is_full(QueueType* q) {
	return((q->rear + 1) % max_queue_size == q->front);
}

//���� ť ��� �Լ�
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d, rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (max_queue_size);
			printf("%d| ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % max_queue_size;
	q->data[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % max_queue_size;
	return q->data[q->front];
}

int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)){
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d\n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}