#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct student_info {
    char name[10];
    int height;
    float weight;
} student_info;    

struct student_info* ptr;//struct student_info_ptr[10];

int main() {
    ptr=(student_info*)malloc(sizeof(student_info) * 4);
    for (int i = 0; i < 4; i++) {
        printf("�̸�: ");
        scanf("%s", ptr[i].name);
        printf("Ű: ");
        scanf("%d", &ptr[i].height);
        printf("������: ");
        scanf("%f", &ptr[i].weight);
    }

    for (int i = 0; i < 4; i++) {
        printf("�̸�: %s, Ű: %d, ������: %f\n", ptr[i].name, ptr[i].height, ptr[i].weight);
    }

    free(ptr);
    return 0;
}