#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {//��� Ÿ��
    element data;
    struct ListNode* link;
}ListNode;

//���� ó�� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//ù ��� ���� ����
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//
    p->link = head;//(3)
    head = p;//(4)
    return head;//(5)
}

//��� pre�ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));//(1)
    p->data = value;//(2)
    p->link = pre->link;//(3)
    p->link = p;//(4)
    return head;//(5)
}

//ù ��� ����
ListNode* delete_first(ListNode* head) {
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;//(1)
    head = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//pre�� ����Ű�� ����� ���� ��� ����
ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;//(1)
    pre->link = removed->link;//(2)
    free(removed);//(3)
    return head;//(4)
}

//���� ����Ʈ ���
void print_list(ListNode* head) {
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

//����Ʈ�� �������� ����� �Լ�
ListNode* reverse(ListNode* head) {
    //��ȸ �����ͷ� p, q, r�� ���
    ListNode* p, * q, * r;

    p = head;//p�� �������� ���� ����Ʈ
    q = NULL;//q�� �������� ���� ���

    while (p != NULL) {
        r = q;//r�� �������� �� ����Ʈ
        q = p;
        p = p->link;
        q->link = r;//q�� ��ũ ������ �ٲ۴�.
    }
    return q;
}

//�׽�Ʈ ���α׷�
int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    printf("���� ����Ʈ\n");
    print_list(head1);

    head2 = reverse(head1);
    printf("���� ����Ʈ\n");
    print_list(head2);

    return 0;
}