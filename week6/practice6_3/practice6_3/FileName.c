#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat(char* result, const char* str1, const char* str2) {
    strcpy(result, str1); // ù ��° ���ڿ� ����
    strcat(result, str2); // �� ��° ���ڿ� �߰�
}

int main() {
    char str1[10] = "hello";
    char str2[10] = "world!!!";
    char* p;

    p = (char*)malloc(sizeof(char) * 20);
    if (p == NULL) {
        fprintf(stderr, "malloc fail!!!\n");
        exit(1);
    }

    concat(p, str1, str2);

    printf("%s\n", p);

    free(p); // �������� �Ҵ��� �޸� ����

    return 0;
}
