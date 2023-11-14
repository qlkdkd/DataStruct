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

ListNode* contact_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL)return head2;
    else if (head2 == NULL)return head2;
    else {
        ListNode* p;
        p = head1;
        while (p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}
int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    //head1�� �� ����
    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    //head2�� �� ����
    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);
    
    //�� ��� ��ġ��
    ListNode* total = contact_list(head1, head2);
    print_list(total);

    return 0;
}