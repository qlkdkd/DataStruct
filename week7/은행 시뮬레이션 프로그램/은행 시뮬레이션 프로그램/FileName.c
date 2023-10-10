#include<stdio.h>
#include<stdlib.h>

//����ť �ڵ� ����
#define max_queue_size 5
typedef struct {//��� Ÿ��
	int id;
	int arrival_time;
	int service_time;
}element;
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

//����ť �ڵ� ����



int main() {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

	//����
	srand(time(NULL));

	//���� ������ ������ �ݺ� ����
	for (int clock = 0; clock < minutes; clock++) {
		//�� ����
		if (rand() % 10 < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("��%d��(��) %d�п� ���ɴϴ�. ����ó���ð�: %d��\n",
				customer.id, customer.arrival_time, customer.service_time);
		}

		//�� ����ó��
		if(service_time > 0) {
			printf("�� %d��(��) ����ó�� ���Դϴ�.\n", service_customer);
			service_time--;
		}

		//�� ����
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� %d ��(��) %d�п� ������ �����մϴ�. ���簣�� %d���̿����ϴ�.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ��� �ð�=%d��\n", total_wait);
	return 0;
}