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
	printf("\n");
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
//����ť �ڵ� ����

int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {//5�� ������ �������� �� �߰�
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);

		if (rand() % 10 == 0) {//10���� ������ �������� �� ����
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}

	return 0;
}
